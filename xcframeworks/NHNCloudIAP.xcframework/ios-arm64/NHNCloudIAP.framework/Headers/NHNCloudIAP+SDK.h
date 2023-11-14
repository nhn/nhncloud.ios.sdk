//
//  NHNCloudIAP+SDK.h
//  NHNCloudIAP
//
//  Created by Hyup on 2018. 9. 11..
//  Copyright © 2018년 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NHNCloudCore/NHNCloudCore.h>
#import "NHNCloudIAPConfiguration.h"
#import "NHNCloudProduct.h"
#import "NHNCloudProductsResponse.h"
#import "NHNCloudPurchaseResult.h"
#import "NHNCloudInAppPurchaseDelegate.h"

@protocol NHNCloudInAppPurchaseDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudIAP
 
 SDK to manage in-app-purchase
 
 ## Initialize Precautions
 * NHNCloudIAP SDK uses the UserID set in NHNCloudSDK.
 * After you set the UserID, you need to initialize the NHNCloudIAP Module.
 * At initialization, you must register the delegate to receive the payment result as mandatory.
 * After initialization, reprocessing for uncompleted payments and automatic renewal of Auto-Renewal Subscription occur.
 
 */
@interface NHNCloudIAP : NSObject

/// ---------------------------------
/// @name Set Delegate(NHNCloudInAppPurchaseDelegate)
/// ---------------------------------

/**
 Sets Delegate with a given delegate that following NHNCloudInAppPurchaseDelegate

 @param delegate The delegate that following NHNCloudInAppPurchaseDelegate
 */
+ (void)setDelegate:(nullable id<NHNCloudInAppPurchaseDelegate>)delegate
NS_SWIFT_NAME(setDelegate(_:));

/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Initialize SDK
 
 @param configuration The configuration about IAP
 */
+ (void)initWithConfiguration:(NHNCloudIAPConfiguration *)configuration
NS_SWIFT_NAME(initialize(configuration:));

/**
 Initialize SDK

 @param configuration The configuration about IAP
 @param delegate The delegate to be executed according to the purchase result.
 */
+ (void)initWithConfiguration:(NHNCloudIAPConfiguration *)configuration
                     delegate:(nullable id<NHNCloudInAppPurchaseDelegate>)delegate
NS_SWIFT_NAME(initialize(configuration:delegate:));

/// ---------------------------------
/// @name IAP Methods
/// ---------------------------------

// 상품 목록 조회
/**
 Gets the list of products registered in IAP Console.

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestProductsWithCompletionHandler:(nullable void (^)(NHNCloudProductsResponse * _Nullable response, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestProducts(completion:));

// 앱스토어 미소비 결제 내역 조회
/**
 Gets the list of products that have not been paid out of the purchased consumable items from the App Store.

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestConsumablePurchasesWithCompletionHandler:(nullable void (^)(NSArray<NHNCloudPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestConsumablePurchases(completion:));

// 전체 마켓 미소비 결제 내역 조회
/**
 Gets the list of products that have not been paid out of the purchased consumable items from all markets (App Store, Google, ONEStore...)

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestAllMarketsConsumablePurchasesWithCompletionHandler:(nullable void (^)(NSArray<NHNCloudPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestAllMarketsConsumablePurchases(completion:));

// 상품 구매
/**
 Purchase a product acquired through the request. The purchase result is returned to the delegate.

 @param product The product to purchase
 */
+ (void)purchaseWithProduct:(NHNCloudProduct *)product
NS_SWIFT_NAME(purchase(product:));

/**
 Purchase a product acquired through the request. The purchase result is returned to the delegate.
 
 @param product The product to purchase
 @param payload The developer's purchase payload
 */
+ (void)purchaseWithProduct:(NHNCloudProduct *)product payload:(nullable NSString *)payload
NS_SWIFT_NAME(purchase(product:payload:));

// 구매 복원
/**
 Restore auto-renewable subscription products.
 Restores the transaction of the AppStore's auto-renewable subscription product and returns a list of active subscription products.

 @param completionHandler The handler to execute after the restore is complete.
 */
+ (void)restoreWithCompletionHandler:(nullable void (^)(NSArray<NHNCloudPurchaseResult *> * _Nullable restoredPurchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(restore(completion:));

// 활성화된 구매 목록 조회 (Deprecated)
/**
 Gets a list of valid subscription items based on UserID, regardless of iOS or Android Store.

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestActivePurchasesWithCompletionHandler:(nullable void (^)(NSArray<NHNCloudPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestActivePurchases(completion:)) __deprecated_msg("use requestAllMarketsActiveSubscriptionsWithCompletionHandler: instead.");

// 활성화된 앱스토어 구매 목록 조회
/**
 Gets a list of valid subscription App Store items based on UserID

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestActiveSubscriptionsWithCompletionHandler:(nullable void (^)(NSArray<NHNCloudPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestActiveSubscriptions(completion:));

// 활성화된 전체 마켓 구매 목록 조회
/**
 Gets a list of valid subscription items based on UserID, regardless of iOS or Android Store.

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestAllMarketsActiveSubscriptionsWithCompletionHandler:(nullable void (^)(NSArray<NHNCloudPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestAllMarketsActiveSubscriptions(completion:));

// 상품 구매
/**
 Purchase a product by only identifier. The purchase result is returned to the delegate.
 
 @param productIdentifier The product identifier to purchase
 */
+ (void)purchaseWithProductIdentifier:(NSString *)productIdentifier
NS_SWIFT_NAME(purchase(productIdentifier:));

/**
 Purchase a product by only identifier. The purchase result is returned to the delegate.
 
 @param productIdentifier The product identifier to purchase
 @param payload The developer's purchase payload
 */
+ (void)purchaseWithProductIdentifier:(NSString *)productIdentifier payload:(nullable NSString *)payload
NS_SWIFT_NAME(purchase(productIdentifier:payload:));

// 소모성 상품 소비
/**
 An additional API that allows Consume to be performed in the SDK.

 @param result The result of purchase
 @param completionHandler The handler to execute after consume
 */
+ (void)consumeWithPurchaseResult:(NHNCloudPurchaseResult *)result
                completionHandler:(nullable void (^)(NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(consume(result:completion:));


/// ---------------------------------
/// @name Reprocessing
/// ---------------------------------

// 미완료 결제건 재처리 - (구) IAP SDK 호환 (Deprecated)
/**
 Ability to process items stored in LocalDB generated by IAP SDK
 
 @param completionHandler The handler to execute after the process is complete
 
 @note Used when changing SDK from from IAP SDK to NHNCloudIAP SDK
 @note If the item purchased from the IAP SDK is not completed, the NHNCloudIAP SDK processes the obsolete items in the LocalDB.
 @note Need to add libsqlite3.tdb to Linked Framework
 */
+ (void)processesIncompletePurchasesWithCompletionHandler:(nullable void (^)(NSArray <NHNCloudPurchaseResult *> * _Nullable results, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(processesIncompletePurchases(completion:)) __deprecated_msg("processesIncompletePurchasesWithCompletionHandler: is no longer supported.");;

/// ---------------------------------
/// @name Gets the version
/// ---------------------------------

// SDK 버전 정보
/**
 Gets the version of SDK.

 @return The version of SDK
 */
+ (NSString *)version
NS_SWIFT_NAME(version());

@end


NS_ASSUME_NONNULL_END
