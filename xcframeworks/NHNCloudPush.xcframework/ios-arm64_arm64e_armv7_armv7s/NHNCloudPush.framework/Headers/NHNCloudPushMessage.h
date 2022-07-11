//
//  NHNCloudPushMessage.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 25/06/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudPushStyle.h"
#import "NHNCloudPushRichMessage.h"

NS_ASSUME_NONNULL_BEGIN

/**
# NHNCloudPushMessage

A class that has information about received message.
*/
@interface NHNCloudPushMessage : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Identifier of push message. */
@property (nonatomic, readonly) NSString *identifier;

/** Title of push message. */
@property (nonatomic, readonly, nullable) NSString *title;

/** Body of push message. */
@property (nonatomic, readonly, nullable) NSString *body;

/** The number that will appear in the badge icon for the application. */
@property (nonatomic, readonly, nullable) NSNumber *badge;

/** Sound to play when notification is notified. */
@property (nonatomic, readonly, nullable) NSString *sound;

/** Action to be executed when a user responds to an notification. */
@property (nonatomic, readonly, nullable) NSString *clickAction;

/** Styles for notification. */
@property (nonatomic, readonly, nullable) NHNCloudPushStyle *style;

/** Information to generate rich message notification. */
@property (nonatomic, readonly, nullable) NHNCloudPushRichMessage *richMessage;

/** Payload received message. */
@property (nonatomic, readonly) NSDictionary *payload;

@end

NS_ASSUME_NONNULL_END
