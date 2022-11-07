//
//  NHNCloudLoggerConfiguration+Deprecated.h
//  NHNCloudLogger
//
//  Created by JooHyun Lee on 07/03/2019.
//  Copyright © 2019 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudLoggerConfiguration.h"

@interface NHNCloudLoggerConfiguration (Deprecated)

/** Log & Crasyh Search project key on the nhn cloud console */
@property (strong, nonatomic, readonly) NSString *projectKey __deprecated_msg("use appKey instead.");

/**
 Initialize a configuration with the given projectKey.
 
 @param projectKey Project key on the nhn cloud console
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey __deprecated_msg("use configurationWithAppKey: instead.");

/**
 Initialize a configuration with the given projectKey and enableCrashReport.
 
 @param projectKey Project key on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter __deprecated_msg("use configurationWithAppKey:enableCrashReporter: instead.");

/**
 Initialize a configuration with the given projectKey, enableCrashReport and setting.
 
 @param projectKey Project key on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param setting configuration setting about NHN Cloud Logger
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                    setting:(NHNCloudLoggerConfigurationSetting *)setting __deprecated_msg("use configurationWithAppKey:enableCrashReporter:setting: instead.");

/**
 Initialize a configuration with the given projectKey, enableCrashReport and serviceZone.
 
 @param projectKey Project key on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param serviceZone service zone of the nhn cloud console
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                serviceZone:(NHNCloudServiceZone)serviceZone __deprecated_msg("use configurationWithAppKey:enableCrashReporter:serviceZone: instead.");

/**
 Initialize a configuration with the given projectKey, enableCrashReport, setting and serviceZone.
 
 @param projectKey Project key on the nhn cloud console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param setting configuration setting about NHN Cloud Logger
 @param serviceZone service zone of the nhn cloud console
 @return A instance of NHNCloudLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                    setting:(NHNCloudLoggerConfigurationSetting *)setting
                                serviceZone:(NHNCloudServiceZone)serviceZone __deprecated_msg("use configurationWithAppKey:enableCrashReporter:setting:serviceZone: instead.");

#pragma mark - ServiceZone
/// ---------------------------------
/// @name Set & Get service zone
/// ---------------------------------

/**
 Sets service zone of the nhn cloud console.
 
 @param serviceZone service zone of the nhn cloud console.(Real or Alpha or Beta)
 */
- (void)setLoggerServiceZone:(NHNCloudServiceZone)serviceZone __deprecated_msg("use setServiceZone: instead.");

/**
 Gets service zone of the nhn cloud console.
 
 @return service zone of the nhn cloud console.(Real or Alpha or Beta)
 */
- (NHNCloudServiceZone)loggerServiceZone __deprecated_msg("use serviceZone instead.");

@end
