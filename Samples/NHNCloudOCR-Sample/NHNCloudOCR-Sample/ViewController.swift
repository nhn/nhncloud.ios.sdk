//
//  ViewController.swift
//  NHNCloudOCR-Sample
//
//  Created by NHNCloud on 2022/11/17.
//

import UIKit
import NHNCloudOCR

let kAppKey:String = "OCR AppKey"
let kSecret:String = "OCR Secret"

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        let configuration = NHNCloudOCRConfiguration(appKey: kAppKey, secret: kSecret)
        NHNCloudOCR.initialize(configuration: configuration)
    }
}

