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
  void CreateNewAccount(std::string role, std::string username);
  void DisplayForBuyer(Buyer* b);
  void DisplayForSeller(Seller* s);
  void ViewProductsForSale();
  void ViewHistoryProducts();
  void CheckMessagebox(std::string role, std::string name);
  void SendMessage(std::string* sender, std::string* receiver, std::string receiverRole, std::string content);
  void SendMessage(std::string* sender, std::string* receiver, std::string receiverRole, std::string content, int productID);
  Seller* GetSeller(std::string name);
  Buyer* GetBuyer(std::string name);
  bool MakeNewUser(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount, std::string userType);
  bool AddNewProduct(Product* p, Seller* seller);
  void WriteToUsersCSV();
  void WriteToBidsCSV();
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
  std::map<int, Product*> _pendingProducts;
  std::vector<Product*> _historyOrders;
};
