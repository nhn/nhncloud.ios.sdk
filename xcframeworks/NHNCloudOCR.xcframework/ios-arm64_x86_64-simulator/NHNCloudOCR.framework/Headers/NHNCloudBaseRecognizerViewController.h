//
//  NHNCloudBaseRecognizerViewController.h
//  DectedCreditCard
//
//  Created by HyupM1 on 2022/03/07.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudBaseRecognizerViewController : UIViewController 

- (void)startRunningCamera;
- (void)stopRunningCamera;
- (BOOL)isRunnginCamera;

- (void)dismissViewController;

@end

NS_ASSUME_NONNULL_END
