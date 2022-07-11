//
//  NHNCloudIAPError.h
//  NHNCloudIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const NHNCloudIAPErrorDomain;

/**
The error used in NHNCloudIAP.
*/
typedef NS_ERROR_ENUM(NHNCloudIAPErrorDomain, NHNCloudIAPError) {
    NHNCloudIAPErrorUnknown = 0,                       // 알수 없음
    NHNCloudIAPErrorNotInitialized = 1,                // 초기화 하지 않음
    NHNCloudIAPErrorStoreNotAvailable = 2,             // 스토어 사용 불가
    NHNCloudIAPErrorProductNotAvailable = 3,           // 상품 정보 획득 실패
    NHNCloudIAPErrorProductInvalid = 4,                // 원결제의 상품 아이디와 현재 상품 아이디 불일치
    NHNCloudIAPErrorAlreadyOwned = 5,                  // 이미 소유한 상품
    NHNCloudIAPErrorAlreadyInProgress = 6,             // 이미 진행중인 요청 있음
    NHNCloudIAPErrorUserInvalid = 7,                   // 현재 사용자 아이디가 결제 사용자 아이디와 불일치
    NHNCloudIAPErrorPaymentInvalid = 8,                // 결제 추가정보(ApplicationUsername) 획득 실패
    NHNCloudIAPErrorPaymentCancelled = 9,              // 스토어 결제 취소
    NHNCloudIAPErrorPaymentFailed = 10,                // 스토어 결제 실패
    NHNCloudIAPErrorVerifyFailed = 11,                 // 영수증 검증 실패
    NHNCloudIAPErrorChangePurchaseStatusFailed = 12,   // 구매 상태 변경 실패
    NHNCloudIAPErrorPurchaseStatusInvalid = 13,        // 구매 진행 불가 상태
    NHNCloudIAPErrorExpired = 14,                      // 구독 만료
    NHNCloudIAPErrorRenewalPaymentNotFound = 15,       // 영수증내에 갱신 결제와 일치하는 결제 정보가 없음
    NHNCloudIAPErrorRestoreFailed = 16,                // 복원 실패
    NHNCloudIAPErrorPaymentNotAvailable = 17,          // 구매 진행 불가 상태 (e.g. 앱 내 구입 제한 설정)
    NHNCloudIAPErrorPurchaseLimitExceeded = 18,        // 월 구매 한도 초과
};

NS_ASSUME_NONNULL_END
