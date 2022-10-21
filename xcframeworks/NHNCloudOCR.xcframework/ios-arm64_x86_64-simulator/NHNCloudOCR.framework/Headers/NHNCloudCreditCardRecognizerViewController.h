//
//  NHNCloudCreditCardRecognizerViewController.h
//  DectedCreditCard
//
//  Created by HyupM1 on 2022/03/07.
//

#import <Vision/Vision.h>

#import "NHNCloudBaseRecognizerViewController.h"
#import "NHNCloudCreditCardInfo.h"


NS_ASSUME_NONNULL_BEGIN

@class NHNCloudCreditCardRecognizerViewController;
@protocol NHNCloudCreditCardRecognizerViewControllerDelegate <NSObject>

@optional
- (void)didUpdateCreditCardGuide:(CGRect)rect orientation:(NHNCloudCreditCardOrientation)orientation viewController:(NHNCloudCreditCardRecognizerViewController *)viewController
NS_SWIFT_NAME(didUpdateCreditCardGuide(rect:orientation:viewController:));

- (void)didLoadCreditCardRecognizerViewController:(NHNCloudCreditCardRecognizerViewController *)viewController
NS_SWIFT_NAME(didLoadCreditCardRecognizer(viewController:));

- (void)didWillAppearCreditCardRecognizerViewController:(NHNCloudCreditCardRecognizerViewController *)viewController
NS_SWIFT_NAME(didWillAppearCreditCardRecognizer(viewController:));

- (void)didWillDisappearCreditCardRecognizerViewController:(NHNCloudCreditCardRecognizerViewController *)viewController
NS_SWIFT_NAME(didWillDisappearCreditCardRecognizer(viewController:));

- (void)didDisappearCreditCardRecognizerViewController:(NHNCloudCreditCardRecognizerViewController *)viewController
NS_SWIFT_NAME(didDisappearCreditCardRecognizer(viewController:));

@end

@interface NHNCloudCreditCardRecognizerViewController : NHNCloudBaseRecognizerViewController

@property (weak, nonatomic) id<NHNCloudCreditCardRecognizerViewControllerDelegate> delegate;

@property (assign, nonatomic, readonly) CGRect creditCardGuide;
@property (assign, nonatomic, readonly) NHNCloudCreditCardOrientation creditCardGuideOrientation;

- (void)didUpdateCreditCardGuide:(CGRect)rect orientation:(NHNCloudCreditCardOrientation)orientation;

- (void)startRunning;
- (void)stopRunning;
- (BOOL)isRunning;

- (void)enableTorchMode;
- (void)disableTorchMode;
- (BOOL)isEnableTorchMode;

- (void)rotateCreditCardGuideOrientation;

- (BOOL)isEnableDefaultUI;

@end

NS_ASSUME_NONNULL_END
