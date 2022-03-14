#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Message.h"
#include "Product.h"

class User {
 public:
  User(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount) : _username(name), _address(address), _phoneNum(phoneNum), _accountBalance(accountBalance), _rateTotal(rateTotal), _rateCount(rateCount){};
  std::string GetUsername() { return _username; };
  void UpdateUsername(std::string newName) { _username = newName; };
  std::string GetAddress() { return _address; };
  void UpdateAddress(std::string newAddress) { _address = newAddress; };
  long GetPhoneNum() { return _phoneNum; };
  void UpdatePhoneNum(long newPhoneNum) { _phoneNum = newPhoneNum; };
  double GetAccountBalance() { return _accountBalance; };
  void UpdateAccountBalance(double newBalance) { _accountBalance += newBalance; };
  bool MessageboxIsEmpty() { return _messagebox.empty(); };
  void ReadMessage(std::string& replyTo);
  void ReceiveMessage(Message message);
  double GetRate() { return _rateTotal / _rateCount; };
  void AddNewRate(double newRate) {
    _rateTotal += newRate;
    _rateCount++;
  };
  void RateUser(std::string username, double rate);

 private:
  std::string _username;
  std::string _address;
  long _phoneNum;
  double _accountBalance;
  std::vector<Message> _messagebox;
  double _rateTotal;
  int _rateCount;
};

class Seller : public User {
 public:
  Seller(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount) : User(name, address, phoneNum, accountBalance, rateTotal, rateCount){};
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
  Buyer(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount) : User(name, address, phoneNum, accountBalance, rateTotal, rateCount){};
  void AddBidToProduct(Product* product, double bid);

 private:
  std::map<Product*, double> _bidsOverview;
  std::vector<Product*> _historyOrders;
};