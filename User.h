#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Message.h"
#include "Product.h"

class User {
 public:
  User(std::string name, long phoneNum, double accountBalance) : _username(name), _phoneNum(phoneNum), _accountBalance(accountBalance){};
  std::string GetUsername() { return _username; };
  void UpdateUsername(std::string newName) { _username = newName; };
  std::string GetAddress() { return _address; };
  void UpdateAddress(std::string newAddress) { _address = newAddress; };
  long GetPhoneNum() { return _phoneNum; };
  void UpdatePhoneNum(long newPhoneNum) { _phoneNum = newPhoneNum; };
  double GetAccountBalance() { return _accountBalance; };
  void UpdateAccountBalance(double newBalance) { _accountBalance += newBalance; };
  void ReadMessage();
  bool SendMessage(std::string sendTo, std::string content);
  double GetRate() { return _rate; };
  void RateUser(std::string username, double rate);

 private:
  std::string _username;
  std::string _address;
  long _phoneNum;
  double _accountBalance;
  std::vector<Message> _messagebox;
  double _rate;
};

class Seller : public User {
 public:
  Seller(std::string name, long phoneNum, double accountBalance) : User(name, phoneNum, accountBalance){};
  void AddProductForSale(int productID, Product* product);
  void ViewProductList();
  void SetProductStatus(int productID, bool status);
  Product* GetProductInfo(int productID);

 private:
  std::map<int, Product*> _productlist;
  std::vector<Product*> _historyProducts;
};

class Buyer : public User {
 public:
  Buyer(std::string name, long phoneNum, double accountBalance) : User(name, phoneNum, accountBalance){};
  void AddBidToProduct(Product* product, double bid);

 private:
  std::map<Product*, double> _bidsOverview;
  std::vector<Product*> _historyOrders;
};