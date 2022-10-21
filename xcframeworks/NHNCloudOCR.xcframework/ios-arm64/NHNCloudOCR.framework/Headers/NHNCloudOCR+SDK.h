//
//  NHNCloudOCR+SDK.h
//  NHNCloudOCR
//
//  Created by HyupM1 on 2022/03/16.
//

#import <Foundation/Foundation.h>

#import <NHNCloudCommon/NHNCloudCommon.h>

#import "NHNCloudOCRConfiguration.h"
#import "NHNCloudCreditCardRecognizerViewController.h"
#import "NHNCloudCreditCardInfo.h"
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
- (void)didDetectSecurityEvent:(NHNCloudSecurityEvent)event;
@end

@interface NHNCloudOCR : NSObject

+ (void)setDelegate:(nullable id<NHNCloudCreditCardRecognizerDelegate>)delegate
NS_SWIFT_NAME(setDelegate(_:));

+ (void)initWithConfiguration:(NHNCloudOCRConfiguration *)configuration
NS_SWIFT_NAME(initialize(configuration:));

+ (void)initWithConfiguration:(NHNCloudOCRConfiguration *)configuration
                     delegate:(nullable id<NHNCloudCreditCardRecognizerDelegate>)delegate
NS_SWIFT_NAME(initialize(configuration:delegate:));

+ (NHNCloudCreditCardRecognizerViewController *)openCreditCardRecognizerViewController
NS_SWIFT_NAME(openCreditCardRecognizerViewController());

+ (nullable NHNCloudCreditCardRecognizerViewController *)creditCardRecognizerViewController
NS_SWIFT_NAME(creditCardRecognizerViewController());

+ (void)setDetectedImageReturn:(BOOL)enable;
+ (BOOL)isEnableDetectedImageReturn;

+ (void)setDebugMode:(BOOL)debugMode;
+ (BOOL)isDebugMode;

+ (NSString *)version;



@end

NS_ASSUME_NONNULL_END
