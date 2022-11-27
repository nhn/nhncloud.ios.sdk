//
//  NotificationService.swift
//  PushServiceExtension
//
//  Created by NHNCloud on 2022/11/22.
//

import UserNotifications
import NHNCloudPush

let kAppKey:String = "Push AppKey"

@available(iOSApplicationExtension 10.0, *)
class NotificationService: NHNCloudPushServiceExtension {

    var contentHandler: ((UNNotificationContent) -> Void)?
    var bestAttemptContent: UNMutableNotificationContent?

    override init() {
        super.init()
        // Extension은 앱과는 분리된 별도의 샌드박스 환경이기때문에 수신 지표를 수집하기위헤 Extension에서도 별도로 초기화를 해야합니다.
        let configuration = NHNCloudPushConfiguration(appKey: kAppKey)
        NHNCloudPush.initialize(configuration: configuration)
        
    }
    
    override func didReceive(_ request: UNNotificationRequest, withContentHandler contentHandler: @escaping (UNNotificationContent) -> Void) {
        self.contentHandler = contentHandler
        bestAttemptContent = (request.content.mutableCopy() as? UNMutableNotificationContent)
        
        if let bestAttemptContent = bestAttemptContent {
            // Modify the notification content here...
            bestAttemptContent.title = "\(bestAttemptContent.title) [modified]"
            
            contentHandler(bestAttemptContent)
        }
    }
    
    override func serviceExtensionTimeWillExpire() {
        // Called just before the extension will be terminated by the system.
        // Use this as an opportunity to deliver your "best attempt" at modified content, otherwise the original push payload will be used.
        if let contentHandler = contentHandler, let bestAttemptContent =  bestAttemptContent {
            contentHandler(bestAttemptContent)
        }
    }

}
