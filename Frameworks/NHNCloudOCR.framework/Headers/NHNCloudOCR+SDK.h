//
//  NHNCloudOCR+SDK.h
//  NHNCloudOCR
//
//  Created by HyupM1 on 2022/03/16.
//

#import <Foundation/Foundation.h>

#import <NHNCloudCommon/NHNCloudCommon.h>

#import "NHNCloudOCRConfiguration.h"
#import "NHNCloudCreditCardRecognizerServiceViewController.h"
#import "NHNCloudIDCardRecognizerServiceViewController.h"
#import "NHNCloudCreditCardInfo.h"
#import "NHNCloudIDCardInfo.h"
#import "NHNCloudOCRError.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NHNCloudSecurityEvent) {
    NHNCloudSecurityEventScreenshot = 0,
    NHNCloudSecurityEventScreenRecordingOn = 1,
    NHNCloudSecurityEventScreenRecordingOff = 2,
};

@protocol NHNCloudCreditCardRecognizerDelegate <NSObject>

- (void)didDetectCreditCardInfo:(nullable NHNCloudCreditCardInfo *)cardInfo error:(nullable NSError *)error;

@optional
- (void)didDetectCreditCardSecurityEvent:(NHNCloudSecurityEvent)event;
- (void)creditCardRecognizerViewControllerCancel;
- (void)creditCardRecognizerViewControllerConfirm;

@end

@protocol NHNCloudIDCardRecognizerDelegate <NSObject>

- (void)didDetectIDCardInfo:(nullable NHNCloudIDCardInfo *)cardInfo error:(nullable NSError *)error;

@optional
- (void)didDetectIDCardSecurityEvent:(NHNCloudSecurityEvent)event;
- (void)IDCardRecognizerViewControllerCancel;
- (void)IDCardRecognizerViewControllerConfirm;

@end

@interface NHNCloudOCR : NSObject

+ (void)setDelegate:(nullable id<NHNCloudCreditCardRecognizerDelegate>)delegate
NS_SWIFT_NAME(setDelegate(_:)) __deprecated_msg("use \"setCreditCardRecognizerDelegate\" or \"setIDCardRecognizerDelegate\" instead.");

+ (void)setCreditCardRecognizerDelegate:(nullable id<NHNCloudCreditCardRecognizerDelegate>)delegate
NS_SWIFT_NAME(setCreditCardRecognizerDelegate(_:));

+ (void)setIDCardRecognizerDelegate:(nullable id<NHNCloudIDCardRecognizerDelegate>)delegate
NS_SWIFT_NAME(setIDCardRecognizerDelegate(_:));

+ (void)initWithConfiguration:(NHNCloudOCRConfiguration *)configuration
NS_SWIFT_NAME(initialize(configuration:));

+ (void)initWithConfiguration:(NHNCloudOCRConfiguration *)configuration
                     delegate:(nullable id<NHNCloudCreditCardRecognizerDelegate>)delegate
NS_SWIFT_NAME(initialize(configuration:delegate:)) __deprecated_msg("use \"initWithConfiguration:creditCardRecognizerDelegate:IDCardRecognizerDelegate:\" instead.");

+ (NHNCloudCreditCardRecognizerServiceViewController *)openCreditCardRecognizerViewController
NS_SWIFT_NAME(openCreditCardRecognizerViewController()) __deprecated_msg("This method only supports up to version 1.5.0.");

+ (nullable NHNCloudCreditCardRecognizerServiceViewController *)creditCardRecognizerViewController
NS_SWIFT_NAME(creditCardRecognizerViewController()) __deprecated_msg("This method only supports up to version 1.5.0.");

+ (void)verificateAuthenticityIDCard:(nonnull NHNCloudIDCardInfo *)IDCardInfo
                   completionHandler:(nullable void (^)(BOOL isAuthenticity, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(verificateAuthenticityIDCard(IDCardInfo:completionHandler:));

+ (void)verificateAuthenticityResidentInfoWithApiKey:(nonnull NSString *)apiKey
                                                name:(nonnull NSString *)name
                                      residentNumber:(nonnull NSString *)residentNumber
                                           issueDate:(nonnull NSString *)issueDate
                                   completionHandler:(nullable void (^)(BOOL isAuthenticity, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(verificateAuthenticityResidentInfo(apiKey:name:residentNumber:issueDate:completionHandler:));

+ (void)verificateAuthenticityDriverInfoWithApiKey:(nonnull NSString *)apiKey
                                              name:(nonnull NSString *)name
                                    residentNumber:(nonnull NSString *)residentNumber
                               driverLicenseNumber:(nonnull NSString *)driverLicenseNumber
                                      serialNumber:(nonnull NSString *)serialNumber
                                 completionHandler:(nullable void (^)(BOOL isAuthenticity, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(verificateAuthenticityDriverInfo(apiKey:name:residentNumber:driverLicenseNumber:serialNum:completionHandler:));

+ (void)setDetectedImageReturn:(BOOL)enable;
+ (BOOL)isEnableDetectedImageReturn;

+ (void)setDebugMode:(BOOL)debugMode __deprecated_msg("use \"NHNCloudSDK setDebugMode:\" instead.");;
+ (BOOL)isDebugMode __deprecated_msg("use \"NHNCloudSDK isDebugMode\" instead.");;

+ (NSString *)version;



@end

NS_ASSUME_NONNULL_END
