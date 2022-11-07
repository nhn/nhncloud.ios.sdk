//
//  NHNCloudProduct.h
//  NHNCloudIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The type of product.

 - NHNCloudProductTypeUnknown: Unknown type
 - NHNCloudProductTypeConsumable: Consumable type
 - NHNCloudProductTypeAutoRenewableSubscription: Auto renewable subscription type
 - NHNCloudProductTypeConsumableSubscription : Consumable subscription type
 */
typedef NS_ENUM(NSInteger, NHNCloudProductType) {
    NHNCloudProductTypeUnknown                     NS_SWIFT_NAME(unknown) = 0,
    NHNCloudProductTypeConsumable                  NS_SWIFT_NAME(consumable) = 1,
    NHNCloudProductTypeAutoRenewableSubscription   NS_SWIFT_NAME(autorenewableSubscription) = 2,
    NHNCloudProductTypeConsumableSubscription      NS_SWIFT_NAME(consumableSubscription) = 3,
};

/**
 # NHNCloudProduct
 
 The information of product.
 */
@interface NHNCloudProduct : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** The identifier of product */
@property (nonatomic, copy, readonly) NSString *productIdentifier;

/** The sequence of product. */
@property (nonatomic, readonly) long productSeq;

/** The name of product */
@property (nonatomic, copy, readonly, nullable) NSString *productName;

/** The Type of product(consumable or auto-renewable-subscription) */
@property (nonatomic, readonly) NHNCloudProductType productType;

/** The price of product */
@property (nonatomic, copy, readonly, nullable) NSDecimalNumber *price;

/** The currency of product */
@property (nonatomic, copy, readonly, nullable) NSString *currency;

/** The title of appstore product*/
@property (nonatomic, copy, readonly, nullable) NSString *localizedTitle;

/** The description of appstore product*/
@property (nonatomic, copy, readonly, nullable) NSString *localizedDescription;

/** The localized price of product */
@property (nonatomic, copy, readonly, nullable) NSString *localizedPrice;

/** If 'YES', the product is currently active. If 'NO', it is deactive. */
@property (nonatomic, readonly, getter=isActive) BOOL active;

/** The store code of purchase */
@property (nonatomic, copy, readonly) NSString *storeCode;

@end

NS_ASSUME_NONNULL_END
