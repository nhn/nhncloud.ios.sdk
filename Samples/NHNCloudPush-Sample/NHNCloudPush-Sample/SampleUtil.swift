//
//  SampleUtil.swift
//  NHNCloudPush-Sample
//
//  Created by NHNCloud on 2022/11/22.
//

import UIKit
import NHNCloudPush

let kAppKey:String = "Push AppKey"

class SampleUtil {
    
    public static let shared = SampleUtil()
    
    private init() {
        pushAgreement.allowAdvertisements = true
        pushAgreement.allowNightAdvertisements = false
        // languageCode는 설정하지 않으면 앱의 리소스 언어 -> 획득 불가시 디바이스의 언어 순으로 설정됩니다.
        pushConfiguration.languageCode = "ko"
        // 개발환경(Debug)에서는 꼭 아래 sandbox 프로퍼티를 YES로 설정해야 개발용 인증서로 발송한 메시지의 수신이 가능합니다.
        pushConfiguration.sandbox = true
        // 최초 실행일 경우 사용자에게 알림 허용 권한을 요청합니다. 알림 허용 권한을 획득하지 못하더라도 토큰을 등록합니다.
        pushConfiguration.alwaysAllowTokenRegistration = false
    }
    
    var pushAgreement = NHNCloudPushAgreement(allowNotifications: true)
    var pushConfiguration = NHNCloudPushConfiguration(appKey: kAppKey)
    
    public static func showAlert(title: String, message: String, confirmBtnAction: ((UIAlertAction) -> Void)? = nil) {
        DispatchQueue.main.async {
            let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
            
            let confirmAction = UIAlertAction(title: "확인", style: .default, handler: confirmBtnAction)
            alert.addAction(confirmAction)
            
            if let viewController = UIApplication.shared.visibleViewController {
                
                guard !(viewController is UIAlertController), viewController.presentedViewController == nil else {
                    return
                }
                
                viewController.present(alert, animated: true, completion: nil)
            }
        }
    }
}

extension UIApplication {
    var visibleViewController: UIViewController? {
        
        guard let rootViewController = windows.filter({$0.isKeyWindow}).first?.rootViewController else {
            return nil
        }
        
        return getVisibleViewController(rootViewController)
    }
    
    private func getVisibleViewController(_ rootViewController: UIViewController) -> UIViewController? {
        
        if let presentedViewController = rootViewController.presentedViewController {
            return getVisibleViewController(presentedViewController)
        }
        
        if let navigationController = rootViewController as? UINavigationController {
            return navigationController.visibleViewController
        }
        
        if let tabBarController = rootViewController as? UITabBarController {
            return tabBarController.selectedViewController
        }
        
        return rootViewController
    }
}
