#include "Detector.h"
#include "common.h"
#include "EventReceiver.h"
#include "DetectorManager.h"
#include <string>

CDetectorManager *CDetector::m_pDetMgr = NULL;
const int CDetector::OFFSETMASK = Enm_CorrectOp_SW_PreOffset | Enm_CorrectOp_SW_PostOffset | Enm_CorrectOp_HW_PreOffset | Enm_CorrectOp_HW_PostOffset;
const int CDetector::GAINMASK = Enm_CorrectOp_SW_Gain | Enm_CorrectOp_HW_Gain;
const int CDetector::DEFECTMASK = Enm_CorrectOp_SW_Defect | Enm_CorrectOp_HW_Defect;

CDetector *CDetector::CreateDetector(const char *pszWorkDir)
{
	if (NULL == m_pDetMgr)
	{
		m_pDetMgr = new CDetectorManager();
	}
	return m_pDetMgr->Create(pszWorkDir);
}

void CDetector::DestoryDetector(int id)
{
	if (NULL != m_pDetMgr)
	{
		m_pDetMgr->Destory(id);
	}
}

CDetector::CDetector()
	: m_nDetectorID(0), m_bInitilized(false),
	  m_fpCreate(NULL),
	  m_fpDestroy(NULL),
	  m_fpGetAttr(NULL),
	  m_fpInvoke(NULL),
	  m_fpSetAttr(NULL),
	  m_hModule(NULL),
	  m_pFnGetErrorInfo(NULL),
	ready(std::promise<void>())
{
}

CDetector::~CDetector()
{
	Destory();
	Deinit();
}

bool CDetector::Init()
{
	m_hModule = LoadLibraryA("FpdSys.dll");
	if (NULL == m_hModule)
	{
		print("Load Dll failed!\n");
		//MessageBoxW(NULL, _T("Load Dll failed!"));

		auto err = GetLastError();
		return false;
	}
	m_fpCreate = (FnCreate)GetProcAddress(m_hModule, IRAY_FPD_PROC_NAME_CREATE);
	if (NULL == m_fpCreate)
	{
		print("GetProcAddress:Create failed!\n");
		return false;
	}
	m_fpDestroy = (FnDestroy)GetProcAddress(m_hModule, IRAY_FPD_PROC_NAME_DESTROY);
	if (NULL == m_fpDestroy)
	{
		print("GetProcAddress:Destroy failed!\n");
		return false;
	}
	m_fpGetAttr = (FnGetAttr)GetProcAddress(m_hModule, IRAY_FPD_PROC_NAME_GETATTR);
	if (NULL == m_fpGetAttr)
	{
		print("GetProcAddress:GetAttr failed!\n");
		return false;
	}
	m_fpSetAttr = (FnSetAttr)GetProcAddress(m_hModule, IRAY_FPD_PROC_NAME_SETATTR);
	if (NULL == m_fpSetAttr)
	{
		print("GetProcAddress:etAttr failed!\n");
		return false;
	}
	m_fpInvoke = (FnInvoke)GetProcAddress(m_hModule, IRAY_FPD_PROC_NAME_INVOKE);
	if (NULL == m_fpInvoke)
	{
		print("GetProcAddress:Invoke failed!\n");
		return false;
	}

	m_pFnGetErrorInfo = (FnGetErrInfo)GetProcAddress(m_hModule, IRAY_FPD_PROC_NAME_GET_ERROR_INFO);
	if (NULL == m_pFnGetErrorInfo)
	{
		print(" GetProcAddress:GetErrInfo Failed!");
		return false;
	}
	m_bInitilized = true;
	return true;
}

void CDetector::Deinit()
{
	if (m_hModule)
	{
		FreeLibrary(m_hModule);
		m_hModule = NULL;
	}
}

FPDRESULT CDetector::Create(const char *pszWorkDir, FnCallback fpCallback)
{
	if (!m_bInitilized)
	{
		if (!Init())
		{
			return Err_NotInitialized;
		}
	}

	FPDRESULT nRet = m_fpCreate(pszWorkDir, fpCallback, &m_nDetectorID);
	if (Err_OK != nRet)
	{
		print("Create failed\n, errorCode: %d\n", nRet);
		return nRet;
	}

	return nRet;
}

FPDRESULT CDetector::Connect()
{
	FPDRESULT nRet = Invoke(Cmd_Connect);
	if (Err_TaskPending == nRet)
	{
		print("Connect...\n");
	}
	else
	{
		print("Connect failed, errorCode: %d\n", nRet);
	}
	return nRet;
}

FPDRESULT CDetector::ConnectSync(int ms) {
	auto nRet = this->Connect();
	if (Err_OK == nRet) {
		return Err_OK;
	} else if(Err_TaskPending != nRet) {
		print("Connect failed, errorCode: %d\n", nRet);
		return nRet;
		// throw std::runtime_error("Connect failed, errorCode: " + nRet);
	}
	auto fur = this->ready.get_future();
	std::chrono::milliseconds timeout(ms);
	if (fur.wait_for(timeout) == std::future_status::timeout) {
		print("Connect timeou.\n");
		// throw std::runtime_error("连接采集设备超时(Connect timeout).");
		return Err_TaskTimeOut;
	}
	return Err_OK;
}

