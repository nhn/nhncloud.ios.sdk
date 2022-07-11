//
//  NHNCloudPushServiceExtension.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudPushServiceExtension
 
 You must create and set a NotificationServiceExtension target in your project to receive rich message notification and to collect received analytics event.
 
 ## NotificationServiceExtension configuration
 
     #import <UserNotifications/UserNotifications.h>
     #import <NHNCloudPush/NHNCloudPush.h>
 
     @interface NotificationService : NHNCloudPushServiceExtension
 
     @end
 */
API_AVAILABLE(ios(10.0))
@interface NHNCloudPushServiceExtension : UNNotificationServiceExtension

@end

NS_ASSUME_NONNULL_END
