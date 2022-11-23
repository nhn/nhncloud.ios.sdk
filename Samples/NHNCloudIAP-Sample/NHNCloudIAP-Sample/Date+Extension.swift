//
//  Date+Extension.swift
//  NHNCloudIAP-Sample
//
//  Created by NHNCloud on 2022/11/22.
//

import Foundation

extension Date {
    var toString: String {
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss zzz"
        
        return formatter.string(from: self)
    }
}
