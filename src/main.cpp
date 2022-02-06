#include <iostream>
#include <future>
#include <chrono>
#include <windows.h>
#include "IRayFpdSys.h"
#include "DetectorManager.h"
#include "Detector.h"
#define TEST_WORKDIR_1 "C:\\Users\\Keyon\\Desktop\\ShengHong\\CapDriver\\sdk\\work_dir\\Mars1417V3"
// #define TEST_WORKDIR_2 "D:\\MyDR\\MyDetector2"

void MyCallback(int nDetectorID, int nEventID, int nEventLevel,
	const char* pszMsg, int nParam1, int nParam2, int nPtrParamLen, void* pParam);

FnCreate  g_fpCreate;
FnDestroy g_fpDestroy;
FnGetAttr g_fpGetAttr;
FnSetAttr g_fpSetAttr;
FnInvoke  g_fpInvoke;
FnGetSDKVersion g_fpGetSDKVersion;
int nDetectorID1;
HMODULE hModule;

auto connectWait = new std::promise<void>();
auto readyWait = new std::promise<void>();


int main(int argc, char* argv[])
{
	SetCurrentDirectory("C:\\Users\\Keyon\\Desktop\\ShengHong\\CapDriver\\sdk\\bin\\x64");
	CDetector * m_pDetector = CDetector::CreateDetector(TEST_WORKDIR_1);
	
	DetectorCallback *onConnect = [](CDetector* nDetectorID, int nEventID, int nEventLevel,
		const char* pszMsg, int nParam1, int nParam2, int nPtrParamLen, void* pParam) -> void {
			std::cout << "EventID: " << nEventID << " nParam1: " << nParam1 << " Msg: " << pszMsg << std::endl;
			/*if (nEventID == Evt_TaskResult_Succeed) {
				if (nParam1 == Cmd_Connect) {
					printf("Connected\n");
					connectWait->set_value();
				}
			}*/
	};
	m_pDetector->RegisterHandler(onConnect);
	FPDRESULT result;
	result = m_pDetector->ConnectSync(); // 连接采集卡
    if (result != Err_OK) {
	    return -1;
    }
	result = m_pDetector->StartAcquireSync(); // 准备采集
	if (result != Err_OK) {
		return -1;
	}
	// TODO 曝光
	printf("exposure\n");
	auto res = m_pDetector->WaitForImage();
	if (res.first != Err_OK) {
		return -1;
	}
	IRayImage* pImg = res.second;
	const unsigned short* pImageData = pImg->pData;
	int nImageWidth = pImg->nWidth;
	int nImageHeight = pImg->nHeight;
	int nImageSize = nImageWidth * nImageHeight * pImg->nBytesPerPixel;
	if (!pImageData || (0 == nImageSize)) return -1;
	HANDLE hFile = CreateFile("image.raw", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD nWriten = 0;
	WriteFile(hFile, pImageData, nImageSize, &nWriten, NULL);
	CloseHandle(hFile);
	return 0;
	//auto result = m_pDetector->Connect();
	//if (result == Err_TaskPending) {

	//}
	//else if (result != Err_OK) {
	//	std::cout << "Connect Failed!" << result << std::endl;
	//	// connectWait->set_exception()
	//}
	//else {
	//	connectWait->set_value();
	//}
	//auto fur = connectWait->get_future();
	//std::chrono::milliseconds timeout(10000);
	//if (fur.wait_for(timeout) == std::future_status::timeout) {
	//	std::cout << "Connect Failed2! " << result << std::endl;
	//	return 0;
	//}
	//fur.get();

	//int t = 10;
	//AttrResult var;
	//while (t > 0) {
	//	m_pDetector->GetAttr(Attr_State, var);
	//	if (var.nVal != Enm_State_Ready) {
	//		printf("Not ready (%d), Retry.\n", var.nVal);
	//		Sleep(10);
	//	
	//		if (t == 0) {
	//			return -1;
	//		}
	//		t--;
	//	}
	//	else {
	//		break;
	//	}
	//}
	//
	//
	//m_pDetector->StartAcquire();

	//printf("ready");
	/*
	hModule = LoadLibraryA("FpdSys.DLL");
	if (NULL == hModule)
	{
		printf("\r\n----Load SDK DLL failed!----");

		return 0;
	}

	g_fpCreate = (FnCreate)GetProcAddress(hModule, IRAY_FPD_PROC_NAME_CREATE);
	g_fpDestroy = (FnDestroy)GetProcAddress(hModule, IRAY_FPD_PROC_NAME_DESTROY);
	g_fpGetAttr = (FnGetAttr)GetProcAddress(hModule, IRAY_FPD_PROC_NAME_GETATTR);
	g_fpSetAttr = (FnSetAttr)GetProcAddress(hModule, IRAY_FPD_PROC_NAME_SETATTR);
	g_fpInvoke = (FnInvoke)GetProcAddress(hModule, IRAY_FPD_PROC_NAME_INVOKE);
    g_fpGetSDKVersion = (FnGetSDKVersion)GetProcAddress(hModule, IRAY_FPD_PROC_NAME_VERSION);

	if (NULL == g_fpCreate || NULL == g_fpDestroy || NULL == g_fpGetAttr ||
		NULL == g_fpSetAttr || NULL == g_fpInvoke)
	{
		printf("\r\n----Get exported function failed!----");
		std::cout << (g_fpCreate == NULL) << (g_fpDestroy == NULL)<< (g_fpGetAttr  == NULL) << (g_fpSetAttr == NULL) << (g_fpInvoke == NULL) << std::endl;
		FreeLibrary(hModule);

		return 0;
	}

	FPDRESULT result;
    // char ver[32];
    // result = g_fpGetSDKVersion(ver);

    // std::cout << "result: " << result << " ver: "<< ver << std::endl;

	
	result = g_fpCreate(TEST_WORKDIR_1, &MyCallback, &nDetectorID1);
	if(Err_OK != result) {
		printf("\r\n----Create detector object failed %d !----", result);
		FreeLibrary(hModule);
		return 0;
	}

	// IRayVariant var;
	// result = g_fpGetAttr(nDetectorID1, Attr_State, &var);
	// if (Err_OK != result) {
	// 	printf("\r\n----Test get attribute data failed!----");
	// 	FreeLibrary(hModule);
	// 	return 0;
	// } else if(var.val.nVal != Enm_State_Ready) {
	// 	printf("\r\n----Test command detector not ready.----");
	// 	FreeLibrary(hModule);
	// 	return 0;
	// }

	// result = g_fpInvoke(nDetectorID1, Cmd_StartAcq, NULL, 0);
	// if (Err_TaskPending != result) {
	// 	printf("\r\n----Test command invoke is pending, please wait task result event.----");
	// 	FreeLibrary(hModule);
	// 	return 0;
	// }
	result = g_fpInvoke(nDetectorID1, Cmd_Connect, NULL, 0);
	if (Err_TaskPending == result)
	{
		printf("\r\n----Test command invoke is pending, please wait task result event.----"); 
	}
	if (Err_OK == result)
	{
		
		// var.vt = IVT_INT;
		// var.val.nVal = 1;
		// result = g_fpSetAttr(nDetectorID1, Cfg_ComPort, &var);
		// if (Err_OK != result)
		// {
		// 	printf("\r\n----Test set attribute data failed!----");
		// }
		// else
		// {
		// 	printf("\r\n----Test set attribute data succeed----");
		// }

		// result = g_fpGetAttr(nDetectorID1, Attr_State, &var);
		
		// else
		// {
		// 	printf("\r\n----Test get attribute data succeed, value = %d----", var.val.nVal);
		// }
		// result = g_fpInvoke(nDetectorID1, Cmd_Connect, NULL, 0);
		// if (Err_TaskPending == result)
		// {
		// 	printf("\r\n----Test command invoke is pending, please wait task result event.----");
		// }
		// else if (Err_OK == result)
		// {
		// 	printf("\r\n----Test command invoke succeed!----");
		// }
		// else
		// {
		// 	printf("\r\n----Test command invoke failed! ErrCode = %d----", result);
		// }
	}
	else
	{
		
	}


	g_fpDestroy(nDetectorID1);
	// g_fpDestroy(nDetectorID2);

	FreeLibrary(hModule);
	*/
	while (getchar() != 'q')
	{
		Sleep(10);
	}

	return 0;
}

void MyCallback(int nDetectorID, int nEventID, int nEventLevel,
	const char* pszMsg, int nParam1, int nParam2, int nPtrParamLen, void* pParam)
{
	IRayImage *img;

	switch (nEventID)
	{
	case Evt_TaskResult_Succeed:
		if (Cmd_Connect == nParam1)
		{
			printf("\r\n----Test event callback succeed, Detector connected: ID = %d----", nDetectorID);
			FPDRESULT result;

			IRayVariant var;
			var.vt = IVT_INT;
			result = g_fpGetAttr(nDetectorID1, Attr_State, &var);
			if (Err_OK != result) {
				printf("\r\n----Test get attribute data failed!----");
				FreeLibrary(hModule);
				break;
			} else if(var.val.nVal != Enm_State_Ready) {
				printf("\r\n----Test command detector not ready. (%d)----", var.val.nVal);
				FreeLibrary(hModule);
				break;
			}

			result = g_fpInvoke(nDetectorID1, Cmd_StartAcq, NULL, 0);
			if (Err_TaskPending != result) {
				printf("\r\n----Test command invoke is pending, please wait task result event.----");
				FreeLibrary(hModule);
			}
		}
		break;
	case Evt_Image:
		img = (IRayImage*)pParam;
		std::cout << "width: " << img->nWidth << ", height: " << img->nHeight << ", nBytesPerPixel:" << img->nBytesPerPixel << std::endl;
		break;
	default:
		break;
	}
}