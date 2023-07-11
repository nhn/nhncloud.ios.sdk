//
//  NHNCloudCore.h
//  NHNCloudCore
//
//  Created by Hyup on 2017. 9. 26..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "NHNCloudSDK.h"
#import "NHNCloudHttpError.h"

//! Project version number for NHNCloudCore.
FOUNDATION_EXPORT double NHNCloudCoreVersionNumber;

//! Project version string for NHNCloudCore.
FOUNDATION_EXPORT const unsigned char NHNCloudCoreVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <NHNCloudCore/PublicHeader.h>


typedef NS_ENUM(NSInteger, NHNCloudServiceZone) {
    NHNCloudServiceZoneReal, ToastServiceZoneReal __deprecated_msg("use NHNCloudServiceZoneReal instead.") = 0,
    NHNCloudServiceZoneAlpha, ToastServiceZoneAlpha __deprecated_msg("use NHNCloudServiceZoneAlpha instead.") = 1,
    NHNCloudServiceZoneBeta, ToastServiceZoneBeta __deprecated_msg("use NHNCloudServiceZoneBeta instead.") = 2,
};
typedef NHNCloudServiceZone ToastServiceZone __deprecated_msg("use NHNCloudServiceZone instead.");

typedef NS_ENUM(NSInteger, NHNCloudLogLevel) {
    NHNCloudLogLevel_DEBUG, ToastLogLevel_DEBUG __deprecated_msg("use NHNCloudLogLevel_DEBUG instead.") = 0,
    NHNCloudLogLevel_INFO, ToastLogLevel_INFO __deprecated_msg("use NHNCloudLogLevel_INFO instead.") = 1,
    NHNCloudLogLevel_WARN, ToastLogLevel_WARN __deprecated_msg("use NHNCloudLogLevel_WARN instead.") = 2,
    NHNCloudLogLevel_ERROR, ToastLogLevel_ERROR __deprecated_msg("use NHNCloudLogLevel_ERROR instead.") = 3,
    NHNCloudLogLevel_FATAL, ToastLogLevel_FATAL __deprecated_msg("use NHNCloudLogLevel_FATAL instead.") = 4,
};
typedef NHNCloudLogLevel ToastLogLevel __deprecated_msg("use NHNCloudLogLevel instead.");

typedef NS_ENUM(NSInteger, NHNCloudEnvironment) {
    NHNCloudEnvironmentPublic = 0,
    NHNCloudEnvironmentGovernment = 1,
};
