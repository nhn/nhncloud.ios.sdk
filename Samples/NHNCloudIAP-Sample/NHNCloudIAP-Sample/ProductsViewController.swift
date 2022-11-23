//
//  ProductsViewController.swift
//  NHNCloudIAP-Sample
//
//  Created by NHNCloud on 2022/11/21.
//

import UIKit
import NHNCloudIAP

class ProductsViewController: UIViewController {
    @IBOutlet weak var tableView: UITableView!

    var products: [NHNCloudProduct] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()

        requestProducts()
    }
    
    // 상품 목록 조회
    private func requestProducts() {
        NHNCloudIAP.requestProducts { [weak self] response, error in
            if let error = error {
                self?.showAlert(title: nil, message: error.localizedDescription)
                return
            }
            
            
            self?.products = response?.products ?? []
            
            DispatchQueue.main.async {
                self?.tableView.reloadData()
            }
        }
    }
    
    // 상품 구매
    private func purchase(product: NHNCloudProduct, payload: String?) {
        NHNCloudIAP.purchase(product: product, payload: payload)
    }
}

extension ProductsViewController: UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return products.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let product = products[indexPath.row];
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "ProductCell", for: indexPath) as! ProductCell
        
        
        cell.identifierLabel.text = "\(product.productName ?? "")\n\(product.productIdentifier)"
        cell.identifierLabel.numberOfLines = 2

        cell.nameLabel.text = "\(product.localizedTitle ?? "")\n\(product.localizedDescription ?? "")"
        cell.nameLabel.numberOfLines = 2
        
        cell.priceLabel.text = product.localizedPrice
        
        return cell;
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let product = products[indexPath.row];
        
        purchase(product: product, payload: nil)
    }
}

extension ProductsViewController {
    func showAlert(title: String?, message: String?) {
        let alertViewController = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alertViewController.addAction(UIAlertAction(title: "확인", style: .default))
        
        DispatchQueue.main.async { [weak self] in
            self?.present(alertViewController, animated: true)
        }
    }
}
