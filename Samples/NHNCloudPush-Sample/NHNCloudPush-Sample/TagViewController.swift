//
//  TagViewController.swift
//  NHNCloudPush-Sample
//
//  Created by NHNCloud on 2022/11/22.
//

import UIKit
import NHNCloudPush

// 태그명이 아닌 태그 아이디(8자리 문자열)를 기반으로 동작하며, 태그 아이디는 콘솔 > 태그 메뉴에서 생성 및 확인 가능합니다.
class TagViewController: UIViewController {
    
    @IBOutlet var tagTextField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    @IBAction func didTapUpdateTag(_ sender: Any) {
        // 사용자 아이디의 태그 아이디 목록 업데이트
        NHNCloudPush.setUserTag(trimmedTagIdentifiers(tagTextField.text)) { error in
            if let error = error {
                SampleUtil.showAlert(title: "태그 업데이트 실패", message: error.localizedDescription)
            } else {
                SampleUtil.showAlert(title: "태그 업데이트 성공", message: self.tagTextField.text ?? "")
            }
        }
    }
    
    
    @IBAction func didTapAddTag(_ sender: Any) {
        // 사용자 아이디의 태그 아이디 목록 추가
        NHNCloudPush.addUserTag(trimmedTagIdentifiers(tagTextField.text)) { tagIdentifiers, error in
            if let error = error {
                SampleUtil.showAlert(title: "태그 추가 실패", message: error.localizedDescription)
            } else {
                SampleUtil.showAlert(title: "태그 추가 성공", message: tagIdentifiers?.description ?? "")
            }
        }
    }
    
    @IBAction func didTapRemoveTag(_ sender: Any) {
        // 사용자 아이디의 태그 아이디 목록 삭제
        NHNCloudPush.removeUserTag(trimmedTagIdentifiers(tagTextField.text)) { tagIdentifiers, error in
            if let error = error {
                SampleUtil.showAlert(title: "태그 삭제 실패", message: error.localizedDescription)
            } else {
                SampleUtil.showAlert(title: "태그 삭제 성공", message: tagIdentifiers?.description ?? "")
            }
        }
    }
    
    @IBAction func didTapReadTag(_ sender: Any) {
        // 사용자 아이디의 태그 아이디 목록 획득
        NHNCloudPush.getUserTag { tagIdentifiers, error in
            if let error = error {
                SampleUtil.showAlert(title: "태그 조회 실패", message: error.localizedDescription)
            } else {
                SampleUtil.showAlert(title: "태그 조회 성공", message: tagIdentifiers?.description ?? "")
            }
        }
    }
    
    func trimmedTagIdentifiers(_ tagString: String?) -> Set<String> {
        guard let tagString = tagString?.trimmingCharacters(in: .whitespacesAndNewlines),
              tagString.count != 0 else {
            return Set()
        }
        
        return Set(Array(arrayLiteral: tagString))
    }
}
