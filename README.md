## NHN Cloud > SDK 사용 가이드 > 시작하기 > iOS

## 지원 환경

* iOS 9.0 이상
* XCode 최신 버전(버전 13 이상)

## NHN Cloud SDK의 구성

iOS용 NHN Cloud SDK의 구성은 다음과 같습니다.

* [Logger](https://docs.toast.com/ko/TOAST/ko/toast-sdk/log-collector-ios/) SDK
* [In-app Purchase AppStore](https://docs.toast.com/ko/TOAST/ko/toast-sdk/iap-ios/) SDK
* [Push](https://docs.toast.com/ko/TOAST/ko/toast-sdk/push-ios/) SDK

NHN Cloud SDK가 제공하는 서비스 중 원하는 기능을 선택해 적용할 수 있습니다.

| Service | Cocoapods Pod Name | Carthage | Framework | Dependency | Build Settings |
| ------- | ------------------ | -------- | --------- | ---------- | -------------- |
| All | NHNCloudSDK | binary "https://nh.nu/nhncloudsdk " | NHNCloudCore.framework<br>NHNCloudCommon.framework<br>NHNCloudLogger.framework<br>NHNCloudIAP.framework<br>NHNCloudPush.framework |  |  |
| Mandatory | NHNCloudCore<br>NHNCloudCommon |  | NHNCloudCore.framework<br>NHNCloudCommon.framework |  | OTHER\_LDFLAGS = (<br>"-ObjC",<br>"-lc++"<br>); |
| Log & Crash | NHNCloudLogger |  | NHNCloudLogger.framework | [External & Optional]<br>\* CrashReporter.framework (NHNCloud) |  |
| IAP | NHNCloudIAP |  | NHNCloudIAP.framework | \* StoreKit.framework<br><br>[Optional]<br>\* libsqlite3.tdb |  |
| Push | NHNCloudPush |  | NHNCloudPush.framework | \* UserNotifications.framework<br><br>[Optional]<br>\* PushKit.framework |  |

## NHN Cloud SDK를 Xcode 프로젝트에 적용

### 1. Cococapods를 사용해 NHN Cloud SDK 적용

Podfile을 생성하여 NHN Cloud SDK에 대한 Pod을 추가합니다.

```podspec
platform :ios, '9.0'
use_frameworks!

target '{YOUR PROJECT TARGET NAME}' do
pod 'NHNCloudSDK'
end
```

생성된 Workspace를 열어 사용할 SDK를 가져옵니다(import).

```objc
#import <NHNCloudCore/NHNCloudCore.h>
#import <NHNCloudLogger/NHNCloudLogger.h>
#import <NHNCloudIAP/NHNCloudIAP.h>
#import <NHNCloudPush/NHNCloudPush.h>
```

### 2. 바이너리를 다운로드하여 NHN Cloud SDK 적용

#### SDK 가져오기(import)

NHN Cloud [Downloads](https://docs.toast.com/ko/Download/#toast-sdk) 페이지에서 전체 iOS SDK를 다운로드할 수 있습니다.

![import_frameworks](https://static.toastoven.net/toastcloud/sdk/ios/overview_import_frameworks_folder_202206.png)

Logger의 Crash Report 기능을 사용하려면 함께 배포되는 CrashReporter.framework도 프로젝트에 추가해야 합니다.

![import_external_framework](https://static.toastoven.net/toastcloud/sdk/ios/overview_import_external_folder_202206.png)

프로젝트에 다음과 같이 프레임워크(framework)가 추가된 것을 확인합니다.

![import_frameworks_complete](https://static.toastoven.net/toastcloud/sdk/ios/overview_import_complete_folder_202206.png)

IAP 기능을 사용하려면 StoreKit.framework를 추가해야 합니다.

![linked__storekit_frameworks](https://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_StoreKit_202206.png)

Push 기능을 사용하려면 UserNotifications.framework를 추가해야 합니다.

![linked__usernotifications_frameworks](https://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_UserNotifications_202206.png)

##### xcframework
* xcframework를 사용하면 arm simulator에서도 NHN Cloud SDK를 사용할 수 있습니다.
![xcframework01](https://static.toastoven.net/toastcloud/sdk/ios/xcframework01_202206.png)
![xcframework01](https://static.toastoven.net/toastcloud/sdk/ios/xcframework02_202206.png)


#### Project Settings

**Build Settings**의 **Other Linker Flags**에 **-lc++**와 **-ObjC** 항목을 추가합니다.

**Project Target > Build Settings > Linking > Other Linker Flags**를 클릭해 추가할 수 있습니다.

![other_linker_flags](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_flags_202206.png)

CrashReporter.framewor를 직접 다운로드하거나 빌드한 경우에는 Build Setting의 Enable Bitcode의 값을 **NO**로 변경해야 합니다.

**Project Target > Build Settings > Build Options > Enable Bitcode**을 클릭하고 **NO**를 클릭합니다.

![enable_bitcode](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_bitcode_202206.png)
> NHN Cloud의 [Downloads](https://docs.toast.com/ko/Download/#toast-sdk) 페이지에서 다운로드 받은 CrashReporter.framework는 bitCode를 지원합니다.


#### 프레임워크 가져오기 

사용하려는 프레임워크를 가져옵니다(import).

``` objc
#import <NHNCloudCore/NHNCloudCore.h>
#import <NHNCloudLogger/NHNCloudLogger.h>
#import <NHNCloudIAP/NHNCloudIAP.h>
#import <NHNCloudPush/NHNCloudPush.h>
```

## UserID 설정

NHN Cloud SDK에 사용자 아이디를 설정할 수 있습니다.
설정한 사용자 아이디는 NHN Cloud SDK의 각 모듈에서 공통으로 사용됩니다.
NHN Cloud Logger의 로그 전송 API를 호출할 때마다 설정한 사용자 아이디를 로그와 함께 서버로 전송합니다.

### UserID API 명세

```objc
@interface NHNCloudSDK : NSObject

//...

+ (void)setUserID:(NSString *)userID;

//...

@end
```

### UserID 설정 사용 예

```objc
[NHNCloudSDK setUserID:@"NHNCloud-USER"];
```
## 디버그 모드 설정

NHNCloudSDK의 내부 로그를 확인하기 위해 디버그 모드를 설정할 수 있습니다.
NHNCloudSDK와 관련해 문의하실 때는 디버그 모드를 활성화해서 전달해 주시면 빠르게 지원해드릴 수 있습니다.

### 디버그 모드 설정 API 명세


```objc
@interface NHNCloudSDK : NSObject

//...

+ (void)setDebugMode:(BOOL)debugMode;

//...

@end
```

### 디버그 모드 설정 사용 예

```objc
// Set Debug Mode.
[NHNCloudSDK setDebugMode:YES];// or NO
```

> [주의] 앱을 릴리스할 경우, 반드시 디버그 모드를 비활성화해야 합니다.

## NHN Cloud Service 사용

* [Log & Crash](https://docs.toast.com/ko/TOAST/ko/toast-sdk/log-collector-ios/) 사용 가이드
* [In-app Purchase](https://docs.toast.com/ko/TOAST/ko/toast-sdk/iap-ios/) 사용 가이드
* [Push](https://docs.toast.com/ko/TOAST/ko/toast-sdk/push-ios/) 사용 가이드
