//
//  CustomIDCardOCRViewController.swift
//  NHNCloudOCR-Sample
//
//  Created by NHN on 2023/06/26.
//

import NHNCloudOCR

protocol CustomIDCardOCRViewControllerDelegate: NSObject {
    func dismissedByConfirmAction(_ idCardInfo: NHNCloudIDCardInfo)
    func dismissedByCancelAction()
}

class CustomIDCardOCRViewController: NHNCloudIDCardRecognizerServiceViewController {
    var customView: IDCardOCRCustomView? = nil
    var customNavigationBar: UINavigationBar? = nil
    weak var delegate: CustomIDCardOCRViewControllerDelegate? = nil
    
    var idCardInfo: NHNCloudIDCardInfo? = nil
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NHNCloudOCR.setIDCardRecognizerDelegate(self)
        
        self.navigationController?.navigationBar.isHidden = true
        self.navigationController?.navigationBar.barStyle = .black
        
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
    
    override func didUpdateIDCardGuide(_ rect: CGRect) {
        super.didUpdateIDCardGuide(rect)
        
        self.customView?.updateGuide(rect: rect)
        
    }

    override func imageDidDetect(_ detected: Bool) {
        if detected {
            self.customView?.showEffect()
        }
    }
}

//MARK: - Custom UI
extension CustomIDCardOCRViewController {
    
    func setCustomUI() {
        self.setCustomView()
        self.setCustomNavigation()
        self.setCustomBottomBar()
    }
    
    func setCustomView() {
        self.customView = IDCardOCRCustomView(frame: self.view.frame, dimmedColor: UIColor(red: 0, green: 0, blue: 0, alpha: 0.5))
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
        
        let navigationItem = UINavigationItem(title: "ID-Card")
        self.customNavigationBar?.setItems([navigationItem], animated: true)
        
        let closeButton = UIButton(type: .custom)
        closeButton.setTitle("X", for: .normal)
        closeButton.addTarget(self, action: #selector(closeButtonAction(_:)), for: .touchUpInside)
        closeButton.frame = CGRect(x: 0, y: 0, width: 44, height: 44)
        let rightBarButton = UIBarButtonItem(customView: closeButton)
        navigationItem.rightBarButtonItem = rightBarButton
        
        self.view.addSubview(self.customNavigationBar!)
        
        self.customNavigationBar?.translatesAutoresizingMaskIntoConstraints = false
        self.customNavigationBar?.topAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.topAnchor).isActive = true
        self.customNavigationBar?.leadingAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.leadingAnchor).isActive = true
        self.customNavigationBar?.trailingAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.trailingAnchor).isActive = true
        self.customNavigationBar?.heightAnchor.constraint(equalToConstant: 56).isActive = true
    }
    
    @objc func closeButtonAction(_ button: UIButton) {
        dismiss { [weak self] in
            self?.delegate?.dismissedByCancelAction()
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
    }
    
    private func isConfident(_ cardInfo: NHNCloudCreditCardInfo) -> Bool {
        
        if let numbers = cardInfo.numbers {
            
            if numbers.count < 3 {
                return false
            }
            
            var totalNumberCount = 0;
            for number in numbers {
                if number.conf.floatValue < 0.3 {
                    return false
                }
                totalNumberCount += number.value.count
            }
            
            if totalNumberCount < 15 {
                return false
            }
        }
        
        if let valThru = cardInfo.validThru {
            if valThru.monthYear.isEmpty {
                return false
            }
            
            if valThru.conf.floatValue < 0.3 {
                return false
            }
        }
        return true
    }
    
    private func isConfident(cardInfo: NHNCloudIDCardInfo) -> Bool {
        guard isValidInfoValue(cardValue: cardInfo.name) else { return false }
        
        guard isValidInfoValue(cardValue: cardInfo.residentNumber) else { return false }
        guard cardInfo.residentNumber?.value.count == 14 else { return false }

        guard isValidInfoValue(cardValue: cardInfo.issueDate) else { return false }
        guard isValidInfoValue(cardValue: cardInfo.issuer) else { return false }
        
        
        if (cardInfo.type == .driver) {
            guard isValidInfoValue(cardValue: cardInfo.driverLicenseNumber) else { return false }
            
            guard cardInfo.driverLicenseNumber?.value.count == 12 || cardInfo.driverLicenseNumber?.value.count == 15 else { return false }
            
            guard isValidInfoValue(cardValue: cardInfo.licenseType) else { return false }
            guard isValidInfoValue(cardValue: cardInfo.serialNumber) else { return false }
        }
        
        return true
    }
    
    private func isValidInfoValue(cardValue: NHNCloudIDCardValue?) -> Bool {
        guard let cardValue = cardValue, !cardValue.value.isEmpty, cardValue.conf.doubleValue >= 0.4 else {
            return false
        }
        
        return true
    }
}

extension CustomIDCardOCRViewController: NHNCloudIDCardRecognizerDelegate {
    func didDetect(_ cardInfo: NHNCloudIDCardInfo?, error: Error?) {

        if let cardInfo = cardInfo, isConfident(cardInfo: cardInfo) {
            stopRunning()
            
            var message: String
            
            switch cardInfo.type {
            case .driver:
                message = """
                \(cardInfo.driverLicenseNumber?.value ?? "")
                \(cardInfo.name?.value ?? "")
                \(cardInfo.residentNumber?.value ?? "")
                \(cardInfo.serialNumber?.value ?? "")
                \(cardInfo.licenseType?.value ?? "")
                \(cardInfo.condition?.value ?? "")
                \(cardInfo.issueDate?.value ?? "")
                \(cardInfo.issuer?.value ?? "")
                """
            case .resident:
                message = """
                \(cardInfo.name?.value ?? "")
                \(cardInfo.residentNumber?.value ?? "")
                \(cardInfo.issueDate?.value ?? "")
                \(cardInfo.issuer?.value ?? "")
                """
            @unknown default:
                message = ""
            }
            
            let alertController = UIAlertController(title: "", message: message, preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "확인", style: .default, handler: { [weak self] action in
                self?.dismiss { [weak self] in
                    self?.delegate?.dismissedByConfirmAction(cardInfo)
                }
            }))

            alertController.addAction(UIAlertAction(title: "취소", style: .destructive, handler: { [weak self] _ in
                self?.startRunning()
            }))
            
            present(alertController, animated: true)
        }
    }
}
