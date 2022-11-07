//
//  NHNCloudPushNotificationAction.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 25/06/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "NHNCloudPushMessage.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NHNCloudPushNotificationActionType) {
    NHNCloudPushNotificationActionDismiss  NS_SWIFT_NAME(dismiss) = 0,
    NHNCloudPushNotificationActionOpenApp  NS_SWIFT_NAME(openApp) = 1,
    NHNCloudPushNotificationActionOpenURL  NS_SWIFT_NAME(openURL) = 2,
    NHNCloudPushNotificationActionReply    NS_SWIFT_NAME(reply) = 3,
};

/**
# NHNCloudPushMessage

A class that has information about received message.
*/
@interface NHNCloudPushNotificationAction : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Identifier of notification action. */
@property (nonatomic, readonly) NSString *actionIdentifier;

/** Identifier of category that contains notification action. */
@property (nonatomic, readonly) NSString *categoryIdentifier;

/** Type of notification action. */
@property (nonatomic, readonly) NHNCloudPushNotificationActionType actionType;

/** Button's information of notification action. */
@property (nonatomic, readonly) NHNCloudPushButton *button;

/** Received push message of notification action. */
@property (nonatomic, readonly) NHNCloudPushMessage *message;

/** User input text for reply type action. */
@property (nonatomic, readonly, nullable) NSString *userText;

@end

NS_ASSUME_NONNULL_END
