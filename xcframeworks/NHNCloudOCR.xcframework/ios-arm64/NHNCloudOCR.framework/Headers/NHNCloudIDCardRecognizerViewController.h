//
//  NHNCloudIDCardRecognizerViewController.h
//  NHNCloudOCR
//
//  Created by NHN Cloud on 2023/04/05.
//

#import <NHNCloudOCR/NHNCloudOCR.h>


NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudIDCardRecognizerViewController : NHNCloudIDCardRecognizerServiceViewController

@property (assign, nonatomic, readonly) CGRect IDCardGuide;

- (void)startRunning;
- (void)stopRunning;
- (BOOL)isRunning;

- (BOOL)isEnableDefaultUI;

// Override
- (void)didUpdateIDCardGuide:(CGRect)rect;
- (void)imageDidDetect:(BOOL)detected;

@end

NS_ASSUME_NONNULL_END
