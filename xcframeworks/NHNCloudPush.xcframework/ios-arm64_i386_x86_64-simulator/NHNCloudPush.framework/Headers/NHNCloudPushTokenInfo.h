//
//  NHNCloudPushTokenInfo.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudPushConfiguration.h"
#import "NHNCloudPushAgreement.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *NHNCloudPushType NS_STRING_ENUM;

/** When the type is APNs. */
extern NHNCloudPushType const NHNCloudPushTypeAPNS NS_SWIFT_NAME(apns);

/** When the type is VoIP. */
extern NHNCloudPushType const NHNCloudPushTypeVoIP NS_SWIFT_NAME(voip);


/**
# NHNCloudPushTokenInfo

A class that contains information about the registered token.
*/
@interface NHNCloudPushTokenInfo : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Identifier of user. */
@property (nonatomic, copy, readonly) NSString *userID;

/** Device token issued by APNs. */
@property (nonatomic, copy, readonly) NSString *deviceToken;

/** Country code (ISO 3166-1 alpha-2, ISO 3166-1 alpha-3) used for localized time when sending reservation message. */
@property (nonatomic, copy, readonly) NSString *countryCode;

/** Lanuage code (SO 639-1, ISO 639-2) used for multiple language message. */
@property (nonatomic, copy, readonly) NSString *languageCode;

/** Push type of device token. ( APNs or VoIP ) */
@property (nonatomic, copy, readonly) NHNCloudPushType pushType;

/** User agreement to receive push messages. */
@property (nonatomic, copy, readonly) NHNCloudPushAgreement *agreement;

/** A region of the globe that observes a uniform standard time for legal, commercial and social purposes. */
@property (nonatomic, copy, readonly) NSString *timezone;

/** Latest updated date and time. */
@property (nonatomic, copy, readonly) NSString *updateDateTime;

/** Is registered in sandbox environment */
@property (nonatomic, getter=isSandbox) BOOL sandbox;

@end

NS_ASSUME_NONNULL_END
