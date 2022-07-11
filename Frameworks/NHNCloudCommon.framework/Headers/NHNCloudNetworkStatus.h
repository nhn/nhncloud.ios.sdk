//
//  NHNCloudNetworkStatus.h
//  NHNCloudCommon
//
//  Created by JooHyun Lee on 2018. 6. 29..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

typedef NS_ENUM(NSUInteger, NHNCloudNetworkType) {
    NHNCloudNetworkTypeNone,
    NHNCloudNetworkTypeWIFI,
    NHNCloudNetworkTypeWWAN,
};

@interface NHNCloudNetworkStatus : NSObject

@property (nonatomic, readonly, getter=isConnected) BOOL connected;
@property (nonatomic, readonly) NHNCloudNetworkType type;

@end
