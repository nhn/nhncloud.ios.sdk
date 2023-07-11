//
//  NHNCloudProductsResponse.h
//  NHNCloudIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudProduct.h"

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudProductsResponse
 
 The response you receive as a result of the product listing inquiry([NHNCloudIAP requestProductsWithCompletionHandler:]).
 
 */
@interface NHNCloudProductsResponse : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** A list of products whose status is active in the IAP Console and can be viewed from AppConnect (iTunseConnect). */
@property (nonatomic, copy, readonly) NSArray<NHNCloudProduct *> *products;

/** A list of products whose status is active in the IAP Console and can not be viewed by AppConnect(iTunseConnect). */
@property (nonatomic, copy, readonly) NSArray<NHNCloudProduct *> *invalidProducts;

@end

NS_ASSUME_NONNULL_END
