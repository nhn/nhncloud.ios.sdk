//
//  NHNCloudMobillConfig.h
//  NHNCloudIAP
//
//  Created by NHN on 8/28/24.
//  Copyright © 2024 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudMobillConfig : NSObject

+ (void)setForceURL:(nullable NSString *)forceURL;
+ (nullable NSString *)forceURL;

@end

NS_ASSUME_NONNULL_END
