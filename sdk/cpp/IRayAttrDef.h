/**
* File: IRayAttrDef.h
*
* Purpose: IRay attribute definition
*
*
* @author Haitao.Ning
* @version 1.0 2015/4/23
*
* Copyright (C) 2009, 2015, iRay Technology (Shanghai) Ltd.
*
*/
#ifndef _IRAY_ATTRIBUTE_DEF_H_
#define _IRAY_ATTRIBUTE_DEF_H_

#define Cfg_ProtocolEdition	1
#define Cfg_ProductNo	2
#define Cfg_SN	3
#define Cfg_UseServiceProcess	8
#define Cfg_DetectorImp	4
#define Cfg_ConnImp	5
#define Cfg_CaliImp	6
#define Cfg_LogLevel	7
#define Cfg_HostIP	101
#define Cfg_HostPort	102
#define Cfg_RemoteIP	103
#define Cfg_RemotePort	104
#define Cfg_ComPort	105
#define Cfg_PleoraConnStr	106
#define Cfg_PleoraPacketSize	107
#define Cfg_WinpcapConnStr	108
#define Cfg_PleoraMaxFps	109
#define Cfg_HostImagePort	110
#define Cfg_HostImageAckPort	111
#define Cfg_PCIEBoardIndex	112
#define Cfg_E5_ResendCnt	113
#define Cfg_E5_ResendInterval	114
#define Cfg_HeartBeatTimeOutDuration	115
#define Cfg_RepeatCmdEnable	150
#define Cfg_USBConnStr	151
#define Cfg_FTP_Download_HostIP	201
#define Cfg_FTP_Download_HostPort	202
#define Cfg_FTP_Download_User	203
#define Cfg_FTP_Download_PWD	204
#define Cfg_FTP_Download_LocalPath	205
#define Cfg_FTP_Upload_HostIP	206
#define Cfg_FTP_Upload_HostPort	207
#define Cfg_FTP_Upload_User	208
#define Cfg_FTP_Upload_PWD	209
#define Cfg_FTP_Upload_LocalPath	210
#define Cfg_OffsetAlarmMinute	301
#define Cfg_GainAlarmTime	302
#define Cfg_DefectAlarmTime	303
#define Cfg_CaliValidity_PreWarnMinute	304
#define Cfg_CaliValidity_Enable	305
#define Cfg_DefaultSubset	306
#define Cfg_DefaultCorrectOption	307
#define Cfg_DefectStatistical_DummyTop	308
#define Cfg_DefectStatistical_DummyBottom	309
#define Cfg_DefectStatistical_DummyLeft	310
#define Cfg_DefectStatistical_DummyRight	311
#define Cfg_CalibrationFlow	312
#define Cfg_EnableROIShareTemplate	313
#define Cfg_GridRemovalPreProcess_Enable	314
#define Cfg_ClearAcqParam_DelayTime	501
#define Cfg_FpsCheck_Enable	502
#define Cfg_FpsCheck_Tolerance	503
#define Cfg_FWUpdTimeOut	504
#define Cfg_OfflineInspectTimeout	505
#define Cfg_AllowReconnectByOnlineNotice	506
#define Cfg_ResetTimeout	507
#define Cfg_PreviewImage_Enable	508
#define Cfg_PushImageAtExpTimeout_Enable	509
#define Cfg_RetransferCount	510
#define Cfg_ConnRecoverTimeout	511
#define Cfg_TemperatureHighThreshold	512
#define Cfg_AllowMismatchSN	513
#define Cfg_ImagePacketGapTimeout	514
#define Cfg_FwAllowedDefectPoints	515
#define Cfg_PostOffsetStart_DelayTime	516
#define Cfg_TotalAcqTimeout	517
#define Cfg_PreExpImageAcqTimeout	518
#define Cfg_CleanupProcessTime	519
#define Cfg_SeqAcq_AutoStopToSyncExp	520
#define Cfg_Acq2SubFlow	521
#define Cfg_DetectorSleepMode	522
#define Cfg_SkipFirmwareCheck	523
#define Cfg_TimingOutput	524
#define Cfg_RetransferImageEnable	525
#define Cfg_AecPrevBinningMode	526
#define Cfg_FtransTimeoutPreM	527
#define Cfg_SubjoinDelayTime	528
#define Cfg_BEImageCacheTimeMs	529
#define Cfg_ShockLog_ShowMode	530
#define Cfg_WaitGenHWOffsetTemplateTime	531
#define Attr_Prod_Name	1001
#define Attr_Prod_Description	1002
#define Attr_Prod_FullWidth	1003
#define Attr_Prod_FullHeight	1004
#define Attr_Prod_PhysicalPixelSize	1005
#define Attr_Prod_BitDepth	1006
#define Attr_Prod_DataBytesPerPacket	1007
#define Attr_Prod_TotalPacketNumber	1008
#define Attr_Prod_DummyTop	1009
#define Attr_Prod_DummyBottom	1010
#define Attr_Prod_DummyLeft	1011
#define Attr_Prod_DummyRight	1012
#define Attr_Prod_AfeChSize	1014
#define Attr_Prod_GateSize	1016
#define Attr_Prod_GateEdge	1017
#define Attr_Prod_DriveMode	1013
#define Attr_Prod_ReXferMode	1015
#define Attr_UROM_ProductNo	2001
#define Attr_UROM_MainVersion	2002
#define Attr_UROM_ReadVersion	2003
#define Attr_UROM_McuVersion	2004
#define Attr_UROM_ArmVersion	2005
#define Attr_UROM_KernelVersion	2006
#define Attr_UROM_ProtocolVersion	2007
#define Attr_UROM_MasterBuildTime	2008
#define Attr_UROM_SlaveBuildTime	2009
#define Attr_UROM_McuBuildTime	2010
#define Attr_UROM_RowPreDelayTime	2011
#define Attr_UROM_RowPostDelayTime	2012
#define Attr_UROM_IntegrateTime	2013
#define Attr_UROM_ZoomMode	2014
#define Attr_UROM_ExpEnable_SignalLevel	2015
#define Attr_UROM_SelfClearEnable	2016
#define Attr_UROM_SelfClearSpanTime	2017
#define Attr_UROM_SequenceIntervalTime	2018
#define Attr_UROM_TriggerMode	2019
#define Attr_UROM_DynamicFlag	2020
#define Attr_UROM_TubeReadyTime	2021
#define Attr_UROM_SequenceIntervalTime_HighPrecision	2022
#define Attr_UROM_SetDelayTime	2023
#define Attr_UROM_ExpWindowTime	2025
#define Attr_UROM_SyncExpTime	2027
#define Attr_UROM_SyncExpTime_HighPrecision	2028
#define Attr_UROM_VT	2029
#define Attr_UROM_PGA	2030
#define Attr_UROM_PrepCapMode	2032
#define Attr_UROM_SelfCapEnable	2033
#define Attr_UROM_FluroSync	2034
#define Attr_UROM_SrcPort	2035
#define Attr_UROM_SrcIP	2036
#define Attr_UROM_SrcMAC	2037
#define Attr_UROM_DestPort	2038
#define Attr_UROM_DestIP	2039
#define Attr_UROM_DestMAC	2040
#define Attr_UROM_SyncboxIP	2041
#define Attr_UROM_PreviewImgMode	2044
#define Attr_UROM_HWOffsetType	2045
#define Attr_UROM_AcquireDelayTime	2046
#define Attr_UROM_BinningMode	2047
#define Attr_UROM_ExpMode	2050
#define Attr_UROM_AecMainTime	2051
#define Attr_UROM_DynaOffsetGapTime	2052
#define Attr_UROM_DynaOffsetEnable	2053
#define Attr_UROM_ImagePktGapTime	2054
#define Attr_UROM_OutModeCapTrig	2069
#define Attr_UROM_HvgPrepOn	2055
#define Attr_UROM_HvgXRayEnable	2056
#define Attr_UROM_HvgXRayOn	2057
#define Attr_UROM_HvgXRaySyncOut	2058
#define Attr_UROM_HvgXRaySyncIn	2059
#define Attr_UROM_CbxBuildTime	2060
#define Attr_UROM_SubProductNo	2061
#define Attr_UROM_SerialNo	2062
#define Attr_UROM_ImageChType	2063
#define Attr_UROM_ImageChProtocol	2064
#define Attr_UROM_HWGainEnable	2065
#define Attr_UROM_ExpTimeValidPercent	2066
#define Attr_UROM_FreesyncCenterThreshold	2067
#define Attr_UROM_FreesyncEdgeThreshold	2068
#define Attr_UROM_FreesyncSubFlow	2070
#define Attr_UROM_PowSeriesCorrectEnable	2071
#define Attr_UROM_PulseClearTimes	2072
#define Attr_UROM_ROIColStartPos	2073
#define Attr_UROM_ROIColEndPos	2074
#define Attr_UROM_ROIRowStartPos	2075
#define Attr_UROM_ROIRowEndPos	2076
#define Attr_UROM_FullWell	2077
#define Attr_UROM_InnerSubFlow	2078
#define Attr_UROM_SoftwareSubFlow	2079
#define Attr_UROM_MainMBCpuVersion	2080
#define Attr_UROM_MainMBCpuBuildTime	2081
#define Attr_UROM_XCombWiseType	2082
#define Attr_UROM_YCombWiseType	2083
#define Attr_UROM_SubProductVersion	2084
#define Attr_UROM_WarningTemperature	2085
#define Attr_UROM_PowerOffTemperature	2086
#define Attr_UROM_WLAN_DHCPEnable	2087
#define Attr_UROM_LAN_DHCPEnable	2088
#define Attr_UROM_DHCP_StaticIP	2089
#define Attr_UROM_HWPreoffsetBase	2090
#define Attr_UROM_ShockMcuVersion	2091
#define Attr_UROM_ShockMcuBuildTime	2092
#define Attr_UROM_ProductConfigCode	2093
#define Attr_UROM_NetworkBand	2094
#define Attr_UROM_CofPGA	2095
#define Attr_UROM_TriggerThreshold	2096
#define Attr_UROM_NumberOfFramesDiscardedInSequenceAcquire	2097
#define Attr_UROM_AutoSleepIdleTime	2098
#define Attr_UROM_IntegrateTime_W	2540
#define Attr_UROM_ZoomMode_W	2501
#define Attr_UROM_ExpEnable_SignalLevel_W	2502
#define Attr_UROM_SelfClearEnable_W	2503
#define Attr_UROM_SelfClearSpanTime_W	2504
#define Attr_UROM_SequenceIntervalTime_W	2505
#define Attr_UROM_TriggerMode_W	2506
#define Attr_UROM_DynamicFlag_W	2507
#define Attr_UROM_TubeReadyTime_W	2508
#define Attr_UROM_SetDelayTime_W	2510
#define Attr_UROM_SequenceIntervalTime_HighPrecision_W	2511
#define Attr_UROM_ExpWindowTime_W	2512
#define Attr_UROM_PGA_W	2513
#define Attr_UROM_PrepCapMode_W	2514
#define Attr_UROM_SelfCapEnable_W	2515
#define Attr_UROM_FluroSync_W	2516
#define Attr_UROM_SrcIP_W	2518
#define Attr_UROM_SrcMAC_W	2519
#define Attr_UROM_DestPort_W	2520
#define Attr_UROM_DestIP_W	2521
#define Attr_UROM_DestMAC_W	2522
#define Attr_UROM_PreviewImgMode_W	2523
#define Attr_UROM_HWOffsetType_W	2544
#define Attr_UROM_SyncboxIP_W	2543
#define Attr_UROM_AcquireDelayTime_W	2524
#define Attr_UROM_BinningMode_W	2525
#define Attr_UROM_ExpMode_W	2528
#define Attr_UROM_AecMainTime_W	2529
#define Attr_UROM_DynaOffsetGapTime_W	2530
#define Attr_UROM_DynaOffsetEnable_W	2531
#define Attr_UROM_ImagePktGapTime_W	2542
#define Attr_UROM_OutModeCapTrig_W	2541
#define Attr_UROM_HvgPrepOn_W	2532
#define Attr_UROM_HvgXRayEnable_W	2533
#define Attr_UROM_HvgXRayOn_W	2534
#define Attr_UROM_HvgXRaySyncOut_W	2535
#define Attr_UROM_HvgXRaySyncIn_W	2536
#define Attr_UROM_ExpTimeValidPercent_W	2537
#define Attr_UROM_FreesyncCenterThreshold_W	2538
#define Attr_UROM_FreesyncEdgeThreshold_W	2539
#define Attr_UROM_PowSeriesCorrectEnable_W	2545
#define Attr_UROM_ROIColStartPos_W	2546
#define Attr_UROM_ROIColEndPos_W	2547
#define Attr_UROM_ROIRowStartPos_W	2548
#define Attr_UROM_ROIRowEndPos_W	2549
#define Attr_UROM_FullWell_W	2550
#define Attr_UROM_PulseClearTimes_W	2551
#define Attr_UROM_InnerSubFlow_W	2552
#define Attr_UROM_SoftwareSubFlow_W	2553
#define Attr_UROM_SubProductVersion_W	2554
#define Attr_UROM_WarningTemperature_W	2555
#define Attr_UROM_PowerOffTemperature_W	2556
#define Attr_UROM_WLAN_DHCPEnable_W	2557
#define Attr_UROM_LAN_DHCPEnable_W	2558
#define Attr_UROM_DHCP_StaticIP_W	2559
#define Attr_UROM_HWPreoffsetBase_W	2560
#define Attr_UROM_YCombWiseType_W	2561
#define Attr_UROM_NetworkBand_W	2562
#define Attr_UROM_CofPGA_W	2563
#define Attr_UROM_TriggerThreshold_W	2564
#define Attr_UROM_NumberOfFramesDiscardedInSequenceAcquire_W	2565
#define Attr_UROM_AutoSleepIdleTime_W	2566
#define Attr_FROM_ProductNo	3001
#define Attr_FROM_MainVersion	3002
#define Attr_FROM_ReadVersion	3003
#define Attr_FROM_McuVersion	3004
#define Attr_FROM_ArmVersion	3005
#define Attr_FROM_KernelVersion	3006
#define Attr_FROM_ProtocolVersion	3007
#define Attr_FROM_MasterBuildTime	3008
#define Attr_FROM_SlaveBuildTime	3009
#define Attr_FROM_McuBuildTime	3010
#define Attr_FROM_RowPreDelayTime	3011
#define Attr_FROM_RowPostDelayTime	3012
#define Attr_FROM_IntegrateTime	3013
#define Attr_FROM_ZoomMode	3014
#define Attr_FROM_ExpEnable_SignalLevel	3015
#define Attr_FROM_SelfClearEnable	3016
#define Attr_FROM_SelfClearSpanTime	3017
#define Attr_FROM_SequenceIntervalTime	3018
#define Attr_FROM_TriggerMode	3019
#define Attr_FROM_DynamicFlag	3020
#define Attr_FROM_TubeReadyTime	3021
#define Attr_FROM_SequenceIntervalTime_HighPrecision	3022
#define Attr_FROM_SetDelayTime	3023
#define Attr_FROM_ExpWindowTime	3025
#define Attr_FROM_SyncExpTime	3027
#define Attr_FROM_SyncExpTime_HighPrecision	3028
#define Attr_FROM_VT	3029
#define Attr_FROM_PGA	3030
#define Attr_FROM_PrepCapMode	3032
#define Attr_FROM_SelfCapEnable	3033
#define Attr_FROM_FluroSync	3034
#define Attr_FROM_SrcPort	3035
#define Attr_FROM_SrcIP	3036
#define Attr_FROM_SrcMAC	3037
#define Attr_FROM_DestPort	3038
#define Attr_FROM_DestIP	3039
#define Attr_FROM_DestMAC	3040
#define Attr_FROM_SyncboxIP	3041
#define Attr_FROM_PreviewImgMode	3044
#define Attr_FROM_HWOffsetType	3045
#define Attr_FROM_AcquireDelayTime	3046
#define Attr_FROM_BinningMode	3047
#define Attr_FROM_ExpMode	3050
#define Attr_FROM_AecMainTime	3051
#define Attr_FROM_DynaOffsetGapTime	3052
#define Attr_FROM_DynaOffsetEnable	3053
#define Attr_FROM_ImagePktGapTime	3054
#define Attr_FROM_OutModeCapTrig	3069
#define Attr_FROM_HvgPrepOn	3055
#define Attr_FROM_HvgXRayEnable	3056
#define Attr_FROM_HvgXRayOn	3057
#define Attr_FROM_HvgXRaySyncOut	3058
#define Attr_FROM_HvgXRaySyncIn	3059
#define Attr_FROM_CbxBuildTime	3060
#define Attr_FROM_SubProductNo	3061
#define Attr_FROM_SerialNo	3062
#define Attr_FROM_ImageChType	3063
#define Attr_FROM_ImageChProtocol	3064
#define Attr_FROM_HWGainEnable	3065
#define Attr_FROM_ExpTimeValidPercent	3066
#define Attr_FROM_FreesyncCenterThreshold	3067
#define Attr_FROM_FreesyncEdgeThreshold	3068
#define Attr_FROM_FreesyncSubFlow	3070
#define Attr_FROM_AutoSleepIdleTime	3071
#define Attr_FROM_FSyncParalClearTimes	3072
#define Attr_FROM_FSyncFastScanCpvCycle	3073
#define Attr_FROM_FSyncTriggerCheckTimeout	3074
#define Attr_FROM_FSyncSegmentThreshold	3075
#define Attr_FROM_FSyncLineThreshold	3076
#define Attr_FROM_FSyncFalseTriggerUnresponseStageTime	3077
#define Attr_FROM_FSyncParalClearLine	3078
#define Attr_FROM_PowSeriesCorrectEnable	3079
#define Attr_FROM_PulseClearTimes	3080
#define Attr_FROM_ROIColStartPos	3081
#define Attr_FROM_ROIColEndPos	3082
#define Attr_FROM_ROIRowStartPos	3083
#define Attr_FROM_ROIRowEndPos	3084
#define Attr_FROM_FullWell	3085
#define Attr_FROM_InnerSubFlow	3086
#define Attr_FROM_SoftwareSubFlow	3087
#define Attr_FROM_LowPowerWarnThreshold	3088
#define Attr_FROM_ShutDownWarnThreshold	3089
#define Attr_FROM_MainMBCpuVersion	3090
#define Attr_FROM_MainMBCpuBuildTime	3091
#define Attr_FROM_CofPGA	3092
#define Attr_FROM_XCombWiseType	3093
#define Attr_FROM_YCombWiseType	3094
#define Attr_FROM_WarningTemperature	3095
#define Attr_FROM_PowerOffTemperature	3096
#define Attr_FROM_HWPreoffsetBase	3097
#define Attr_FROM_WLAN_DHCPEnable	3098
#define Attr_FROM_LAN_DHCPEnable	3099
#define Attr_FROM_AutoWakeUpTime	3100
#define Attr_FROM_AutoPowerOffTimeOut	3101
#define Attr_FROM_ProtocolEditionVersion	3102
#define Attr_FROM_SubProductVersion	3103
#define Attr_FROM_NetworkBand	3104
#define Attr_FROM_TriggerThreshold	3105
#define Attr_FROM_NumberOfFramesDiscardedInSequenceAcquire	3106
#define Attr_FROM_Debug1	3200
#define Attr_FROM_Debug2	3201
#define Attr_FROM_Debug3	3202
#define Attr_FROM_Debug4	3203
#define Attr_FROM_Debug5	3204
#define Attr_FROM_Debug6	3205
#define Attr_FROM_Debug7	3206
#define Attr_FROM_Debug8	3207
#define Attr_FROM_Debug9	3208
#define Attr_FROM_Debug10	3209
#define Attr_FROM_Debug11	3210
#define Attr_FROM_Debug12	3211
#define Attr_FROM_Debug13	3212
#define Attr_FROM_Debug14	3213
#define Attr_FROM_Debug15	3214
#define Attr_FROM_Debug16	3215
#define Attr_FROM_Debug17	3216
#define Attr_FROM_Debug18	3217
#define Attr_FROM_Debug19	3218
#define Attr_FROM_Debug20	3219
#define Attr_FROM_Debug21	3220
#define Attr_FROM_Debug22	3221
#define Attr_FROM_Debug23	3222
#define Attr_FROM_Debug24	3223
#define Attr_FROM_Debug25	3224
#define Attr_FROM_Debug26	3225
#define Attr_FROM_Debug27	3226
#define Attr_FROM_Debug28	3227
#define Attr_FROM_Debug29	3228
#define Attr_FROM_Debug30	3229
#define Attr_FROM_Debug31	3230
#define Attr_FROM_Debug32	3231
#define Attr_FROM_Test1	3232
#define Attr_FROM_Test2	3233
#define Attr_FROM_Test3	3234
#define Attr_FROM_Test4	3235
#define Attr_FROM_Test5	3236
#define Attr_FROM_Test6	3237
#define Attr_FROM_Test7	3238
#define Attr_FROM_Test8	3239
#define Attr_FROM_Test9	3240
#define Attr_FROM_Test10	3241
#define Attr_FROM_Test11	3242
#define Attr_FROM_Test12	3243
#define Attr_FROM_Test13	3244
#define Attr_FROM_Test14	3245
#define Attr_FROM_Test15	3246
#define Attr_FROM_Test16	3247
#define Attr_FROM_ShockMcuVersion	3248
#define Attr_FROM_ShockMcuBuildTime	3249
#define Attr_FROM_ProductConfigCode	3250
#define Attr_FROM_RowPreDelayTime_W	3511
#define Attr_FROM_RowPostDelayTime_W	3512
#define Attr_FROM_IntegrateTime_W	3513
#define Attr_FROM_ZoomMode_W	3514
#define Attr_FROM_ExpEnable_SignalLevel_W	3515
#define Attr_FROM_SelfClearEnable_W	3516
#define Attr_FROM_SelfClearSpanTime_W	3517
#define Attr_FROM_SequenceIntervalTime_W	3518
#define Attr_FROM_TriggerMode_W	3519
#define Attr_FROM_DynamicFlag_W	3520
#define Attr_FROM_TubeReadyTime_W	3521
#define Attr_FROM_SequenceIntervalTime_HighPrecision_W	3522
#define Attr_FROM_SetDelayTime_W	3523
#define Attr_FROM_ExpWindowTime_W	3525
#define Attr_FROM_VT_W	3529
#define Attr_FROM_PGA_W	3530
#define Attr_FROM_PrepCapMode_W	3532
#define Attr_FROM_SelfCapEnable_W	3533
#define Attr_FROM_FluroSync_W	3534
#define Attr_FROM_SrcIP_W	3536
#define Attr_FROM_SrcMAC_W	3537
#define Attr_FROM_DestPort_W	3538
#define Attr_FROM_DestIP_W	3539
#define Attr_FROM_DestMAC_W	3540
#define Attr_FROM_SyncboxIP_W	3541
#define Attr_FROM_PreviewImgMode_W	3544
#define Attr_FROM_HWOffsetType_W	3545
#define Attr_FROM_AcquireDelayTime_W	3546
#define Attr_FROM_BinningMode_W	3547
#define Attr_FROM_ExpMode_W	3550
#define Attr_FROM_AecMainTime_W	3551
#define Attr_FROM_DynaOffsetGapTime_W	3552
#define Attr_FROM_DynaOffsetEnable_W	3553
#define Attr_FROM_ImagePktGapTime_W	3554
#define Attr_FROM_OutModeCapTrig_W	3569
#define Attr_FROM_HvgPrepOn_W	3555
#define Attr_FROM_HvgXRayEnable_W	3556
#define Attr_FROM_HvgXRayOn_W	3557
#define Attr_FROM_HvgXRaySyncOut_W	3558
#define Attr_FROM_HvgXRaySyncIn_W	3559
#define Attr_FROM_CbxBuildTime_W	3560
#define Attr_FROM_SubProductNo_W	3561
#define Attr_FROM_SerialNo_W	3562
#define Attr_FROM_ImageChType_W	3563
#define Attr_FROM_ImageChProtocol_W	3564
#define Attr_FROM_HWGainEnable_W	3565
#define Attr_FROM_ExpTimeValidPercent_W	3566
#define Attr_FROM_FreesyncCenterThreshold_W	3567
#define Attr_FROM_FreesyncEdgeThreshold_W	3568
#define Attr_FROM_FreesyncSubFlow_W	3570
#define Attr_FROM_AutoSleepIdleTime_W	3571
#define Attr_FROM_FSyncParalClearTimes_W	3572
#define Attr_FROM_FSyncFastScanCpvCycle_W	3573
#define Attr_FROM_FSyncTriggerCheckTimeout_W	3574
#define Attr_FROM_FSyncSegmentThreshold_W	3575
#define Attr_FROM_FSyncLineThreshold_W	3576
#define Attr_FROM_FSyncFalseTriggerUnresponseStageTime_W	3577
#define Attr_FROM_FSyncParalClearLine_W	3578
#define Attr_FROM_PowSeriesCorrectEnable_W	3579
#define Attr_FROM_PulseClearTimes_W	3580
#define Attr_FROM_ROIColStartPos_W	3581
#define Attr_FROM_ROIColEndPos_W	3582
#define Attr_FROM_ROIRowStartPos_W	3583
#define Attr_FROM_ROIRowEndPos_W	3584
#define Attr_FROM_FullWell_W	3585
#define Attr_FROM_InnerSubFlow_W	3586
#define Attr_FROM_SoftwareSubFlow_W	3587
#define Attr_FROM_LowPowerWarnThreshold_W	3588
#define Attr_FROM_ShutDownWarnThreshold_W	3589
#define Attr_FROM_CofPGA_W	3590
#define Attr_FROM_XCombWiseType_W	3591
#define Attr_FROM_YCombWiseType_W	3592
#define Attr_FROM_WarningTemperature_W	3593
#define Attr_FROM_PowerOffTemperature_W	3594
#define Attr_FROM_HWPreoffsetBase_W	3595
#define Attr_FROM_WLAN_DHCPEnable_W	3596
#define Attr_FROM_LAN_DHCPEnable_W	3597
#define Attr_FROM_AutoWakeUpTime_W	3598
#define Attr_FROM_AutoPowerOffTimeOut_W	3599
#define Attr_FROM_NetworkBand_W	3600
#define Attr_FROM_TriggerThreshold_W	3601
#define Attr_FROM_NumberOfFramesDiscardedInSequenceAcquire_W	3602
#define Attr_FROM_Debug1_W	3700
#define Attr_FROM_Debug2_W	3701
#define Attr_FROM_Debug3_W	3702
#define Attr_FROM_Debug4_W	3703
#define Attr_FROM_Debug5_W	3704
#define Attr_FROM_Debug6_W	3705
#define Attr_FROM_Debug7_W	3706
#define Attr_FROM_Debug8_W	3707
#define Attr_FROM_Debug9_W	3708
#define Attr_FROM_Debug10_W	3709
#define Attr_FROM_Debug11_W	3710
#define Attr_FROM_Debug12_W	3711
#define Attr_FROM_Debug13_W	3712
#define Attr_FROM_Debug14_W	3713
#define Attr_FROM_Debug15_W	3714
#define Attr_FROM_Debug16_W	3715
#define Attr_FROM_Debug17_W	3716
#define Attr_FROM_Debug18_W	3717
#define Attr_FROM_Debug19_W	3718
#define Attr_FROM_Debug20_W	3719
#define Attr_FROM_Debug21_W	3720
#define Attr_FROM_Debug22_W	3721
#define Attr_FROM_Debug23_W	3722
#define Attr_FROM_Debug24_W	3723
#define Attr_FROM_Debug25_W	3724
#define Attr_FROM_Debug26_W	3725
#define Attr_FROM_Debug27_W	3726
#define Attr_FROM_Debug28_W	3727
#define Attr_FROM_Debug29_W	3728
#define Attr_FROM_Debug30_W	3729
#define Attr_FROM_Debug31_W	3730
#define Attr_FROM_Debug32_W	3731
#define Attr_FROM_Test1_W	3732
#define Attr_FROM_Test2_W	3733
#define Attr_FROM_Test3_W	3734
#define Attr_FROM_Test4_W	3735
#define Attr_FROM_Test5_W	3736
#define Attr_FROM_Test6_W	3737
#define Attr_FROM_Test7_W	3738
#define Attr_FROM_Test8_W	3739
#define Attr_FROM_Test9_W	3740
#define Attr_FROM_Test10_W	3741
#define Attr_FROM_Test11_W	3742
#define Attr_FROM_Test12_W	3743
#define Attr_FROM_Test13_W	3744
#define Attr_FROM_Test14_W	3745
#define Attr_FROM_Test15_W	3746
#define Attr_FROM_Test16_W	3747
#define Attr_FROM_ProductConfigCode_W	3748
#define Attr_Wifi_AP_SSID	4001
#define Attr_Wifi_AP_Key	4002
#define Attr_Wifi_AP_CountryCode	4003
#define Attr_Wifi_AP_FrequencySel	4004
#define Attr_Wifi_AP_BandWidthSel	4005
#define Attr_Wifi_AP_ChannelSel	4006
#define Attr_Wifi_AP_SecuritySel	4007
#define Attr_Wifi_AP_ApModeEn	4008
#define Attr_Wifi_AP_DhcpServerEn	4009
#define Attr_Wifi_Client_ListNum	4010
#define Attr_Wifi_Client_CurrentSel	4011
#define Attr_Wifi_Client_SSID0	4012
#define Attr_Wifi_Client_Key0	4013
#define Attr_Wifi_Client_SSID1	4014
#define Attr_Wifi_Client_Key1	4015
#define Attr_Wifi_Client_SSID2	4016
#define Attr_Wifi_Client_Key2	4017
#define Attr_Wifi_Client_SSID3	4018
#define Attr_Wifi_Client_Key3	4019
#define Attr_Wifi_Client_SSID4	4020
#define Attr_Wifi_Client_Key4	4021
#define Attr_Wifi_Client_SSID5	4022
#define Attr_Wifi_Client_Key5	4023
#define Attr_Wifi_Client_SSID6	4024
#define Attr_Wifi_Client_Key6	4025
#define Attr_Wifi_Client_SSID7	4026
#define Attr_Wifi_Client_Key7	4027
#define Attr_Wifi_Client_SSID8	4028
#define Attr_Wifi_Client_Key8	4029
#define Attr_Wifi_Client_SSID9	4030
#define Attr_Wifi_Client_Key9	4031
#define Attr_Wifi_AP_CountryCode_ByLetter	4032
#define Attr_Wifi_AP_SSID_W	4501
#define Attr_Wifi_AP_Key_W	4502
#define Attr_Wifi_AP_CountryCode_W	4503
#define Attr_Wifi_AP_FrequencySel_W	4504
#define Attr_Wifi_AP_BandWidthSel_W	4505
#define Attr_Wifi_AP_ChannelSel_W	4506
#define Attr_Wifi_AP_SecuritySel_W	4507
#define Attr_Wifi_AP_ApModeEn_W	4508
#define Attr_Wifi_AP_DhcpServerEn_W	4509
#define Attr_Wifi_Client_ListNum_W	4510
#define Attr_Wifi_Client_CurrentSel_W	4511
#define Attr_Wifi_Client_SSID0_W	4512
#define Attr_Wifi_Client_Key0_W	4513
#define Attr_Wifi_Client_SSID1_W	4514
#define Attr_Wifi_Client_Key1_W	4515
#define Attr_Wifi_Client_SSID2_W	4516
#define Attr_Wifi_Client_Key2_W	4517
#define Attr_Wifi_Client_SSID3_W	4518
#define Attr_Wifi_Client_Key3_W	4519
#define Attr_Wifi_Client_SSID4_W	4520
#define Attr_Wifi_Client_Key4_W	4521
#define Attr_Wifi_Client_SSID5_W	4522
#define Attr_Wifi_Client_Key5_W	4523
#define Attr_Wifi_Client_SSID6_W	4524
#define Attr_Wifi_Client_Key6_W	4525
#define Attr_Wifi_Client_SSID7_W	4526
#define Attr_Wifi_Client_Key7_W	4527
#define Attr_Wifi_Client_SSID8_W	4528
#define Attr_Wifi_Client_Key8_W	4529
#define Attr_Wifi_Client_SSID9_W	4530
#define Attr_Wifi_Client_Key9_W	4531
#define Attr_Wifi_AP_CountryCode_ByLetter_W	4532
#define Attr_WorkDir	5001
#define Attr_State	5002
#define Attr_ConnState	5003
#define Attr_CurrentTask	5004
#define Attr_CurrentTransaction	5005
#define Attr_FsmState	5006
#define Attr_Width	5007
#define Attr_Height	5008
#define Attr_PrevImg_Width	5009
#define Attr_PrevImg_Height	5010
#define Attr_Authority	5011
#define Attr_ConnState_CmdCh	5012
#define Attr_ConnState_ImgCh	5013
#define Attr_ElapsedExpWindowTime	5014
#define Attr_FWUpdateProgress	5015
#define Attr_ImageTransProgress	5016
#define Attr_RdResult_T1	5017
#define Attr_RdResult_T2	5018
#define Attr_RdResult_Humidity	5019
#define Attr_RdResult_Shock_Threshold	5020
#define Attr_CurrentSubset	5021
#define Attr_CurrentCorrectOption	5022
#define Attr_OffsetValidityState	5023
#define Attr_GainValidityState	5024
#define Attr_DefectValidityState	5025
#define Attr_LagValidityState	5026
#define Attr_GhostValidityState	5027
#define Attr_OffsetTotalFrames	5028
#define Attr_OffsetValidFrames	5029
#define Attr_GainTotalFrames	5030
#define Attr_GainValidFrames	5031
#define Attr_DefectTotalFrames	5032
#define Attr_DefectValidFrames	5033
#define Attr_LagTotalFrames	5034
#define Attr_LagValidFrames	5035
#define Attr_Battery_Exist	5036
#define Attr_Battery_Remaining	5037
#define Attr_Battery_ChargingStatus	5038
#define Attr_Battery_PowerWarnStatus	5039
#define Attr_Battery_FullChargeCapacity	5067
#define Attr_Battery_DesignCapacity	5068
#define Attr_Battery_CycleCount	5069
#define Attr_Battery_Temperature	5070
#define Attr_Battery_RelativeStateOfCharge	5071
#define Attr_Battery_AbsoluteStateOfCharge	5072
#define Attr_Battery_RemainingCapacity	5073
#define Attr_Battery_Manufacture	5074
#define Attr_Battery_SN	5075
#define Attr_Battery_DeviceName	5076
#define Attr_HallSensorValue	5077
#define Attr_NetworkInterface	5040
#define Attr_WifiStatu_LinkedAP	5041
#define Attr_WifiStatu_WorkingBand	5042
#define Attr_WifiStatu_WorkingSignalIntensity	5043
#define Attr_WifiStatu_WorkingLinkQuality	5044
#define Attr_WifiStatu_WorkingTxPower	5045
#define Attr_HwTmpl_Offset_Enable	5046
#define Attr_HwTmpl_Offset_ValidIndex	5047
#define Attr_HwTmpl_Offset_FileCount	5048
#define Attr_HwTmpl_Gain_Enable	5049
#define Attr_HwTmpl_Gain_ValidIndex	5050
#define Attr_HwTmpl_Gain_FileCount	5051
#define Attr_HwTmpl_MostGain_Enable	5052
#define Attr_HwTmpl_MostGain_ValidIndex	5053
#define Attr_HwTmpl_MostGain_FileCount	5054
#define Attr_HwTmpl_Defect_Enable	5055
#define Attr_HwTmpl_Defect_ValidIndex	5056
#define Attr_HwTmpl_Defect_FileCount	5057
#define Attr_HwTmpl_Lag_Enable	5058
#define Attr_HwTmpl_Lag_ValidIndex	5059
#define Attr_HwTmpl_Lag_FileCount	5060
#define Attr_CorrectionPrepared	5061
#define Attr_RdResult_OutExpState	5062
#define Attr_RdResult_AutoSleepState	5063
#define Attr_Battery_ExternalPower	5064
#define Attr_GCU_OnlineState	5065
#define Attr_ClippingValue	5066
#define Attr_FD_LifeTime	5078
#define Attr_FD_PowerOnCount	5079
#define Attr_FD_PowerOffCount	5080
#define Attr_WifiInfo_WirelessAPMAC	5081
#define Attr_WifiInfo_WirelessClientMAC	5082
#define Attr_Temperature_State	5083
#define Attr_RdResult_RiskA_Shock_Threshold	5084
#define Attr_RdResult_RiskB_Shock_Threshold	5085
#define Attr_RdResult_RiskC_Shock_Threshold	5086
#define Attr_RdResult_RiskB2A_Shock_Threshold	5087
#define Attr_RdResult_RiskC2B_Shock_Threshold	5088
#define Attr_RdResult_RiskD2C_Shock_Threshold	5089
#define Attr_MultiGainPointNumber	5090
#define Attr_Network_LAN_IP_Addr	5300
#define Attr_Network_WLAN_IP_Addr	5301
#define Attr_Network_WLAN_DHCPEnable	5498
#define Attr_Network_LAN_DHCPEnable	5499
#define Attr_Network_LAN_IP_Addr_W	5500
#define Attr_Network_WLAN_IP_Addr_W	5501
#define Attr_Network_WLAN_DHCPEnable_W	5698
#define Attr_Network_LAN_DHCPEnable_W	5699
#define Attr_TransactionProgress	5700

#endif
