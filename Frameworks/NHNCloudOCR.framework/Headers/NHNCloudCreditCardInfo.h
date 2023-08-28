//
//  NHNCloudCreditCardInfo.h
//  DectedCreditCard
//
//  Created by HyupM1 on 2022/03/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef __NHNCloudCreditCardOrientation__
#define __NHNCloudCreditCardOrientation__
typedef NS_ENUM(NSInteger, NHNCloudCreditCardOrientation) {
  
    NHNCloudCreditCardOrientationPortrait = 0,
    NHNCloudCreditCardOrientationLandscape = 1
};

#pragma mark - NHNCloudCreditCardNumber
@interface NHNCloudCreditCardNumber : NSObject
@property(nonatomic, strong, readonly) NSString *value;
@property(nonatomic, strong, readonly) NSNumber *conf;

- (char *)cString;
@end

#pragma mark - NHNCloudCreditCardValidThru
@interface NHNCloudCreditCardValidThru : NSObject
@property(nonatomic, strong, readonly) NSString *monthYear;
@property(nonatomic, strong, readonly) NSNumber *conf;

- (char *)cString;
@end

#pragma mark - NHNCloudDetectCreditCardImage
@interface NHNCloudDetectCreditCardImage : NSObject
@property(nonatomic, strong, readonly) UIImage *image;
@property(nonatomic, readonly) NHNCloudCreditCardOrientation orientation;
@end

#pragma mark - NHNCloudCreditCardInfo
@interface NHNCloudCreditCardInfo : NSObject
@property(nonatomic, strong, readonly, nullable) NSString *totalNumber;
@property(nonatomic, strong, readonly, nullable) NSArray<NHNCloudCreditCardNumber *> *numbers;
@property(nonatomic, strong, readonly, nullable) NHNCloudCreditCardValidThru *validThru;
@property(nonatomic, strong, readonly, nullable) NHNCloudDetectCreditCardImage *detectedImage;
@property(nonatomic, strong, readonly, nullable) NSArray<NSValue *> *numberBoundingBoxes;
@property(nonatomic, assign, readonly) CGRect validThruBoundingBox;

- (char *)cStringTotalNumber;
@end

#endif
NS_ASSUME_NONNULL_END
