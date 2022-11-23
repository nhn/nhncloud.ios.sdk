//
//  ViewController.swift
//  NHNCloudLogger-Sample
//
//  Created by NHNCloud on 2022/11/21.
//

import UIKit
import NHNCloudLogger

let kAppKey:String = "Log & Crash Search AppKey"

class ViewController: UIViewController {

    @IBOutlet var userIDTextField: UITextField!
    @IBOutlet var messageTextField: UITextField!
    @IBOutlet var logLevelSegment: UISegmentedControl!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        guard let configuration = NHNCloudLoggerConfiguration(appKey: kAppKey) else { return }
        NHNCloudLogger.initWith(configuration)
        NHNCloudLogger.setDelegate(self)
    }
    
    @IBAction func didTapSendLog(_ sender: Any) {
        if let userID = userIDTextField.text, !userID.isEmpty {
            NHNCloudSDK.setUserID(userID)
        }

        let logLevel: NHNCloudLogLevel = NHNCloudLogLevel(rawValue: logLevelSegment.selectedSegmentIndex) ?? .DEBUG

        if let logMessage = messageTextField.text, !logMessage.isEmpty {
            sendLog(level: logLevel, message: logMessage)
        } else {
            sendLog(level: logLevel, message: "test log: \(currentDateString())")
        }
    }
    
    @IBAction func didTapCrashNSInvalidArgumentException(_ sender: Any) {
        // 크래시 유발
        self.performSegue(withIdentifier: "unknown", sender: self)
    }
    
    func sendLog(level: NHNCloudLogLevel, message: String) {
        switch level {
        case .DEBUG:
            NHNCloudLogger.debug(message)
        case .INFO:
            NHNCloudLogger.info(message)
        case .WARN:
            NHNCloudLogger.warn(message)
        case .ERROR:
            NHNCloudLogger.error(message)
        case .FATAL:
            NHNCloudLogger.fatal(message)
        @unknown default:
            NHNCloudLogger.debug(message)
        }
    }
    
    func currentDateString() -> String {
        let now = Date()
        let format = DateFormatter()
        format.dateFormat = "yyyy-MM-dd HH:mm:ss zzz"
        return format.string(from: now)
    }
}

extension ViewController: NHNCloudLoggerDelegate {
    
    // 로그 전송 성공
    func nhnCloudLogDidSuccess(_ log: NHNCloudLog) {
        print("log did success: \(log)")
    }
    
    // 로그 전송 실패
    func nhnCloudLogDidFail(_ log: NHNCloudLog, error: Error) {
        print("log did fail: \(log), \(error.localizedDescription)")
    }
    
    // 네트워크 단절 등의 이유로 로그 전송에 실패한 경우 재전송을 위해 SDK 내부 저장
    func nhnCloudLogDidSave(_ log: NHNCloudLog) {
        print("log did save: \(log)")
    }
    
    // 로그 필터링
    func nhnCloudLogDidFilter(_ log: NHNCloudLog, logFilter: NHNCloudLogFilter) {
        print("log did filter: \(log), \(logFilter)")
    }
}
