//
//  NHNCloudCameraManager.h
//  DectedCreditCard
//
//  Created by HyupM1 on 2022/03/04.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const NHNCloudCameraManagerErrorDomain;

typedef NS_ERROR_ENUM(NHNCloudCameraManagerErrorDomain, NHNCloudCameraManagerError) {
    NHNCloudCameraManagerErrorUnknown = 0,                       // 알수 없음
    NHNCloudCameraManagerErrorNoCameraPermission = 1,            // 카메라 권한 없음
    NHNCloudCameraManagerErrorNotFoundCamera = 2,                // 카메라 획득 실패
    NHNCloudCameraManagerErrorFailedToAddCamera = 3,             // 카메라 추가 실패
};

@protocol NHNCloudCameraManagerDelegate <NSObject>

- (void)didOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer;

@optional
- (void)didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end

@interface NHNCloudCameraManager : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate>

@property (nonatomic, weak) id<NHNCloudCameraManagerDelegate> delegate;

@property (strong, nonatomic) AVCaptureDevice *captureDevice;
@property (strong, nonatomic) AVCaptureSession *captureSession;
@property (strong, nonatomic) AVCaptureVideoPreviewLayer *previewLayer;
@property (strong, nonatomic) AVCaptureVideoDataOutput *videoDataOutput;

+ (BOOL)requestAccessForCamera;
- (void)openCameraWithView:(UIView *)view completionHandler:(void (^) (BOOL isSuccess, NSError *error))handler;

@end

NS_ASSUME_NONNULL_END
