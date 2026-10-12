## NHN Cloud > SDK 사용 가이드 > 시작하기 > iOS

## 지원 환경

* iOS 11.0 이상
* XCode 최신 버전(버전 14 이상)

## NHN Cloud SDK의 구성

iOS용 NHN Cloud SDK의 구성은 다음과 같습니다.

* [Logger](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/log-collector-ios/) SDK
* [Push](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/push-ios/) SDK
* [Credit-Card OCR](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/creditcard-recognizer-ios/) SDK
* [ID-Card OCR](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/idcard-recognizer-ios/) SDK
    
NHN Cloud SDK가 제공하는 서비스 중 원하는 기능을 선택해 적용할 수 있습니다.

| Service | Cocoapods Pod Name | Carthage | Framework | Deployment Target | Dependency | Build Settings |
| --- | --- | --- | --- | --- | --- | --- |
| All | NHNCloudSDK | binary "[https://nh.nu/sdk](https://nh.nu/sdk) | NHNCloudCore.xcframework<br>NHNCloudCommon.xcframework<br>NHNCloudLogger.xcframework<br>NHNCloudPush.xcframework<br>NHNCloudOCR.xcframework |  |  |  |
| Mandatory | NHNCloudCore<br>NHNCloudCommon |  | NHNCloudCore.xcframework<br>NHNCloudCommon.xcframework | 11.0 |  | OTHER\_LDFLAGS = (<br>"-ObjC",<br>"-lc++"<br>); |
| Log & Crash | NHNCloudLogger |  | NHNCloudLogger.xcframework | 11.0 | [External & Optional]<br> CrashReporter.xcframework (NHNCloud) |  |
| Push | NHNCloudPush |  | NHNCloudPush.xcframework | 11.0 |  UserNotifications.framework<br> PushKit.framework |  |
| OCR | NHNCloudOCR |  | NHNCloudOCR.xcframework | 11.0 |  Vision.framework<br> AVFoundation.framework |  |

## NHN Cloud SDK를 Xcode 프로젝트에 적용

### 1. Cococapods를 사용해 NHN Cloud SDK 적용

Podfile을 생성하여 NHN Cloud SDK에 대한 Pod을 추가합니다.

```podspec
platform :ios, '11.0'
use_frameworks!

target '{YOUR PROJECT TARGET NAME}' do
pod 'NHNCloudSDK'
end
```

생성된 Workspace를 열어 사용할 SDK를 가져옵니다(import).

```objc
#import <NHNCloudCore/NHNCloudCore.h>
#import <NHNCloudLogger/NHNCloudLogger.h>
#import <NHNCloudPush/NHNCloudPush.h>
#import <NHNCloudOCR/NHNCloudOCR.h>
```

### 2. Swift Package Manager를 사용해 NHN Cloud SDK 적용

* XCode에서 **File > Add Packages...** 메뉴를 선택합니다.
* Package URL에 'https://github.com/nhn/nhncloud.ios.sdk'를 넣고 **Add Package** 버튼을 선택합니다.
* 추가를 원하는 Library를 선택합니다.

#### 프로젝트 설정

* **Build Settings**의 **Other Linker Flags**에 **-lc++**와 **-ObjC** 항목을 추가합니다.
    * **Project Target > Build Settings > Linking > Other Linker Flags**
![other_linker_flags](https://static.toastoven.net/toastcloud/sdk/ios/overview_settings_flags_202206.png)

### 3. Carthage를 사용해 NHN Cloud SDK 적용

* Cartfile을 생성하여 NHN Cloud SDK를 추가합니다.

```sh
# Full URL
binary "https://api-storage.cloud.toast.com/v1/AUTH_f9e3dc598ca142d3820e1c19343d5428/carthage/NHNCloudSDK.json" 

# Short URL
binary "https://nh.nu/sdk"
```

* 생성된 Carthage/Build 폴더의 Framework를 Xcode 프로젝트에 추가합니다.
* 프로젝트에 다음과 같이 프레임워크(framework)가 추가된 것을 확인합니다.

* NHN Cloud SDK를 사용하려면 **프레임워크 설정**과 **프로젝트 설정**을 해야합니다.

> 서비스 중 원하는 기능을 선택하여 사용하기 위해서는 서비스별로 필요한 Framework만 선택하여 프로젝트에 추가해야 합니다.
> 서비스별로 필요한 Framework는 [NHN Cloud SDK의 구성](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/getting-started-ios/#nhn-cloud-sdk-components)에서 확인할 수 있습니다.


### 4. 바이너리를 다운로드하여 NHN Cloud SDK 적용

#### SDK 가져오기(import)

NHN Cloud [Downloads](https://docs.nhncloud.com/ko/Download/#nhncloud-sdk) 페이지에서 전체 iOS SDK를 다운로드할 수 있습니다.
Logger의 Crash Report 기능을 사용하려면 함께 배포되는 CrashReporter.xcframework를 프로젝트에 추가해야 합니다.
Push 기능을 사용하려면 UserNotifications.framework를 OCR 기능을 사용하려면 Vision.framework와 AVFoundation.framework를 추가해야 합니다.


#### Project Settings

**Build Settings**의 **Other Linker Flags**에 **-lc++**와 **-ObjC** 항목을 추가합니다.

**Project Target > Build Settings > Linking > Other Linker Flags**를 클릭해 추가할 수 있습니다.

![other_linker_flags](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_flags_202206.png)


#### 프레임워크 가져오기 

사용하려는 프레임워크를 가져옵니다(import).

``` objc
#import <NHNCloudCore/NHNCloudCore.h>
#import <NHNCloudLogger/NHNCloudLogger.h>
#import <NHNCloudPush/NHNCloudPush.h>
#import <NHNCloudOCR/NHNCloudOCR.h>
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

* [Log & Crash](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/log-collector-ios/) 사용 가이드
* [Push](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/push-ios/) 사용 가이드
* [Credit-Card OCR](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/creditcard-recognizer-ios/) 사용 가이드
* [ID-Card OCR](https://docs.nhncloud.com/ko/nhncloud-sdk/ko/idcard-recognizer-ios/) 사용 가이드

