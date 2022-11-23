//
//  IAPViewController.swift
//  NHNCloudIAP-Sample
//
//  Created by NHNCloud on 2022/11/21.
//

import UIKit
import NHNCloudIAP

let kAppKey:String = "IAP AppKey"

class IAPViewController: UIViewController {
    @IBOutlet weak var appKeyTextField: UITextField!
    @IBOutlet weak var userIDTextField: UITextField!
    @IBOutlet weak var functionStackview: UIStackView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = "IAP Sample"
        
        appKeyTextField.text = kAppKey
        userIDTextField.text = "TestUser"
    }
    
    @IBAction func initButtonTapped(_ sender: UIButton) {
        guard let appKey = appKeyTextField.text, !appKey.isEmpty else {
            showAlert(title: "AppKey를 입력하세요", message: nil)
            return
        }

        NHNCloudIAP.initialize(configuration: NHNCloudIAPConfiguration(appKey: appKey), delegate: self)
    }
    
    @IBAction func userIDSettingButtonTapped(_ sender: UIButton) {
        NHNCloudSDK.setUserID(userIDTextField.text)
    }

    // 상품 목록 조회 / 구매
    @IBAction func productListButtonTapped(_ sender: UIButton) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let viewController = storyboard.instantiateViewController(withIdentifier: "ProductsViewController")
        viewController.title = "상품 목록 조회 / 구매"
        navigationController?.pushViewController(viewController, animated: true)
    }

    // 미소비 상품 내역 조회 (전체 마켓)
    @IBAction func requestAllMarketConsumablePurchasesButtonTapped(_ sender: UIButton) {
        NHNCloudIAP.requestAllMarketsConsumablePurchases { [weak self] results, error in
            if let error = error {
                self?.showAlert(title: "오류", message: error.localizedDescription)
                return
            }
            
            guard let results = results, !results.isEmpty else {
                self?.showAlert(title: "전체 마켓", message: "미소비 상품 내역 조회")
                return
            }
                        
            DispatchQueue.main.async { [weak self] in
                guard let viewController = self?.purchaseResultsViewController(results: results, consumable: true) else {
                    return
                }

                viewController.title = "미소비 상품 내역 조회 (전체 마켓)"
                self?.navigationController?.pushViewController(viewController, animated: true)
            }
        }
    }
    
    // 미소비 상품 내역 조회 (앱스토어)
    @IBAction func requestConsumablePurchasesButtonTapped(_ sender: UIButton) {
        NHNCloudIAP.requestConsumablePurchases { [weak self] results, error in
            if let error = error {
                self?.showAlert(title: "오류", message: error.localizedDescription)
                return
            }
            
            guard let results = results, !results.isEmpty else {
                self?.showAlert(title: "앱스토어", message: "미소비 상품 내역 조회")
                return
            }
            
            DispatchQueue.main.async { [weak self] in
                guard let viewController = self?.purchaseResultsViewController(results: results, consumable: true) else {
                    return
                }
                
                viewController.title = "미소비 상품 내역 조회 (앱스토어)"
                self?.navigationController?.pushViewController(viewController, animated: true)
            }
        }
    }
    
    // 활성화된 상품 목록 조회 (전체 마켓)
    @IBAction func requestAllMarketsActiveSubscriptionsButtonTapped(_ sender: UIButton) {
        NHNCloudIAP.requestAllMarketsActiveSubscriptions { [weak self] results, error in
            if let error = error {
                self?.showAlert(title: "오류", message: error.localizedDescription)
                return
            }
            
            guard let results = results, !results.isEmpty else {
                self?.showAlert(title: "전체 마켓", message: "활성화 된 구독 상품이 없습니다")
                return
            }
            
            DispatchQueue.main.async { [weak self] in
                guard let viewController = self?.purchaseResultsViewController(results: results, consumable: false) else {
                    return
                }

                viewController.title = "활성화된 상품 목록 조회 (전체 마켓)"
                self?.navigationController?.pushViewController(viewController, animated: true)
            }
        }
    }
    
    
    
    // 활성화된 상품 목록 조회 (앱스토어)
    @IBAction func requestActieSubscriptionButtonTapped(_ sender: UIButton) {
        NHNCloudIAP.requestActiveSubscriptions { [weak self] results, error in
            if let error = error {
                self?.showAlert(title: "오류", message: error.localizedDescription)
                return
            }
            
            guard let results = results, !results.isEmpty else {
                self?.showAlert(title: "앱스토어", message: "활성화 된 구독 상품이 없습니다")
                return
            }
            
            DispatchQueue.main.async { [weak self] in
                guard let viewController = self?.purchaseResultsViewController(results: results, consumable: false) else {
                    return
                }

                viewController.title = "활성화된 상품 목록 조회 (앱스토어)"
                self?.navigationController?.pushViewController(viewController, animated: true)
            }
        }
    }
    
    // 구독 결제 복원
    @IBAction func restoreButtonTapped(_ sender: UIButton) {
        NHNCloudIAP.restore { [weak self] results, error in
            if let error = error {
                self?.showAlert(title: "오류", message: error.localizedDescription)
                return
            }

            let alertViewController = UIAlertController(title: "복원 성공", message: nil, preferredStyle: .alert)
            alertViewController.addAction(UIAlertAction(title: "확인", style: .default))
            
            DispatchQueue.main.async { [weak self] in
                self?.present(alertViewController, animated: true)
            }
        }
    }
    
    
    private func purchaseResultsViewController(results: [NHNCloudPurchaseResult]?, consumable: Bool) -> PurchaseResultsViewController {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let purchaseResultsViewController = storyboard.instantiateViewController(withIdentifier: "PurchaseResultsViewController") as! PurchaseResultsViewController
        purchaseResultsViewController.consumablePurchases = results ?? []
        purchaseResultsViewController.isConsumable = consumable

        return purchaseResultsViewController
    }
}

extension IAPViewController: NHNCloudInAppPurchaseDelegate {
    func didReceivePurchase(purchase: NHNCloudPurchaseResult!) {
        showAlert(title: purchase.productIdentifier, message: purchase.paymentSeq)
    }
    
    func didFailPurchase(productIdentifier: String!, error: Error!) {
        showAlert(title: productIdentifier, message: error.localizedDescription)
    }
}

extension IAPViewController {
    func showAlert(title: String?, message: String?) {
        let alertViewController = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alertViewController.addAction(UIAlertAction(title: "확인", style: .default))
        
        DispatchQueue.main.async { [weak self] in
            self?.present(alertViewController, animated: true)
        }
    }
}
