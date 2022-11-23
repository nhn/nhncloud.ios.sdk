//
//  AppDelegate.swift
//  NHNCloudPush-Sample
//
//  Created by NHNCloud on 2022/11/22.
//

import UIKit
import NHNCloudPush

@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // NHNCloudPush 초기화 및 토큰 등록
        NHNCloudPush.initialize(configuration: SampleUtil.shared.pushConfiguration, delegate: self)
        
        NHNCloudPush.register { tokenInfo, error in
            if (error != nil) {
                SampleUtil.showAlert(title: "토큰 등록 실패", message: error?.localizedDescription ?? "")
            } else {
                SampleUtil.showAlert(title: "토큰 등록 성공", message: tokenInfo?.description ?? "")
            }
        }
        
        return true
    }

    // MARK: UISceneSession Lifecycle
    
    @available(iOS 13.0, *)
    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    @available(iOS 13.0, *)
    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
    }
    
}

extension AppDelegate: NHNCloudPushDelegate {
    // 메시지 수신
    func didReceiveNotification(message: NHNCloudPushMessage) {
        SampleUtil.showAlert(title: "메시지 수신", message: message.description)
    }
    
    // 알림 실행(클릭)
    func didReceiveNotificationResponse(message: NHNCloudPushMessage) {
        SampleUtil.showAlert(title: "알림 실행(클릭)", message: message.description)
    }
    
    // 알림 액션(버튼) 실행
    func didReceiveNotificationAction(action: NHNCloudPushNotificationAction) {
        SampleUtil.showAlert(title: "알림 액션(버튼) 실행", message: action.description)
    }
}
