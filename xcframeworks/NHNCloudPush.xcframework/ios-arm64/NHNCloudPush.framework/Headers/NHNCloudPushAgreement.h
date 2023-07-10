//
//  NHNCloudPushAgreement.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 12. 12..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudPushAgreement
 
 A class that has the user's agreement as to whether or not to receive message.
 */
@interface NHNCloudPushAgreement : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Whether to accept the notification. */
@property (nonatomic) BOOL allowNotifications;

/** Whether to accept the advertising information notification. */
@property (nonatomic) BOOL allowAdvertisements;

/** Whether to accept the advertising information notification when night. */
@property (nonatomic) BOOL allowNightAdvertisements;

/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Initialize  NHNCloudPushAgreement with allowNotifications.
 
 @param allowNotifications  Whether to accept the notification.
 @return The instance of NHNCloudPushAgreement.
 */
+ (instancetype)agreementWithAllowNotifications:(BOOL)allowNotifications;


/**
 Initialize  NHNCloudPushAgreement with allowNotifications.

 @param allowNotifications  Whether to accept the notification.
 @return The instance of NHNCloudPushAgreement.
 */
- (instancetype)initWithAllowNotifications:(BOOL)allowNotifications
NS_SWIFT_NAME(init(allowNotifications:));

@end

NS_ASSUME_NONNULL_END
