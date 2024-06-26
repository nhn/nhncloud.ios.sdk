//
//  CustomCreditCardOCRViewController.swift
//  NHNCloudOCR-Sample
//
//  Created by NHNCloud on 2022/11/17.
//

import UIKit
import NHNCloudOCR

class CustomCreditCardOCRViewController: NHNCloudCreditCardRecognizerServiceViewController {
    
    var customView: CreditCardOCRCustomView? = nil
    var customNavigationBar: UINavigationBar? = nil
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.navigationController?.navigationBar.isHidden = true
        self.navigationController?.navigationBar.barStyle = .black
        
        NHNCloudOCR.setCreditCardRecognizerDelegate(self)
        
        self.setCustomUI()
        
        self.startRunning()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        self.navigationController?.navigationBar.isHidden = false
        self.navigationController?.navigationBar.barStyle = .default
        
        self.customView = nil
        self.stopRunning()
    }
    
    override func didUpdateCreditCardGuide(_ rect: CGRect, orientation: NHNCloudCreditCardOrientation) {
        super.didUpdateCreditCardGuide(rect, orientation: orientation)
        
        self.customView?.updateGuide(rect: rect)
    }
    
    override func imageDidDetect(_ detected: Bool) {
        if detected {
            self.customView?.showEffect()
        }
    }
}

//MARK: - Custom UI
extension CustomCreditCardOCRViewController {
    
    func setCustomUI() {
        self.setCustomView()
        self.setCustomNavigation()
        self.setCustomBottomBar()
    }
    
    func setCustomView() {
        self.customView = CreditCardOCRCustomView(frame: self.view.frame, dimmedColor: UIColor(red: 0, green: 0, blue: 0, alpha: 0.5))
        self.view.addSubview(self.customView!)
        
        self.customView?.translatesAutoresizingMaskIntoConstraints = false
        self.customView?.topAnchor.constraint(equalTo: self.view.topAnchor).isActive = true
        self.customView?.bottomAnchor.constraint(equalTo: self.view.bottomAnchor).isActive = true
        self.customView?.leadingAnchor.constraint(equalTo: self.view.leadingAnchor).isActive = true
        self.customView?.trailingAnchor.constraint(equalTo: self.view.trailingAnchor).isActive = true
    }
    
