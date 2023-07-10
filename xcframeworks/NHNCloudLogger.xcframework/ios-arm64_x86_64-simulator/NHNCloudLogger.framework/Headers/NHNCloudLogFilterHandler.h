//
//  NHNCloudLogFilterHandler.h
//  NHNCloudLogger
//
//  Created by Hyup on 2017. 9. 18..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudLoggerConfiguration.h"
#import "NHNCloudLogFilter.h"

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudLogFilterHandler
 
 A class that manages to add NHNCloudLogFilter according to NHNCloudLoggerConfiguration.
 */
@interface NHNCloudLogFilterHandler : NSObject

/// ---------------------------------
/// @name Adding log filter
/// ---------------------------------

/**
 Add the log filter user want.

 @param logFilter The filter to add
 @param configuration The configuration about NHN Cloud Logger
 */
+ (void)addLogFilter:(nullable NHNCloudLogFilter *)logFilter withLoggerConfiguration:(nullable NHNCloudLoggerConfiguration *)configuration;

@end

NS_ASSUME_NONNULL_END
