//
//  NHNCloudCommon.h
//  NHNCloudCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "NHNCloudInfoUtil.h"
#import "NHNCloudHttpManager.h"
#import "NHNCloudUtil.h"
#import "NHNCloudInfoUtil.h"
#import "NHNCloudFieldValidator.h"
#import "NHNCloudBlockQueue.h"
#import "NHNCloudStorageManager.h"
#import "NHNCloudNetworkManager.h"
#import "NHNCloudNetworkStatus.h"
#import "NHNCloudScheduleWorker.h"
#import "NHNCloudScheduleTask.h"
#import "NHNCloudTimeoutTask.h"
#import "NHNCloudAsyncTask.h"
#import "NHNCloudTaskQueue.h"
#import "NHNCloudArray.h"
#import "NHNCloudDictionary.h"
#import "NHNCloudCache.h"
#import "NHNCloudMemoryCache.h"
#import "NHNCloudFileCache.h"
#import "NHNCloudKeychainCache.h"
#import "NHNCloudPreferences.h"
#import "NHNCloudCameraManager.h"
#import "NHNCloudBlockQueueWorker.h"

//! Project version number for NHNCloudCommon.
FOUNDATION_EXPORT double NHNCloudCommonVersionNumber;

//! Project version string for NHNCloudCommon.
FOUNDATION_EXPORT const unsigned char NHNCloudCommonVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <NHNCloudCommon/PublicHeader.h>

typedef NHNCloudUtil ToastUtil __deprecated_msg("use NHNCloudUtil instead.");
typedef NHNCloudInfoUtil ToastInfoUtil __deprecated_msg("use NHNCloudInfoUtil instead.");
typedef NHNCloudHttpManager ToastHttpManager __deprecated_msg("use NHNCloudHttpManager instead.");
typedef NHNCloudArray ToastArray __deprecated_msg("use NHNCloudArray instead.");
typedef NHNCloudMutableArray ToastMutableArray __deprecated_msg("use NHNCloudMutableArray instead.");
typedef NHNCloudDictionary ToastDictionary __deprecated_msg("use NHNCloudDictionary instead.");
typedef NHNCloudMutableDictionary ToastMutableDictionary __deprecated_msg("use NHNCloudMutableDictionary instead.");
