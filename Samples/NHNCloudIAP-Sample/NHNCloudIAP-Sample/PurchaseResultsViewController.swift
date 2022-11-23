//
//  PurchaseResultsViewController.swift
//  NHNCloudIAP-Sample
//
//  Created by NHNCloud on 2022/11/21.
//

import UIKit
import NHNCloudIAP

class PurchaseResultsViewController: UIViewController {
    @IBOutlet weak var tableView: UITableView!

    var consumablePurchases: [NHNCloudPurchaseResult] = []
    var isConsumable: Bool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        tableView.reloadData()
    }
    
}

extension PurchaseResultsViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return consumablePurchases.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let consumablePurchase = consumablePurchases[indexPath.row];
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "PurchaseCell", for: indexPath) as! PurchaseCell
        
        
        cell.titleLabel.text = "[\(consumablePurchase.storeCode)] \(consumablePurchase.paymentSeq)"
        cell.priceLabel.text = String(format: "%@ %.2f", consumablePurchase.currency, consumablePurchase.price.floatValue)
        cell.productLabel.text = "\(consumablePurchase.productIdentifier) \(consumablePurchase.productSeq)"
        cell.timeLabel.text = Date(timeIntervalSince1970: consumablePurchase.expiryTime / 1000).toString


        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {

        guard isConsumable else {
            return
        }

        let consumablePurchase = consumablePurchases[indexPath.row];
        
        let alertController = UIAlertController(title: consumablePurchase.paymentSeq, message: consumablePurchase.productIdentifier, preferredStyle: .alert)
        
        alertController.addAction(UIAlertAction(title: "소비", style: .destructive, handler: { _ in
            
            // 상품 소비
            NHNCloudIAP.consume(result: consumablePurchase) { [weak self] error in
                if let _ = error {
                    return
                }
                
                self?.consumablePurchases.remove(at: indexPath.row)
                
                DispatchQueue.main.async {
                    self?.tableView.reloadData()
                }
            }
        }))
        
        alertController.addAction(UIAlertAction(title: "취소", style: .default))
        
        present(alertController, animated: true)
    }
}
