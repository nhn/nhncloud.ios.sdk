//
//  NHNCloudIDCardInfo.h
//  NHNCloudOCR
//
//  Created by NHN Cloud on 2023/04/05.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NHNCloudIDCardType) {
    NHNCloudIDCardTypeResident = 0,
    NHNCloudIDCardTypeDriver = 1
};

#pragma mark - NHNCloudIDCardValue
@interface NHNCloudIDCardValue : NSObject

@property(nonatomic, strong, readonly) NSString *value;
@property(nonatomic, strong, readonly) NSNumber *conf;

- (char *)cString;

@end

#pragma mark - NHNCloudDetectIDCardImage
@interface NHNCloudDetectIDCardImage : NSObject

@property(nonatomic, strong, readonly) UIImage *image;

@end

@interface NHNCloudIDCardInfo  : NSObject

@property(nonatomic, readonly) NHNCloudIDCardType type;
@property(nonatomic, strong, readonly, nullable) NHNCloudDetectIDCardImage *detectedImage;
@property(nonatomic, strong, readonly, nullable) NSArray<NSValue *> *boundingBoxes;

@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *name;
@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *residentNumber;
@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *issueDate;
@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *issuer;

#pragma mark - driver license only
@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *driverLicenseNumber;
@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *licenseType;
@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *condition;
@property(nonatomic, strong, readonly, nullable) NHNCloudIDCardValue *serialNumber;

@end

NS_ASSUME_NONNULL_END
