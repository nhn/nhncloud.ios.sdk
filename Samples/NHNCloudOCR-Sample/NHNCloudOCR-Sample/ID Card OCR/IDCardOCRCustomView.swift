//
//  IDCardOCRCustomView.swift
//  NHNCloudOCR-Sample
//
//  Created by NHN on 2023/06/26.
//

import UIKit

class IDCardOCRCustomView: UIView {

    var dimmedColor: UIColor = UIColor.clear
    var idCardGuide: CGRect = CGRect.zero
    var captureEffect: Bool = false
    var debugLabel: UILabel = UILabel(frame: .zero)
    
    let bottomHeight: CGFloat = 60;
    
    func updateGuide(rect: CGRect) {
        self.idCardGuide = rect
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
        
        var pt = CGPoint(x: self.idCardGuide.origin.x - half,
                         y: self.idCardGuide.origin.y - half)
        path.move(to: pt)
        
        pt = CGPoint(x: pt.x + width,
                     y: pt.y)
        path.addLine(to: pt)
        
        pt = CGPoint(x: self.idCardGuide.origin.x + self.idCardGuide.size.width - width + half,
                     y: pt.y);
        path.move(to: pt)
        
        pt = CGPoint(x: pt.x + width,
                     y: pt.y);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: pt.y + width);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: self.idCardGuide.origin.y + self.idCardGuide.size.height - width + half);
        path.move(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: pt.y + width);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x - width,
                     y: pt.y);
        path.addLine(to: pt)
         
        pt = CGPoint(x: self.idCardGuide.origin.x + width - half,
                     y: pt.y);
        path.move(to: pt)
               
        pt = CGPoint(x: pt.x - width,
                     y: pt.y);
        path.addLine(to: pt)
        
        pt = CGPoint(x: pt.x,
                     y: pt.y - width);
        path.addLine(to: pt)

        pt = CGPoint(x: pt.x,
                     y: self.idCardGuide.origin.y + width - half);
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
        
        let intersectionRect = rect.intersection(self.idCardGuide)
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
        
                
        var pt = CGPoint(x: self.idCardGuide.origin.x - half,
                         y: self.idCardGuide.origin.y - half);
        path.move(to: pt)
          
        
        pt = CGPoint(x: self.idCardGuide.origin.x + self.idCardGuide.size.width + half,
                     y: self.idCardGuide.origin.y - half);
        path.addLine(to: pt)
        
        pt = CGPoint(x: self.idCardGuide.origin.x + self.idCardGuide.size.width + half,
                     y: self.idCardGuide.origin.y + self.idCardGuide.size.height + half);
        path.addLine(to: pt)
        
        
        pt = CGPoint(x: self.idCardGuide.origin.x - half,
                     y: self.idCardGuide.origin.y + self.idCardGuide.size.height + half);
        path.addLine(to: pt)
        
        
        pt = CGPoint(x: self.idCardGuide.origin.x - half,
                     y: self.idCardGuide.origin.y - half);
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
