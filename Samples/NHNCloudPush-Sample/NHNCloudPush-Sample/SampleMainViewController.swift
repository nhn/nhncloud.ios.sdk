//
//  ViewController.swift
//  NHNCloudPush-Sample
//
//  Created by NHNCloud on 2022/11/22.
//

import UIKit
import NHNCloudPush

class SampleMainViewController: UIViewController {

    @IBOutlet var userIDTextField: UITextField!
    @IBOutlet var nightAdvertisementsSwitch: UISwitch!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
    }
    
    @IBAction func didTapUserIDUpdate(_ sender: Any) {
        NHNCloudSDK.setUserID(userIDTextField.text)
        self.view.endEditing(true)
    }
    
    // MARK: 토큰 등록 및 조회

    @IBAction func didTapRegisterToken(_ sender: Any) {
        NHNCloudSDK.setUserID(userIDTextField.text)
        NHNCloudPush.initialize(configuration: SampleUtil.shared.pushConfiguration)

        NHNCloudPush.register(agreement: SampleUtil.shared.pushAgreement) { tokenInfo, error in
            if (error != nil) {
                SampleUtil.showAlert(title: "토큰 등록 실패", message: error?.localizedDescription ?? "")
            } else {
                SampleUtil.showAlert(title: "토큰 등록 성공", message: tokenInfo?.description ?? "")
            }
        }
    }
    
    @IBAction func didTapQueryToken(_ sender: Any) {
        NHNCloudPush.queryTokenInfo { tokenInfo, error in
            if (error != nil) {
                SampleUtil.showAlert(title: "토큰 조회 실패", message: error?.localizedDescription ?? "")
            } else {
                SampleUtil.showAlert(title: "토큰 조회 성공", message: tokenInfo?.description ?? "")
            }
        }
    }
    
    @IBAction func didTapUnregisterToken(_ sender: Any) {
        NHNCloudPush.unregister { deviceToken, error in
            if (error != nil) {
                SampleUtil.showAlert(title: "토큰 삭제 실패", message: error?.localizedDescription ?? "")
            } else {
                SampleUtil.showAlert(title: "토큰 삭제 성공", message: deviceToken ?? "")
            }
        }
    }
    
    @IBAction func didChangeAlwaysAllowTokenRegistrationSwitch(_ sender: UISwitch) {
        SampleUtil.shared.pushConfiguration.alwaysAllowTokenRegistration = sender.isOn
    }
    
    // MARK: 포그라운드 알림 및 동의 여부 설정
    @IBAction func didChangeForegroundSwitch(_ sender: UISwitch) {
        let options = NHNCloudPush.notificationOptions()
        options?.foregroundEnabled = sender.isOn
        
        NHNCloudPush.setNotificationOptions(options)
    }
    
    @IBAction func didChangeNotificationsSwitch(_ sender: UISwitch) {
        SampleUtil.shared.pushAgreement.allowNotifications = sender.isOn
    }
    
    @IBAction func didChangeAdvertisementsSwitch(_ sender: UISwitch) {
        SampleUtil.shared.pushAgreement.allowAdvertisements = sender.isOn
        
        if !sender.isOn {
            nightAdvertisementsSwitch.setOn(false, animated: true)
            nightAdvertisementsSwitch.isEnabled = false
            SampleUtil.shared.pushAgreement.allowNightAdvertisements = false
        } else {
            nightAdvertisementsSwitch.isEnabled = true
        }
    }
    
    @IBAction func didChangeNightAdvertisementsSwitch(_ sender: UISwitch) {
        SampleUtil.shared.pushAgreement.allowNightAdvertisements = sender.isOn
    }
    
}

