//
//  NHNCloudVoIP.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 21/10/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudPush.h"

NS_ASSUME_NONNULL_BEGIN

/**
# NHNCloudVoIPDelegate

Delegate to receive push messages.
*/
API_AVAILABLE(ios(10.0))
@protocol NHNCloudVoIPDelegate <NSObject>

// 메시지 수신
/**
 Delegate the receiving push message.
 
 @param message The received push message.
 */
- (void)didReceiveIncomingVoiceCallWithMessage:(NHNCloudPushMessage *)message
NS_SWIFT_NAME(didReceiveIncomingVoiceCall(message:));

@end

/**
# NHNCloudVoIP

SDK to manage push message for voip.
*/

API_AVAILABLE(ios(10.0))
@interface NHNCloudVoIP : NSObject

/**
 Set the delegate for receiving push message.

 @param delegate The delegate.
*/
+ (void)setDelegate:(nullable id<NHNCloudVoIPDelegate>)delegate
NS_SWIFT_NAME(setDelegate(_:));

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
 Request the token.
 
 Register the push registry with APNS and register the received device token to the nhn cloud server.
 
 @param completionHandler The completion handler for result.
 */
+ (void)registerWithCompletionHandler:(nullable void (^)(NHNCloudPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(completion:));

// 토큰 삭제
/**
 Unregister token.
 
 Unregister token on the current device from the nhn cloud server.
 
 @param completionHandler The completion handler for result.
 */
+ (void)unregisterWithCompletionHandler:(nullable void (^)(NSString * _Nullable deviceToken, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(unregister(completion:));

@end

NS_ASSUME_NONNULL_END
