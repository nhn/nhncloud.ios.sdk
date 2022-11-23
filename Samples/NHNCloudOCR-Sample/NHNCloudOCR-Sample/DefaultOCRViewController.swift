//
//  DefaultOCRViewController.swift
//  NHNCloudOCR-Sample
//
//  Created by NHNCloud on 2022/11/17.
//

import UIKit
import NHNCloudOCR

class DefaultOCRViewController: NHNCloudCreditCardRecognizerViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NHNCloudOCR.setDelegate(self)
    }
}

extension DefaultOCRViewController: NHNCloudCreditCardRecognizerDelegate {
    
    func didDetect(_ cardInfo: NHNCloudCreditCardInfo?, error: Error?) {
        print("didDetect NHNCloudCreditCardInfo : \(String(describing: cardInfo))")
        print("didDetect Error : \(String(describing: cardInfo))")
    }
    
    func didDetect(_ event: NHNCloudSecurityEvent) {
        
        var title = ""
        
        switch event {
        case .screenRecordingOn:
            title = "screenRecordingOn"
            break
        case .screenRecordingOff:
            title = "screenRecordingOff"
            break
        case .screenshot:
            title = "screenshot"
            break
        default:
            break
        }
        
        if (event == .screenshot || event == .screenRecordingOn) {
            let alert = UIAlertController(title: title, message: "Capture!", preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "OK", style: .default))
            
            self.present(alert, animated: true)
        }
        
        if (event == .screenRecordingOn || event == .screenRecordingOff) {
            if (UIScreen.main.isCaptured) {
                UIApplication.shared.windows.first?.isHidden = true
            } else {
                UIApplication.shared.windows.first?.isHidden = false
            }
        }
    }
}