    func setCustomNavigation() {
        self.customNavigationBar = UINavigationBar(frame: CGRectZero)
        self.customNavigationBar?.setBackgroundImage(UIImage(), for: .default)
        self.customNavigationBar?.shadowImage = UIImage()
        self.customNavigationBar?.isTranslucent = true
        
        let titleDict: NSDictionary = [NSAttributedString.Key.foregroundColor: UIColor.white]
        self.customNavigationBar?.titleTextAttributes = titleDict as? [NSAttributedString.Key : Any]
        
        let navigationItem = UINavigationItem(title: "Credit-Card")
        self.customNavigationBar?.setItems([navigationItem], animated: true)
        
        let closeButton = UIButton(type: .custom)
        closeButton.setTitle("X", for: .normal)
        closeButton.addTarget(self, action: #selector(closeButtonAction(_:)), for: .touchUpInside)
        closeButton.frame = CGRect(x: 0, y: 0, width: 44, height: 44)
        let rightBarButton = UIBarButtonItem(customView: closeButton)
        navigationItem.rightBarButtonItem = rightBarButton
    
        let torchButton = UIButton(type: .custom)
        torchButton.setTitle("torch", for: .normal)
        torchButton.addTarget(self, action: #selector(torchButtonAction(_:)), for: .touchUpInside)
        torchButton.frame = CGRect(x: 0, y: 0, width: 44, height: 44)
        let leftBarButton = UIBarButtonItem(customView: torchButton)
        navigationItem.leftBarButtonItem = leftBarButton
        
        self.view.addSubview(self.customNavigationBar!)
        
        self.customNavigationBar?.translatesAutoresizingMaskIntoConstraints = false
        self.customNavigationBar?.topAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.topAnchor).isActive = true
        self.customNavigationBar?.leadingAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.leadingAnchor).isActive = true
        self.customNavigationBar?.trailingAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.trailingAnchor).isActive = true
        self.customNavigationBar?.heightAnchor.constraint(equalToConstant: 56).isActive = true
    }
    
    @objc func closeButtonAction(_ button: UIButton) {
        self.dismiss()
    }
    
    @objc func torchButtonAction(_ button: UIButton) {
        if self.isEnableTorchMode() {
            self.disableTorchMode()
        } else {
            self.enableTorchMode()
        }
    }
    
    func setCustomBottomBar() {
        let bottomView = UIView(frame: CGRect(x: 0,
                                              y: 0,
                                              width: self.view.frame.size.width,
                                              height: 60))
        bottomView.backgroundColor = UIColor.black
        
        self.view.addSubview(bottomView)
        
        bottomView.translatesAutoresizingMaskIntoConstraints = false
        bottomView.heightAnchor.constraint(equalToConstant: 60).isActive = true
        bottomView.bottomAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.bottomAnchor).isActive = true
        bottomView.leadingAnchor.constraint(equalTo: self.view.leadingAnchor).isActive = true
        bottomView.trailingAnchor.constraint(equalTo: self.view.trailingAnchor).isActive = true
        
        let bottomStackView = UIStackView()
        bottomStackView.axis = .horizontal
        bottomStackView.distribution = .fillEqually
        bottomStackView.alignment = .fill
        bottomStackView.spacing = 30
        
        bottomView.addSubview(bottomStackView)
        
        bottomStackView.translatesAutoresizingMaskIntoConstraints = false
        bottomStackView.heightAnchor.constraint(equalTo: bottomView.heightAnchor).isActive = true
        bottomStackView.topAnchor.constraint(equalTo: bottomView.topAnchor).isActive = true
        bottomStackView.bottomAnchor.constraint(equalTo: bottomView.bottomAnchor).isActive = true
        bottomStackView.leadingAnchor.constraint(equalTo: bottomView.leadingAnchor).isActive = true
        bottomStackView.trailingAnchor.constraint(equalTo: bottomView.trailingAnchor).isActive = true
        
        let rotateButton = UIButton(type: .custom)
        rotateButton.addTarget(self, action: #selector(rotateButtonAction(_:)), for: .touchUpInside)
        rotateButton.setTitle("Rotate", for: .normal)
        rotateButton.isExclusiveTouch = true
        rotateButton.backgroundColor = UIColor.green
        
        bottomStackView .addArrangedSubview(rotateButton)
        rotateButton.translatesAutoresizingMaskIntoConstraints = false
        rotateButton.heightAnchor.constraint(equalTo: bottomStackView.heightAnchor).isActive = true
    }
    
    @objc func rotateButtonAction(_ button: UIButton) {
        self.rotateCreditCardGuideOrientation()
    }
    
    private func isConfident(cardInfo: NHNCloudCreditCardInfo) -> Bool {
        guard let validThru = cardInfo.validThru?.monthYear, !validThru.isEmpty else { return false }
        guard let totalNumber = cardInfo.totalNumber, !totalNumber.isEmpty else { return false }

        return true
    }
    
}

extension CustomCreditCardOCRViewController: NHNCloudCreditCardRecognizerDelegate {
    func didDetect(_ cardInfo: NHNCloudCreditCardInfo?, error: Error?) {
        
        if let cardInfo = cardInfo, isConfident(cardInfo: cardInfo) {
            stopRunning()
            
            let message = """
            \(cardInfo.validThru?.monthYear ?? "")
            \(cardInfo.totalNumber ?? "")
            """
            
            let alertController = UIAlertController(title: "", message: message, preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "확인", style: .default, handler: { [weak self] action in
                self?.dismiss()
            }))

            alertController.addAction(UIAlertAction(title: "취소", style: .destructive, handler: { [weak self] _ in
                self?.startRunning()
            }))
            
            present(alertController, animated: true)
        }
    }
}
