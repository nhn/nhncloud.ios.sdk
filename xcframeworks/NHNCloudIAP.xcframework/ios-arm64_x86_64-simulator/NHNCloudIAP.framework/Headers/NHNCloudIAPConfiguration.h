//
//  NHNCloudIAPConfiguration.h
//  NHNCloudIAP
//
//  Created by Hyup on 2018. 9. 14..
//  Copyright © 2018년 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NHNCloudCore/NHNCloudCore.h>

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudIAPConfiguration
 
 Configuration for NHNCloudIAP SDK initialization.
 
 */
@interface NHNCloudIAPConfiguration : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** The app key of NHN Cloud Console Project Key */
@property (nonatomic, copy, readonly) NSString *appKey;

/** The service zone(Real or Alpha) */
@property (nonatomic) NHNCloudServiceZone serviceZone;

/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Initialize NHNCloudIAPConfiguration with a given app key.

 @param appKey The app key of NHN Cloud Console Project key
 @return The instance of NHNCloudIAPConfiguration
 */
+ (instancetype)configurationWithAppKey:(NSString *)appKey;

/**
 Initialize NHNCloudIAPConfiguration with a given appKey.
 
 @param appKey The app key of NHN Cloud Console Project key.
 @return The instance of NHNCloudIAPConfiguration.
 */
- (instancetype)initWithAppKey:(NSString *)appKey
NS_SWIFT_NAME(init(appKey:));

@end

NS_ASSUME_NONNULL_END
