//
//  NHNCloudPush+SDK.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "NHNCloudPushConfiguration.h"
#import "NHNCloudPushAgreement.h"
#import "NHNCloudPushTokenInfo.h"
#import "NHNCloudPushMessage.h"
#import "NHNCloudPushNotificationAction.h"
#import "NHNCloudPushTenant.h"
#import "NHNCloudNotificationOptions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudPushDelegate
 
 Delegate to receive notifications.
 */
@protocol NHNCloudPushDelegate <NSObject>

@optional

// 알림 수신
/**
 Delegate the receiving notification.
 
 @param message The received notification's message.
 */
- (void)didReceiveNotificationWithMessage:(NHNCloudPushMessage *)message
NS_SWIFT_NAME(didReceiveNotification(message:));

// 알림 실행
/**
 Delegate the receiving notification's response.
 
 @param message The message for notification that have received response.
 */
- (void)didReceiveNotificationResponseWithMessage:(NHNCloudPushMessage *)message
NS_SWIFT_NAME(didReceiveNotificationResponse(message:));


// 알림 버튼 액션 수신
/**
 Delegate the receiving notification action.
 
 @param action The received notification action.
 */
- (void)didReceiveNotificationAction:(NHNCloudPushNotificationAction *)action
NS_SWIFT_NAME(didReceiveNotificationAction(action:));

@end


/**
 # ToastPush
 
 SDK to manage remote notifications. (APNS)
 */
@interface NHNCloudPush : NSObject

/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Set the delegate for receiving notification.

 @param delegate The delegate.
*/
+ (void)setDelegate:(nullable id<NHNCloudPushDelegate>)delegate
NS_SWIFT_NAME(setDelegate(_:));

/**
 Initialize SDK
 
 @param configuration The configuration.
*/
+ (void)initWithConfiguration:(NHNCloudPushConfiguration *)configuration
NS_SWIFT_NAME(initialize(configuration:));

/**
 Initialize SDK

 @param configuration The configuration.
 @param delegate The delegate.
 */
+ (void)initWithConfiguration:(NHNCloudPushConfiguration *)configuration
                     delegate:(nullable id<NHNCloudPushDelegate>)delegate
NS_SWIFT_NAME(initialize(configuration:delegate:));

/// ---------------------------------
/// @name Push Methods
/// ---------------------------------

// 토큰 조회
/**
 Queries the token's information.
 
 Queries last registered token's information on the current device.
 
 @param completionHandler The completion handler for result.
 */
+ (void)queryTokenInfoWithCompletionHandler:(void (^)(NHNCloudPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(queryTokenInfo(completion:));


// 토큰 등록
/**
 Register the token with agreement.
 
 Register the remote notification with APNS and register the received device token to the nhn cloud server.
 
 @param agreement Whether or not to accept the notifications.
 @param completionHandler The completion handler for result.
 */
+ (void)registerWithAgreement:(NHNCloudPushAgreement *)agreement
            completionHandler:(nullable void (^)(NHNCloudPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(agreement:completion:));

/**
Register the token.

Register the remote notification with APNS and if the received device token is already registered with the nhn cloud server, update the token's information with current configuration.

@param completionHandler The completion handler for result.
*/
+ (void)registerWithCompletionHandler:(nullable void (^)(NHNCloudPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(completion:));

// 토큰 삭제
/**
 Unregister the token.
 
 Unregister the token on the current device from the nhn cloud server.
 
 @param completionHandler The completion handler for result.
 */
+ (void)unregisterWithCompletionHandler:(nullable void (^)(NSString * _Nullable deviceToken, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(unregister(completion:));

// 알림 옵션 설정
/**
Set the notification options.

Register notification options in the notification center.

@param options Set of notification options
*/
+ (void)setNotificationOptions:(nullable NHNCloudNotificationOptions *)options
NS_SWIFT_NAME(setNotificationOptions(_:));

/**
Get the notification options.

Returns registered notification options in the notification center.
*/
+ (nullable NHNCloudNotificationOptions *)notificationOptions
NS_SWIFT_NAME(notificationOptions());

// 알림 카테고리 설정
/**
Set the notification categories.

Register notification categories in the notification center.

@param categories Set of notification categories
*/
+ (void)setNotificationCategories:(NSSet<UNNotificationCategory *> *)categories API_AVAILABLE(ios(10.0))
NS_SWIFT_NAME(setNotificationCategories(_:));

// 알림 카테고리 획득
/**
Get the notifications categories.

Get the notification categories registered in the notification center.

@param completionHandler The completion handler for result.
*/
+ (void)getNotificationCategoriesWithCompletionHandler:(void (^)(NSSet<UNNotificationCategory *> *categories))completionHandler API_AVAILABLE(ios(10.0))
NS_SWIFT_NAME(getNotificationCategories(completion:));

// iOS 10 미만의 단말기에서는 UIUserNotificationCategory를 사용
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_10_0
+ (void)setUserNotificationCategories:(NSSet<UIUserNotificationCategory *> *)categories
NS_SWIFT_NAME(setUserNotificationCategories(_:));

+ (void)getUserNotificationCategoriesWithCompletionHandler:(void (^)(NSSet<UIUserNotificationCategory *> * _Nullable categories))completionHandler
NS_SWIFT_NAME(getUserNotificationCategories(completion:));
#endif

// Tenant 설정
/**
Set tenant information.

@param tenant The tenant information.
*/
+ (void)setTenant:(nullable NHNCloudPushTenant *)tenant;

// User Tag 설정
/**
Get user tag.

@param completionHandler The completion handler for result.
*/
+ (void)getUserTagWithCompletionHandler:(void (^)(NSSet<NSString *> * _Nullable tagIdentifiers, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(getUserTag(completion:));

/**
Add tag identifiers to user tag.

@param tagIdentifiers The tag identifiers.
@param completionHandler The completion handler for result.
*/
+ (void)addUserTagWithIdentifiers:(NSSet<NSString *> *)tagIdentifiers
                completionHandler:(nullable void (^)(NSSet<NSString *> * _Nullable tagIdentifiers, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(addUserTag(_:completion:));

/**
Set tag identifiers to user tag.

@param tagIdentifiers The tag identifiers.
@param completionHandler The completion handler for result.
*/
+ (void)setUserTagWithIdentifiers:(nullable NSSet<NSString *> *)tagIdentifiers
                completionHandler:(nullable void (^)(NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(setUserTag(_:completion:));

/**
Remove tag identifiers from the user tag.

@param tagIdentifiers The tag identifiers.
@param completionHandler The completion handler for result.
*/
+ (void)removeUserTagWithIdentifiers:(NSSet<NSString *> *)tagIdentifiers
                   completionHandler:(nullable void (^)(NSSet<NSString *> * _Nullable tagIdentifiers, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(removeUserTag(_:completion:));

/**
Remove all user tag.

@param completionHandler The completion handler for result.
*/
+ (void)removeAllUserTagWithCompletionHandler:(nullable void (^)(NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(removeAllUserTag(completion:));

// SDK 버전 획득
/**
 Gets the version of SDK.
 
 @return The version.
 */
+ (NSString *)version
NS_SWIFT_NAME(version());

@end

NS_ASSUME_NONNULL_END