FPDRESULT CDetector::CreateAndConnect(const char *pszWorkDir, FnCallback fpCallback)
{
	FPDRESULT ret = Create(pszWorkDir, fpCallback);
	if (Err_OK != ret)
	{
		return ret;
	}

	return Connect();
}

FPDRESULT CDetector::Destory()
{
	if (m_nDetectorID > 0)
	{
		m_fpDestroy(m_nDetectorID);
		m_nDetectorID = 0;
	}
	return Err_OK;
}

FPDRESULT CDetector::Disconnect()
{
	FPDRESULT nRet = Invoke(Cmd_Disconnect);
	if (Err_TaskPending == nRet)
	{
		print("DisConnect...\n");
	}
	else
	{
		print("DisConnect failed, errorCode: %d\n", nRet);
	}
	return Err_OK;
}

FPDRESULT CDetector::SingleAcquire()
{
	return Invoke(Cmd_ForceSingleAcq);
}

FPDRESULT CDetector::PrepAcquire()
{
	return Invoke(Cmd_ClearAcq);
}

FPDRESULT CDetector::StartAcquire()
{
	this->prepare = std::promise<void>();
	this->image = std::promise<IRayImage*>();
	return Invoke(Cmd_StartAcq);
}

FPDRESULT CDetector::StartAcquireSync(int ms) {
	int t = 10;
	AttrResult var;
	while (t > 0) {
		this->GetAttr(Attr_State, var);
		if (var.nVal != Enm_State_Ready) {
			printf("Not ready (%d), Retry.\n", var.nVal);
			Sleep(100);
			if (t == 0) {
				return Err_StateErr;
			}
			t--;
		}
		else {
			break;
		}
	}
	
	auto nRet = this->StartAcquire();
	if (Err_OK == nRet) {
		return Err_OK;
	}
	else if (Err_TaskPending != nRet) {
		print("Connect failed, errorCode: %d\n", nRet);
		return nRet;
		// throw std::runtime_error("Connect failed, errorCode: " + nRet);
	}
	auto fur = this->prepare.get_future();
	std::chrono::milliseconds timeout(ms);
	if (fur.wait_for(timeout) == std::future_status::timeout) {
		print("Connect timeou.\n");
		// throw std::runtime_error("连接采集设备超时(Connect timeout).");
		return Err_TaskTimeOut;
	}
	return Err_OK;
}

std::pair<FPDRESULT, IRayImage*> CDetector::WaitForImage(int ms) {
	auto fur = this->image.get_future();
	std::chrono::milliseconds timeout(ms);
	if (fur.wait_for(timeout) == std::future_status::timeout) {
		return std::make_pair<FPDRESULT, IRayImage*>(Err_TaskTimeOut, NULL);
	}
	return std::make_pair<FPDRESULT, IRayImage*>(Err_OK, fur.get());;
}

FPDRESULT CDetector::StopAcquire()
{
	return Invoke(Cmd_StopAcq);
}

FPDRESULT CDetector::ReadTemperature()
{
	return Invoke(Cmd_ReadTemperature);
}

