//
//  ViewController.swift
//  NHNCloudOCR-Sample
//
//  Created by NHNCloud on 2022/11/17.
//

import UIKit
import NHNCloudOCR

let kAppKey:String = "OCR App Key"
let kSecret:String = "OCR Secret"
let kApiKey:String = "OCR API Key"

class ViewController: UIViewController {
    var idCardOCRResult: NHNCloudIDCardInfo? = nil
    @IBOutlet weak var idCardOCRResultView: UIView!
    @IBOutlet weak var idCardOCRResultStackView: UIStackView!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let configuration = NHNCloudOCRConfiguration(appKey: kAppKey, secret: kSecret)
        NHNCloudOCR.initialize(configuration: configuration)

        setIDCardOCRResult(nil)
    }
    
    @IBAction @objc func didTapCreditCardDefaultOCRButton() {
        let viewController = NHNCloudCreditCardRecognizerViewController()
        
        NHNCloudOCR.setCreditCardRecognizerDelegate(self)
        
        present(viewController, animated: true)
    }
    
    @IBAction @objc func didTapCreditCardCustomOCRButton() {
        let viewController = CustomCreditCardOCRViewController()
        
        present(viewController, animated: true)
    }
    
    @IBAction @objc func didTapIDCardDefaultOCRButton() {
        let viewController = DefaultIDCardOCRViewController()
        
        NHNCloudOCR.setIDCardRecognizerDelegate(self)
        
        present(viewController, animated: true)
    }
    
    @IBAction @objc func didTapIDCardCustomOCRButton() {
        let viewController = CustomIDCardOCRViewController()
        viewController.delegate = self

        present(viewController, animated: true)
    }
    
    @IBAction @objc func didTapVerificateAuthenticityIDCardButton() {
        guard let idCardOCRResult = idCardOCRResult else {
            return
        }

        NHNCloudOCR.verificateAuthenticityIDCard(IDCardInfo: idCardOCRResult) { [weak self] result, error in
            
            DispatchQueue.main.async { [weak self] in
                let resultAlertViewController = UIAlertController(
                    title: nil,
                    message: result ? "유효한 신분증" : "유효하지 않은 신분증",
                    preferredStyle: .alert
                )
                
                resultAlertViewController.addAction(UIAlertAction(title: "확인", style: .default))
                self?.present(resultAlertViewController, animated: true)
            }
        }
    }
    
    @IBAction @objc func didTapDeleteIDCardOCRResultButton() {
        setIDCardOCRResult(nil)
    }
    
    @IBAction @objc func didTapVerificateAuthenticityResidentInfoButton() {
        let alertController = UIAlertController(title: "신분증 진위확인", message: "주민등록증 진위확인", preferredStyle: .alert)
        
        alertController.addTextField { textField in
            textField.placeholder = "이름";
        }
        
        alertController.addTextField { textField in
            textField.placeholder = "주민등록번호 13자리";
        }
        
        alertController.addTextField { textField in
            textField.placeholder = "주민등록증 발급일자 yyyMMdd";
        }
        
        alertController.addAction(UIAlertAction(title: "완료", style: .default, handler: { _ in
            let name = alertController.textFields?[0].text ?? ""
            let residentNumber = alertController.textFields?[1].text ?? ""
            let issueDate = alertController.textFields?[2].text ?? ""
            
            NHNCloudOCR.verificateAuthenticityResidentInfo(apiKey: kApiKey, name: name, residentNumber: residentNumber, issueDate: issueDate) { [weak self] result, error in

                DispatchQueue.main.async { [weak self] in
                    let resultAlertViewController = UIAlertController(
                        title: nil,
                        message: result ? "유효한 주민등록증" : "유효하지 않은 주민등록증",
                        preferredStyle: .alert
                    )
                    
                    resultAlertViewController.addAction(UIAlertAction(title: "확인", style: .default))
                    self?.present(resultAlertViewController, animated: true)
                }
            }
        }))
        
        alertController.addAction(UIAlertAction(title: "취소", style: .cancel))

        present(alertController, animated: true)
    }
    
    @IBAction @objc func didTapVerificateAuthenticityDriverInfoButton() {
        let alertController = UIAlertController(title: "신분증 진위확인", message: "운전면허증 진위확인", preferredStyle: .alert)
        
        alertController.addTextField { textField in
            textField.placeholder = "이름";
        }
        
        alertController.addTextField { textField in
            textField.placeholder = "주민등록번호 : 생년월일 + 뒷자리 첫번째 숫자";
        }
        
        alertController.addTextField { textField in
            textField.placeholder = "운전면허번호 12자리";
        }
        
        alertController.addTextField { textField in
            textField.placeholder = "5~6자리 운전면허증 일련번호";
        }
        
        alertController.addAction(UIAlertAction(title: "완료", style: .default, handler: { _ in
            let name = alertController.textFields?[0].text ?? ""
            let residentNumber = alertController.textFields?[1].text ?? ""
            let driverLicenseNumber = alertController.textFields?[2].text ?? ""
            let serialNumber = alertController.textFields?[2].text ?? ""
            
            NHNCloudOCR.verificateAuthenticityDriverInfo(apiKey: kApiKey, name: name, residentNumber: residentNumber, driverLicenseNumber: driverLicenseNumber, serialNum: serialNumber) { [weak self] result, error in
                
                DispatchQueue.main.async { [weak self] in
                    let resultAlertViewController = UIAlertController(
                        title: nil,
                        message: result ? "유효한 운전면허증" : "유효하지 않은 운전면허증",
                        preferredStyle: .alert
                    )
                    
                    resultAlertViewController.addAction(UIAlertAction(title: "확인", style: .default))
                    self?.present(resultAlertViewController, animated: true)
                }
            }
        }))
        
        alertController.addAction(UIAlertAction(title: "취소", style: .cancel))

        present(alertController, animated: true)
    }
}

