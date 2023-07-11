//
//  NHNCloudPushError.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const NHNCloudPushErrorDomain;

/**
 The error used in NHNCloudPush. 
 */
typedef NS_ERROR_ENUM(NHNCloudPushErrorDomain, NHNCloudPushError) {
    NHNCloudPushErrorUnknown = 0,              // 알수 없음
    NHNCloudPushErrorNotInitialized = 1,       // 초기화하지 않음
    NHNCloudPushErrorUserInvalid = 2,          // 사용자 아이디 미설정
    NHNCloudPushErrorPermissionDenied = 3,     // 권한 획득 실패
    NHNCloudPushErrorSystemFailed = 4,         // 시스템에 의한 실패
    NHNCloudPushErrorTokenInvalid = 5,         // 토큰 값이 없거나 유효하지 않음
    NHNCloudPushErrorAlreadyInProgress = 6,    // 이미 진행중
    NHNCloudPushErrorParameterInvalid = 7,     // 매계변수 오류
    NHNCloudPushErrorNotSupported = 8,         // 지원하지 않는 기능
    NHNCloudPushErrorClientFailed = 9,         // 서버 오류
};

NS_ASSUME_NONNULL_END