FPDRESULT CDetector::SetAttr(int nAttrID, int nValue)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	IRayVariant var;
	var.vt = IVT_INT;
	var.val.nVal = nValue;
	FPDRESULT result = m_fpSetAttr(m_nDetectorID, nAttrID, &var);
	if (Err_OK != result)
	{
		print("Set Attribute  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}

FPDRESULT CDetector::SetAttr(int nAttrID, float fValue)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	IRayVariant var;
	var.vt = IVT_FLT;
	var.val.fVal = fValue;
	FPDRESULT result = m_fpSetAttr(m_nDetectorID, nAttrID, &var);
	if (Err_OK != result)
	{
		print("Set Attribute  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}
FPDRESULT CDetector::SetAttr(int nAttrID, const char *strValue)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	if (!strValue)
		return Err_InvalidParamValue;

	IRayVariant var;
	var.vt = IVT_STR;
	strcpy_s(var.val.strVal, strValue);
	FPDRESULT result = m_fpSetAttr(m_nDetectorID, nAttrID, &var);
	if (Err_OK != result)
	{
		print("Set Attribute  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}

void CDetector::GetAttr(int nAttrID, AttrResult &result)
{
	IRayVariant var;
	FPDRESULT ret = m_fpGetAttr(m_nDetectorID, nAttrID, &var);
	if (Err_OK != ret)
	{
		memset(&result, 0, sizeof(result));
		return;
	}

	if (IVT_INT == var.vt)
	{
		result.nVal = var.val.nVal;
	}
	else if (IVT_FLT == var.vt)
	{
		result.fVal = var.val.fVal;
	}
	else if (IVT_STR == var.vt)
	{
		memcpy_s(result.strVal, IRAY_MAX_STR_LEN, var.val.strVal, IRAY_MAX_STR_LEN);
	}
}

std::string CDetector::GetErrorInfo(int nErrorCode)
{
	ErrorInfo info;
	m_pFnGetErrorInfo(nErrorCode, &info);
	return string(info.szDescription);
}

/**
SetCaliSubset("Mode1"); У����Ŀ¼Ϊ��pszWorkDir\Correct\Mode1
*/
FPDRESULT CDetector::SetCaliSubset(const char *pSubDir)
{
	return Invoke(Cmd_SetCaliSubset, pSubDir);
}

FPDRESULT CDetector::SetCorrectionOption(int nValue)
{
	return Invoke(Cmd_SetCorrectOption, nValue);
}

FPDRESULT CDetector::Invoke(int cmdId)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	FPDRESULT result = m_fpInvoke(m_nDetectorID, cmdId, NULL, 0);
	if (Err_OK != result && Err_TaskPending != result)
	{
		print("Invoke  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}

FPDRESULT CDetector::Invoke(int cmdId, int nValue)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	IRayCmdParam param;
	param.pt = IPT_VARIANT;
	param.var.vt = IVT_INT;
	param.var.val.nVal = nValue;
	FPDRESULT result = m_fpInvoke(m_nDetectorID, cmdId, &param, 1);
	if (Err_OK != result && Err_TaskPending != result)
	{
		print("Invoke  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}

FPDRESULT CDetector::Invoke(int cmdId, int nPar1, int nPar2)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	IRayCmdParam param[2];
	param[0].pt = IPT_VARIANT;
	param[0].var.vt = IVT_INT;
	param[0].var.val.nVal = nPar1;
	param[1].pt = IPT_VARIANT;
	param[1].var.vt = IVT_INT;
	param[1].var.val.nVal = nPar2;
	FPDRESULT result = m_fpInvoke(m_nDetectorID, cmdId, param, 2);
	if (Err_OK != result && Err_TaskPending != result)
	{
		print("Invoke  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}

FPDRESULT CDetector::Invoke(int cmdId, float fValue)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	IRayCmdParam param;
	param.pt = IPT_VARIANT;
	param.var.vt = IVT_FLT;
	param.var.val.fVal = fValue;
	FPDRESULT result = m_fpInvoke(m_nDetectorID, cmdId, &param, 1);
	if (Err_OK != result && Err_TaskPending != result)
	{
		print("Invoke  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}

FPDRESULT CDetector::Invoke(int cmdId, const char *strValue)
{
	if (!m_bInitilized)
		return Err_NotInitialized;

	if (!strValue)
		return Err_InvalidParamValue;
	IRayCmdParam param;
	param.var.vt = IVT_STR;
	//memset(param[0].var.val.strVal, 0, 512);
	//memcpy_s(param[0].var.val.strVal, 512, pSubDir, strlen(pSubDir));
	strcpy_s(param.var.val.strVal, strValue);
	FPDRESULT result = m_fpInvoke(m_nDetectorID, cmdId, &param, 1);
	if (Err_OK != result && Err_TaskPending != result)
	{
		print("Invoke  failed! Err = %s", GetErrorInfo(result).c_str());
	}
	return result;
}

void CDetector::SDKCallback(int nDetectorID, int nEventID, int nEventLevel,
							const char *pszMsg, int nParam1, int nParam2, int nPtrParamLen, void *pParam)
{
	if (nEventID == Evt_TaskResult_Succeed) {
		if (nParam1 == Cmd_Connect) {
			this->ready.set_value();
		}
	}
	else if (Evt_Exp_Enable == nEventID) {
		this->prepare.set_value();
	}
	else if(nEventID == Evt_TaskResult_Failed) {
		if (nParam1 == Cmd_Connect) {
			this->ready.set_exception(std::make_exception_ptr(std::exception("采集设备连接失败")));
		}
	}
	else if (nEventID == Evt_Image) {
		this->image.set_value((IRayImage*)pParam);
	}

	vector<DetectorCallback*>::iterator iter = m_receivers.begin();
	for (; iter != m_receivers.end(); ++iter)
	{
		DetectorCallback*pCB = *iter;
		(*pCB)(this, nEventID, nEventLevel,
						pszMsg, nParam1, nParam2, nPtrParamLen, pParam);
	}
}

void CDetector::RegisterHandler(DetectorCallback*p)
{
	if (m_receivers.size() == 0)
	{
		m_receivers.push_back(p);
		return;
	}
	vector<DetectorCallback*>::iterator iter = find(m_receivers.begin(), m_receivers.end(), p);
	if (iter == m_receivers.end())
	{
		m_receivers.push_back(p);
	}
}

void CDetector::UnRegisterHandler(DetectorCallback*p)
{
	if (m_receivers.size() == 0)
	{
		return;
	}
	vector<DetectorCallback*>::iterator iter = find(m_receivers.begin(), m_receivers.end(), p);
	if (iter != m_receivers.end())
	{
		m_receivers.erase(iter);
	}
}