// 신용카드 인식 Delegate - 기본 제공 UI - NHNCloudCreditCardRecognizerDelegate
extension ViewController: NHNCloudCreditCardRecognizerDelegate {
    func didDetect(_ cardInfo: NHNCloudCreditCardInfo?, error: Error?) {
        print("didDetect NHNCloudCreditCardInfo : \(String(describing: cardInfo))")
        print("didDetect Error : \(String(describing: cardInfo))")
    }
    
    func didDetectCreditCardSecurityEvent(_ event: NHNCloudSecurityEvent) {
        didDetectSecurityEvent(event)
    }
}


// 신분증 인식 Delegate - 기본 제공 UI - NHNCloudIDCardRecognizerDelegate
extension ViewController: NHNCloudIDCardRecognizerDelegate {
    
    func didDetect(_ cardInfo: NHNCloudIDCardInfo?, error: Error?) {
        print("didDetect NHNCloudIDCardInfo : \(String(describing: cardInfo))")
        print("didDetect Error : \(String(describing: cardInfo))")
        
        idCardOCRResult = cardInfo
    }
    
    func idCardRecognizerViewControllerConfirm() {
        setIDCardOCRResult(idCardOCRResult)
    }
    
    func idCardRecognizerViewControllerCancel() {
        setIDCardOCRResult(nil)
    }
    
    func didDetectIDCardSecurityEvent(_ event: NHNCloudSecurityEvent) {
        didDetectSecurityEvent(event)
    }
}

// 신분증 인식 Delegate - 커스텀 구현 UI - CustomIDCardOCRViewControllerDelegate
extension ViewController: CustomIDCardOCRViewControllerDelegate {
    func dismissedByConfirmAction(_ idCardInfo: NHNCloudIDCardInfo) {
        setIDCardOCRResult(idCardInfo)
    }
    
    func dismissedByCancelAction() {
        setIDCardOCRResult(nil)
    }
}


// Private
extension ViewController {
    private func setIDCardOCRResult(_ idCardInfo: NHNCloudIDCardInfo?) {
        idCardOCRResult = idCardInfo

        DispatchQueue.main.async { [weak self] in
            guard let self = self else { return }
            
            for subview in self.idCardOCRResultStackView.subviews {
                subview.removeFromSuperview()
            }

            if let idCardInfo = idCardInfo {
                self.idCardOCRResultView.isHidden = false
                
                if let detectedImage = idCardInfo.detectedImage {
                    let imageView = self.createImageView(detectedImage.image)
                    drawBoundingBoxes(boundingBoxes: idCardInfo.boundingBoxes, over: imageView)
                    self.idCardOCRResultStackView.addArrangedSubview(imageView)
                }
                
                switch idCardInfo.type {
                case .driver:
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.driverLicenseNumber?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.name?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.residentNumber?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.serialNumber?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.licenseType?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.condition?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.issueDate?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.issuer?.value))
                case .resident:
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.name?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.residentNumber?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.issueDate?.value))
                    self.idCardOCRResultStackView.addArrangedSubview(self.createLabel(idCardInfo.issuer?.value))
                @unknown default:
                    return
                }
            } else {
                self.idCardOCRResultView.isHidden = true
            }
        }
    }
    
    private func createLabel(_ value: String?) -> UILabel {
        let label = UILabel()
        
        label.text = value
        label.textColor = .gray
        label.textAlignment = .center
        
        return label
    }
    
    private func createImageView(_ value: UIImage?) -> UIImageView {
        let imageView = UIImageView(image: value)
        
        imageView.contentMode = .scaleAspectFit
        
        NSLayoutConstraint.activate([
            imageView.widthAnchor.constraint(equalTo: imageView.heightAnchor, multiplier: (value?.size.width ?? 1.0) / (value?.size.height ?? 1.0))
        ])
        
        return imageView
    }
    
    private func drawBoundingBoxes(boundingBoxes: [NSValue]?, over imageView: UIImageView) {
        UIGraphicsBeginImageContextWithOptions(imageView.frame.size, false, 0.0);
        guard let context = UIGraphicsGetCurrentContext(),
              let boundingBoxes = boundingBoxes else { return }
        
        imageView.image?.draw(in: CGRect(x: 0, y: 0, width: imageView.frame.size.width, height: imageView.frame.size.height))
        
        for rectValue in boundingBoxes {
            let boundingBox = dividedRect(rect: rectValue.cgRectValue, scale: UIScreen.main.scale)
    
            context.setStrokeColor(UIColor.orange.cgColor)
            context.setLineWidth(5.0)
            context.stroke(boundingBox)
            
        }
        
        let newImage = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        
        imageView.image = newImage
    }
    
    private func dividedRect(rect: CGRect, scale: CGFloat) -> CGRect {
        return CGRect(x: rect.origin.x / scale, y: rect.origin.y / scale,
                      width: rect.size.width / scale, height: rect.size.height / scale)
    }
    
    private func didDetectSecurityEvent(_ event: NHNCloudSecurityEvent) {
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
            let alert = UIAlertController(title: title,
                                          message: "Capture!",
                                          preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "OK",
                                          style: .default))
            
            self.presentedViewController?.present(alert, animated: true)
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
