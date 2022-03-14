#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "Product.h"
#include "User.h"

class TextUI {
 public:
  static TextUI& GetInstance() {
    static TextUI instance;
    return instance;
  };
  std::string DisplayRoleChoice();
  void LoadInUserData(std::string filename);
  void LoadInBidsData(std::string filename);
  std::string LogInUsername(std::string role);
  void DisplayForBuyer(std::string name);
  void DisplayForSeller(std::string name);
  void ViewProductsForSale();
  void ViewHistoryProducts();
  Seller* GetSeller(std::string name);
  Buyer* GetBuyer(std::string name);
  bool MakeNewUser(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount, std::string userType);
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
  std::map<std::string, std::vector<std::string> > _productCategories;
  std::map<std::string, Seller*> _sellers;  // <username, pointer to the seller>
  std::map<std::string, Buyer*> _buyers;    // <username, pointer to the buyer>
  std::map<int, Product*> _products;        // <product id, pointer to the product>
  std::vector<Product*> _historyOrders;
};
