#pragma once

#include <iostream>
#include <map>

#include "Product.h"
#include "User.h"

class TextUI {
 public:
  static TextUI& GetInstance() {
    static TextUI instance;
    return instance;
  };
  std::string DisplayRoleChoice();
  bool LogInUsername(std::string role);
  void DisplayForSeller();
  void DisplayForBuyer();
  void ViewProductsForSale();
  void ViewHistoryProducts();
  Seller* GetSeller(std::string name);
  Buyer* GetBuyer(std::string name);
  bool MakeNewUser(std::string name, long phoneNum, double accountBalance, std::string userType);
  bool AddNewProduct(Product* p, Seller* seller);
  bool AddBidToProduct(int id, double bid, Buyer* buyer);
  static int GetID() {
    id++;
    return id;
  }

  TextUI(Textbooks const&) = delete;
  void operator=(TextUI const&) = delete;

 private:
  TextUI();
  static int id;
  std::map<std::string, Seller*> _sellers;  // <username, pointer to the seller>
  std::map<std::string, Buyer*> _buyers;    // <username, pointer to the buyer>
  std::map<int, Product*> _products;        // <product id, pointer to the product>
  std::vector<Product*> _historyOrders;
};