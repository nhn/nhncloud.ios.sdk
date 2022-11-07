//
//  NHNCloudInAppPurchaseDelegate.h
//  NHNCloudIAP
//
//  Created by Hyup on 2020/03/03.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NHNCloudProduct;
@class NHNCloudPurchaseResult;

/**
 The delegate to be executed according to the purchase result.
 */
@protocol NHNCloudInAppPurchaseDelegate <NSObject>

// 결제 성공
/**
 Called after the purchase has been successfully.

 @param purchase The purchase that successfully complete
 */
- (void)didReceivePurchaseResult:(NHNCloudPurchaseResult *)purchase
NS_SWIFT_NAME(didReceivePurchase(purchase:));

// 결제 실패
/**
 Called after the purchase has been failure.

 @param productIdentifier The identifier of product that has been failure
 @param error The error about the cause of the payment failure.
 */
- (void)didFailPurchaseProduct:(NSString *)productIdentifier withError:(NSError *)error
NS_SWIFT_NAME(didFailPurchase(productIdentifier:error:));

@optional
// 프로모션 결제 진행 여부 결정
/**
 Called after the promotion purchase(IAP buy from the App Store) has been request.
 
 @param product The product to purchase
 @return Return YES to continue the transaction in your app.
 @return Return NO to defer or cancel the transaction.
 */
- (BOOL)shouldAddStorePurchaseForProduct:(NHNCloudProduct *)product API_AVAILABLE(ios(11.0));

@end
