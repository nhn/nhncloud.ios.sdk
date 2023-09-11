//
//  DefaultIDCardOCRViewController.swift
//  NHNCloudOCR-Sample
//
//  Created by NHN Cloud on 2023/09/05.
//

import NHNCloudOCR

class DefaultIDCardOCRViewController: NHNCloudIDCardRecognizerViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        NHNCloudOCR.setDetectedImageReturn(false)
    }
}
