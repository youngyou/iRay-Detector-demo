/**
* File: IRayCmdDef.h
*
* Purpose: IRay command definition
*
*
* @author Haitao.Ning
* @version 1.0 2015/4/23
*
* Copyright (C) 2009, 2015, iRay Technology (Shanghai) Ltd.
*
*/
#ifndef _IRAY_COMMAND_DEF_H_
#define _IRAY_COMMAND_DEF_H_

#define Cmd_SetLogLevel	1
#define Cmd_Connect	2
#define Cmd_Disconnect	3
#define Cmd_Sleep	4
#define Cmd_Wakeup	5
#define Cmd_SetCorrectOption	6
#define Cmd_SetCaliSubset	7
#define Cmd_Reset	8
#define Cmd_Clear	1001
#define Cmd_ClearAcq	1002
#define Cmd_Acq2	1003
#define Cmd_AecPreExp	1016
#define Cmd_StartAcq	1004
#define Cmd_StopAcq	1005
#define Cmd_ForceSingleAcq	1006
#define Cmd_ForceContinuousAcq	1007
#define Cmd_ForceDarkSingleAcq	1008
#define Cmd_ForceDarkClearAcq	1009
#define Cmd_ForceDarkContinuousAcq	1010
#define Cmd_ProhibOutExp	1011
#define Cmd_EnableOutExp	1012
#define Cmd_SyncStart	1013
#define Cmd_SyncCancel	1014
#define Cmd_SyncAcq	1015
#define Cmd_EnterStitchingFlow	1017
#define Cmd_StitchingAcqOnce	1018
#define Cmd_QuitStitchingFlow	1019
#define Cmd_RetrieveFreshStitchingImages	1020
#define Cmd_ClearStitchingImages	1021
#define Cmd_RetrieveFreshImages	1022
#define Cmd_AbortBackstageImageTransfer	1023
#define Cmd_ReadUserROM	2001
#define Cmd_WriteUserROM	2002
#define Cmd_ReadUserRAM	2030
#define Cmd_WriteUserRAM	2031
#define Cmd_ReadFactoryROM	2003
#define Cmd_WriteFactoryROM	2004
#define Cmd_ReadVtMap	2005
#define Cmd_WriteVtMap	2006
#define Cmd_Recover	2007
#define Cmd_UpdateFirmware	2008
#define Cmd_SetImgChannel	2009
#define Cmd_ReadTemperature	2010
#define Cmd_ReadHumidity	2011
#define Cmd_UploadDetectorLog	2012
#define Cmd_UploadShockLog	2013
#define Cmd_ClearShockLog	2014
#define Cmd_WriteShockThreshold	2015
#define Cmd_ReadShockThreshold	2016
#define Cmd_ReadBatteryStatus	2017
#define Cmd_SetTimeByDiff	2018
#define Cmd_QueryTimeDiff	2019
#define Cmd_QueryLivingTime	2020
#define Cmd_ReadWifiStatus	2021
#define Cmd_QueryWifiScanList	2022
#define Cmd_WriteWifiSettings	2023
#define Cmd_ReadWifiSettings	2024
#define Cmd_DownloadWorkList	2025
#define Cmd_QueryHistoricalImageList	2026
#define Cmd_SelectWorkItem	2027
#define Cmd_UploadHistoricalImages	2028
#define Cmd_StopUploadingHistoricalImages	2029
#define Cmd_ChangeParamsOfCurrentAppMode	2032
#define Cmd_QueryLastImageID	2033
#define Cmd_GetImageByImageID	2034
#define Cmd_WriteCustomROM	2035
#define Cmd_ReadCustomROM	2036
#define Cmd_WriteLicenseData	2037
#define Cmd_ReadLicenseData	2038
#define Cmd_ReadHallSensor	2039
#define Cmd_ClearHistoricalImages	2040
#define Cmd_OffsetGeneration	3001
#define Cmd_GainInit	3002
#define Cmd_GainSelectCurrent	3004
#define Cmd_GainSelectAll	3005
#define Cmd_GainGeneration	3006
#define Cmd_DefectInit	3007
#define Cmd_LoadTemporaryDefectFile	3008
#define Cmd_DefectSelectCurrent	3009
#define Cmd_DefectSelectAll	3033
#define Cmd_DefectGeneration	3010
#define Cmd_LagPrepareDarkImages	3037
#define Cmd_LagInit	3012
#define Cmd_LagSelectCurrent	3013
#define Cmd_LagGeneration	3014
#define Cmd_GridInit	3036
#define Cmd_GridGeneration	3038
#define Cmd_DownloadCertificationFile	3039
#define Cmd_PanelCertificate	3040
#define Cmd_UpdateFreqCompositeCoeff	3032
#define Cmd_CalibrationInit	3035
#define Cmd_FinishGenerationProcess	3015
#define Cmd_DeleteGenerationTempFile	3016
#define Cmd_DownloadCaliFile	3017
#define Cmd_UploadCaliFile	3018
#define Cmd_SelectCaliFile	3019
#define Cmd_HwGeneratePreOffsetTemplate	3020
#define Cmd_QueryHwCaliTemplateList	3021
#define Cmd_ApplyDefectCorrection	3022
#define Cmd_RequestSyncboxControl	3023
#define Cmd_ReleaseSyncboxControl	3024
#define Cmd_ReadOutExpEnableState	3025
#define Cmd_EnableAutoSleep	3026
#define Cmd_DisableAutoSleep	3027
#define Cmd_ReadAutoSleepEnableState	3028
#define Cmd_PowerOff	3029
#define Cmd_StartAutoCleanup	3030
#define Cmd_StopAutoCleanup	3031
#define Cmd_PanelRecover	3034
#define Cmd_Debug_ReadCRC	10001
#define Cmd_ReadCustomFile	4001
#define Cmd_WriteCustomFile	4002
#define Cmd_ActivePanel	4003
#define Cmd_DeactivePanel	4004
#define Cmd_ReadCustomData	4005
#define Cmd_WriteCustomData	4006

#endif