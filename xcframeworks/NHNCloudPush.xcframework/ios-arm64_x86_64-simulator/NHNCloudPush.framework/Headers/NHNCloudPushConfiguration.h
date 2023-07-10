//
//  NHNCloudPushConfiguration.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NHNCloudCore/NHNCloudCore.h>

NS_ASSUME_NONNULL_BEGIN

/**
# NHNCloudPushConfiguration

A class that has configuration about push service required for initialization.
*/
@interface NHNCloudPushConfiguration : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** The app key of push service in your nhn cloud console project. */
@property (nonatomic, copy, readonly) NSString *appKey;

/** The nhn cloud service zone. (Real or Alpha or Beta)  */
@property (nonatomic) NHNCloudServiceZone serviceZone;

/** Country code (ISO 3166-1 alpha-2, ISO 3166-1 alpha-3) used for localized time when sending reservation message. */
@property (nonatomic, copy) NSString *countryCode;

/** Lanuage code (SO 639-1, ISO 639-2) used for multiple language message. */
@property (nonatomic, copy) NSString *languageCode;

/** A region of the globe that observes a uniform standard time for legal, commercial and social purposes. */
@property (nonatomic, copy) NSString *timezone;

/** Whther it is a sandbox environment or not. */
@property (nonatomic) BOOL sandbox;

/** Whether or not to register a token even if the user denies the permission. */
@property (nonatomic) BOOL alwaysAllowTokenRegistration;


/// ---------------------------------
/// @name Initializes
/// ---------------------------------

/**
 Initialize with push service app key.
 
 @param appKey The app key of push service in your nhn cloud console project.
 @return The instance of NHNCloudPushConfiguration.
 */
+ (instancetype)configurationWithAppKey:(NSString *)appKey;

/**
 Initialize with push service app key.

 @param appKey The app key of push service in your nhn cloud console project.
 @return The instance of NHNCloudPushConfiguration.
 */
- (instancetype)initWithAppKey:(NSString *)appKey
NS_SWIFT_NAME(init(appKey:));

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
