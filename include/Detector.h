#ifndef _DETECTOR_H
#define _DETECTOR_H

#include "IRayFpdSys.h"
#include "IRayFpdSysEx.h"
#include "EventReceiver.h"
#include <Windows.h>
#include <vector>
#include <string>
#include <future>
using namespace ::std;

class CDetectorManager;
class CDetector;

/**
* FnCallback: Define a function type for SDK callback,
*             this definition will be used as an function argument while creating a detector object.
*
* @param nDetectorID [in] the detector which fired the event
* @param nEventID [in] event ID
* @param nEventLevel [in] event level
* @param pszMsg [in] string description for the event
* @param nParam1 [in] parameter with the event, defined for a certain event
* @param nParam2 [in] parameter with the event, defined for a certain event
* @param nPtrParamLen [in] bytes count for pointer typed parameter, defined for a certain event
* @param pParam [in] pointer typed parameter, defined for a certain event
*
* @return void
*/
typedef void(DetectorCallback)(CDetector* pDetector, int nEventID, int nEventLevel,
	const char* pszMsg, int nParam1, int nParam2, int nPtrParamLen, void* pParam);



union AttrResult
{
	int nVal;
	float fVal;
	char strVal[IRAY_MAX_STR_LEN];
};

class CDetector
{
public:
	static CDetector *CreateDetector(const char *pszWorkDir);
	static void DestoryDetector(int id);

	FPDRESULT Connect(); 
	FPDRESULT ConnectSync(int ms = 10000);
	FPDRESULT Disconnect();
	FPDRESULT SingleAcquire();
	FPDRESULT PrepAcquire();
	FPDRESULT StartAcquire();
	FPDRESULT StartAcquireSync(int ms = 10000);
	std::pair< FPDRESULT, IRayImage*> WaitForImage(int ms = 10000);
	FPDRESULT StopAcquire();
	FPDRESULT ReadTemperature();
	FPDRESULT SetCorrectionOption(int nValue);
	FPDRESULT SetAttr(int nAttrID, int nValue);
	FPDRESULT SetAttr(int nAttrID, float fValue);
	FPDRESULT SetAttr(int nAttrID, const char *strValue);
	void GetAttr(int nAttrID, AttrResult &result);
	FPDRESULT Invoke(int cmdId);
	FPDRESULT Invoke(int cmdId, int nValue);
	FPDRESULT Invoke(int cmdId, int nPar1, int nPar2);
	FPDRESULT Invoke(int cmdId, float fValue);
	FPDRESULT Invoke(int cmdId, const char *strValue);
	string GetErrorInfo(int nErrorCode);
	FPDRESULT SetCaliSubset(const char *pSubDir);
	int DetectorID() { return m_nDetectorID; }
	void SDKCallback(int nDetectorID, int nEventID, int nEventLevel,
					 const char *pszMsg, int nParam1, int nParam2, int nPtrParamLen, void *pParam);
	void RegisterHandler(DetectorCallback*p);
	void UnRegisterHandler(DetectorCallback*p);


	static const int OFFSETMASK;
	static const int GAINMASK;
	static const int DEFECTMASK;

private:
	CDetector();
	~CDetector();
	FPDRESULT Create(const char *pszWorkDir, FnCallback fpCallback);
	FPDRESULT CreateAndConnect(const char *pszWorkDir, FnCallback fpCallback);
	FPDRESULT Destory();
	static CDetectorManager *m_pDetMgr;
	friend class CDetectorManager;

	bool Init();
	void Deinit();
	bool m_bInitilized;
	HMODULE m_hModule;
	FnCreate m_fpCreate;
	FnDestroy m_fpDestroy;
	FnGetAttr m_fpGetAttr;
	FnSetAttr m_fpSetAttr;
	FnInvoke m_fpInvoke;
	FnGetErrInfo m_pFnGetErrorInfo;
	int m_nDetectorID;
	vector<DetectorCallback *> m_receivers;
	std::promise<void> ready;
	std::promise<void> prepare;
	std::promise<IRayImage *> image;
};

#endif