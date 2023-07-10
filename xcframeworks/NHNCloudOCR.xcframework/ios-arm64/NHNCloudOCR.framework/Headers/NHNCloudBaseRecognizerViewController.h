//
//  NHNCloudBaseRecognizerViewController.h
//  DectedCreditCard
//
//  Created by HyupM1 on 2022/03/07.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NHNCloudBaseRecognizerViewControllerProtocol <NSObject>

- (NSString *)notificationName;

@end

@interface NHNCloudBaseRecognizerViewController : UIViewController <NHNCloudBaseRecognizerViewControllerProtocol>

- (void)startRunningCamera;
- (void)stopRunningCamera;
- (BOOL)isRunnginCamera;

- (void)dismissViewController;
- (void)dismissViewControllerWithCompletionHandler:(nullable void (^)(void))completionHandler;

@end

NS_ASSUME_NONNULL_END
