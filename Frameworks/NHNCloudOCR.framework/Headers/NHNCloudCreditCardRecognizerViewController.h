//
//  NHNCloudCreditCardRecognizerViewController.h
//  NHNCloudOCR
//
//  Created by HyupM1 on 2022/11/10.
//

#import <NHNCloudOCR/NHNCloudOCR.h>

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudCreditCardRecognizerViewController : NHNCloudCreditCardRecognizerServiceViewController

@property (assign, nonatomic, readonly) CGRect creditCardGuide;
@property (assign, nonatomic, readonly) NHNCloudCreditCardOrientation creditCardGuideOrientation;

- (void)startRunning;
- (void)stopRunning;
- (BOOL)isRunning;

- (void)enableTorchMode;
- (void)disableTorchMode;
- (BOOL)isEnableTorchMode;

- (void)rotateCreditCardGuideOrientation;

- (BOOL)isEnableDefaultUI;

// Override
- (void)didUpdateCreditCardGuide:(CGRect)rect orientation:(NHNCloudCreditCardOrientation)orientation;
- (void)imageDidDetect:(BOOL)detected;

@end

NS_ASSUME_NONNULL_END
