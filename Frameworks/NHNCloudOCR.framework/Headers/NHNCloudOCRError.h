//
//  NHNCloudOCRError.h
//  NHNCloudOCR
//
//  Created by HyupM1 on 2022/03/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const NHNCloudOCRErrorDomain;

/**
The error used in NHNCloudOCR.
*/
#ifndef __NHNCloudOCRError__
#define __NHNCloudOCRError__
typedef NS_ERROR_ENUM(NHNCloudOCRErrorDomain, NHNCloudOCRError) {
    NHNCloudOCRErrorUnknown = 0,                       // 알수 없음
    NHNCloudOCRErrorNotInitialized = 1,                // 초기화 하지 않음
    NHNCloudOCRErrorNoCameraPermission = 2,            // 카메라 권한 없음
    NHNCloudOCRErrorNotFoundCamera = 3,                // 카메라 획득 실패
    NHNCloudOCRErrorFailedToAddCamera = 4,             // 카메라 추가 실패
    NHNCloudOCRErrorFormatMismatch = 5,                // 포멧 불일치
    NHNCloudOCRErrorEncryptionFailed = 6,              // 암호화 실패
    NHNCloudOCRErrorInvalidParameter = 7,              // 유효하지 않은 파라미터
};

#endif
NS_ASSUME_NONNULL_END
