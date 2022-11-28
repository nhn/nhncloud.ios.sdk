//
//  NHNCloudCreditCardRecognizerServiceViewController.h
//  DectedCreditCard
//
//  Created by HyupM1 on 2022/03/07.
//

#import <Vision/Vision.h>

#import "NHNCloudBaseRecognizerViewController.h"
#import "NHNCloudCreditCardInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudCreditCardRecognizerServiceViewController : NHNCloudBaseRecognizerViewController

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
