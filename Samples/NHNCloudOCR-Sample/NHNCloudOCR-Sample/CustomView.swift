//
//  CustomView.swift
//  NHNCloudOCR-Sample
//
//  Created by NHNCloud on 2022/11/17.
//

import UIKit

class CustomView: UIView {

    var dimmedColor: UIColor = UIColor.clear
    var creditCardGuide: CGRect = CGRect.zero
    var captureEffect: Bool = false
    var debugLabel: UILabel = UILabel(frame: .zero)
    
    let bottomHeight: CGFloat = 60;
    
    func updateGuide(rect: CGRect) {
        self.creditCardGuide = rect
        self.setNeedsDisplay()
    }
    
    convenience init(frame: CGRect, dimmedColor: UIColor) {
        self.init(frame: frame)
        self.isOpaque = false
        self.dimmedColor = dimmedColor
    }
    
    func edge() {
        let thickness: CGFloat = 6
        let half: CGFloat = thickness / 2
        let width: CGFloat = 30
        let color = UIColor.white
        let path = UIBezierPath()
        
        var pt = CGPoint(x: self.creditCardGuide.origin.x - half,
                         y: self.creditCardGuide.origin.y - half)
        path.move(to: pt)
        
        pt = CGPoint(x: pt.x + width,
                     y: pt.y)
        path.addLine(to: pt)
        
        pt = CGPoint(x: self.creditCardGuide.origin.x + self.creditCardGuide.size.width - width + half,
                     y: pt.y);
        path.move(to: pt)
        
        pt = CGPoint(x: pt.x + width,
                     y: pt.y);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: pt.y + width);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: self.creditCardGuide.origin.y + self.creditCardGuide.size.height - width + half);
        path.move(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: pt.y + width);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x - width,
                     y: pt.y);
        path.addLine(to: pt)
         
        pt = CGPoint(x: self.creditCardGuide.origin.x + width - half,
                     y: pt.y);
        path.move(to: pt)
               
        pt = CGPoint(x: pt.x - width,
                     y: pt.y);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: pt.y - width);
        path.addLine(to: pt)

        pt = CGPoint(x: pt.x,
                     y: self.creditCardGuide.origin.y + width - half);
        path.move(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: pt.y - width - half);
        path.addLine(to: pt)
        
        color.set()
        path.lineWidth = thickness
        path.stroke()
    }
    
    override func draw(_ rect: CGRect) {
        self.dimmedColor.setFill()
        UIRectFill(rect)
        
        let intersectionRect = rect.intersection(self.creditCardGuide)
        UIColor.clear.setFill()
        UIRectFill(intersectionRect)
        
        edge()
        
        if self.captureEffect {
            self.effect()
        }
    }
    
    func effect() {
        
        let thickness: CGFloat = 6
        let half: CGFloat = thickness / 2
        let color = UIColor.yellow
        let path = UIBezierPath()
        
                
        var pt = CGPoint(x: self.creditCardGuide.origin.x - half,
                         y: self.creditCardGuide.origin.y - half);
        path.move(to: pt)
          
        
        pt = CGPoint(x: self.creditCardGuide.origin.x + self.creditCardGuide.size.width + half,
                     y: self.creditCardGuide.origin.y - half);
        path.addLine(to: pt)
        
        pt = CGPoint(x: self.creditCardGuide.origin.x + self.creditCardGuide.size.width + half,
                     y: self.creditCardGuide.origin.y + self.creditCardGuide.size.height + half);
        path.addLine(to: pt)
        
        
        pt = CGPoint(x: self.creditCardGuide.origin.x - half,
                     y: self.creditCardGuide.origin.y + self.creditCardGuide.size.height + half);
        path.addLine(to: pt)
        
        
        pt = CGPoint(x: self.creditCardGuide.origin.x - half,
                     y: self.creditCardGuide.origin.y - half);
        path.addLine(to: pt)
        
        color.set()
        path.lineWidth = thickness
        path.stroke()
    }
    
    func showEffect() {
        DispatchQueue.main.async {
            self.captureEffect = true
            self.setNeedsDisplay()
            
            self.perform(#selector(self.hideEffect), with: nil, afterDelay: 1.0)
        }
    }
    
    @objc func hideEffect() {
        DispatchQueue.main.async {
            self.captureEffect = false
            self.setNeedsDisplay()
        }
    }
}
/*
extension CustomView {
    func setBottomBar() {
        
        let bottomView = UIView(frame: CGRect(x: 0, y: 0, width: self.frame.size.width, height: self.bottomHeight))
        bottomView.backgroundColor = UIColor.black
        
        self.addSubview(bottomView)
        
        bottomView.translatesAutoresizingMaskIntoConstraints = false
        bottomView.heightAnchor.constraint(equalToConstant: self.bottomHeight).isActive = true
        bottomView.bottomAnchor.constraint(equalTo: self.bottomAnchor).isActive = true
        bottomView.leadingAnchor.constraint(equalTo: self.leadingAnchor).isActive = true
        bottomView.trailingAnchor.constraint(equalTo: self.trailingAnchor).isActive = true
        
        let bottomStackView = UIStackView()
        bottomStackView.axis = .horizontal
        bottomStackView.distribution = .fillEqually
        bottomStackView.alignment = .fill
        bottomStackView.spacing = 30
        
        bottomView .addSubview(bottomStackView)
        
        bottomStackView.translatesAutoresizingMaskIntoConstraints = false
        bottomStackView.heightAnchor.constraint(equalTo: bottomView.heightAnchor).isActive = true
        bottomStackView.topAnchor.constraint(equalTo: bottomView.topAnchor).isActive = true
        bottomStackView.bottomAnchor.constraint(equalTo: bottomView.bottomAnchor).isActive = true
        bottomStackView.leadingAnchor.constraint(equalTo: bottomView.leadingAnchor).isActive = true
        bottomStackView.trailingAnchor.constraint(equalTo: bottomView.trailingAnchor).isActive = true
        
        let rotateButton = UIButton(type: .roundedRect)
        rotateButton.addTarget(self, action: #selector(rotateButtonAction(_:)), for: .touchUpInside)
        rotateButton.setTitle("Rotate", for: .normal)
        rotateButton.isExclusiveTouch = true
        rotateButton.backgroundColor = UIColor.green
        
        let torchButton = UIButton(type: .roundedRect)
        torchButton.addTarget(self, action: #selector(torchButtonAction(_:)), for: .touchUpInside)
        torchButton.setTitle("Torch", for: .normal)
        torchButton.isExclusiveTouch = true
        torchButton.backgroundColor = UIColor.green
        
        bottomStackView .addArrangedSubview(rotateButton)
        rotateButton.translatesAutoresizingMaskIntoConstraints = false
        rotateButton.heightAnchor.constraint(equalTo: bottomStackView.heightAnchor).isActive = true
        
        bottomStackView .addArrangedSubview(torchButton)
        torchButton.translatesAutoresizingMaskIntoConstraints = false
        torchButton.heightAnchor.constraint(equalTo: bottomStackView.heightAnchor).isActive = true
    }
    
    @objc func rotateButtonAction(_ button: UIButton) {
        NHNCloudOCR.creditCardRecognizerViewController()?.rotateCreditCardGuideOrientation()
    }
    
    @objc func torchButtonAction(_ button: UIButton) {
        if NHNCloudOCR.creditCardRecognizerViewController()?.isEnableTorchMode() == true {
            NHNCloudOCR.creditCardRecognizerViewController()?.disableTorchMode()
        } else {
            NHNCloudOCR.creditCardRecognizerViewController()?.enableTorchMode()
        }
    }
}
*/
