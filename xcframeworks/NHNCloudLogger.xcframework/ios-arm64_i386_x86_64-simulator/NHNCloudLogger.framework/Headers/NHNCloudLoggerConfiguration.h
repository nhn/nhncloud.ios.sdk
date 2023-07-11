//
//  NHNCloudLoggerConfiguration.h
//  NHNCloudLogger
//
//  Created by JooHyun Lee on 07/03/2019.
//  Copyright © 2019 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NHNCloudCore/NHNCloudCore.h>
#import "NHNCloudLoggerConfigurationSetting.h"

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudLoggerConfiguration
 
 The configuration used to initialize the NHNCloudLogger SDK.
 */
@interface NHNCloudLoggerConfiguration : NSObject

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Log & Crasyh Search app key on the nhn cloud console */
@property (nonatomic, copy, readonly) NSString *appKey;

/** configuration setting about nhn cloud Logger */
@property (nonatomic, copy, readonly) NHNCloudLoggerConfigurationSetting *setting;

/** Whether or not sending crash is enabled. */
@property (nonatomic) BOOL enableCrashReporter;

/** NHN Cloud service zone(Real or Alpha) */
@property (nonatomic) NHNCloudServiceZone serviceZone;

/** NHN Cloud Environment (Public or Government) */
@property (nonatomic) NHNCloudEnvironment cloudEnvironment;

/**
 Initialize a configuration with the given appKey.

 @param appKey AppKey on the nhn cloud console
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (nullable instancetype)configurationWithAppKey:(NSString *)appKey;

/**
 Initialize a configuration with the given appKey and enableCrashReport.

 @param appKey AppKey on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (nullable instancetype)configurationWithAppKey:(NSString *)appKey
                             enableCrashReporter:(BOOL)enableCrashReporter;

/**
 Initialize a configuration with the given appKey, enableCrashReport and setting.

 @param appKey AppKey on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param setting configuration setting about NHN Cloud Logger
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (nullable instancetype)configurationWithAppKey:(NSString *)appKey
                             enableCrashReporter:(BOOL)enableCrashReporter
                                         setting:(nullable NHNCloudLoggerConfigurationSetting *)setting;

/**
 Initialize a configuration with the given appKey.
 
 @param appKey AppKey on the nhn cloud console
 @return A instance of NHNCloudLoggerConfiguration
 */
- (nullable instancetype)initWithAppKey:(NSString *)appKey;

/**
 Initialize a configuration with the given appKey and enableCrashReport.
 
 @param appKey AppKey on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @return A instance of NHNCloudLoggerConfiguration
 */
- (nullable instancetype)initWithAppKey:(NSString *)appKey
                    enableCrashReporter:(BOOL)enableCrashReporter;

/**
 Initialize a configuration with the given appKey, enableCrashReport and setting.
 
 @param appKey AppKey on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param setting configuration setting about NHN Cloud Logger
 @return A instance of NHNCloudLoggerConfiguration
 */
- (nullable instancetype)initWithAppKey:(NSString *)appKey
                    enableCrashReporter:(BOOL)enableCrashReporter
                                setting:(nullable NHNCloudLoggerConfigurationSetting *)setting;

@end

NS_ASSUME_NONNULL_END
