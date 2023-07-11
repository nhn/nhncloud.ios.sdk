//
//  NHNCloudPushButton.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, NHNCloudPushButtonType) {
    NHNCloudPushButtonTypeDismiss  NS_SWIFT_NAME(dismiss) = 0,
    NHNCloudPushButtonTypeOpenApp  NS_SWIFT_NAME(openApp) = 1,
    NHNCloudPushButtonTypeOpenURL  NS_SWIFT_NAME(openURL) = 2,
    NHNCloudPushButtonTypeReply    NS_SWIFT_NAME(reply) = 3,
};

/**
# NHNCloudPushButton

A class that has information about notification button.
*/
@interface NHNCloudPushButton : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Identifier of button. */
@property (nonatomic, readonly) NSString *identifier;

/** Type of button. */
@property (nonatomic, readonly) NHNCloudPushButtonType buttonType;

/** String displayed on button. */
@property (nonatomic, readonly) NSString *name;

/** Link to be executed when a user responds to a button of OpenURL type. */
@property (nonatomic, readonly, nullable) NSString *link;

/** The placeholder string that appears in the user input ui on the button of Reply type. */
@property (nonatomic, readonly, nullable) NSString *hint;

/** String of the submit button thast appears on the button of Reply type. */
@property (nonatomic, readonly, nullable) NSString *submit;

@end

NS_ASSUME_NONNULL_END
