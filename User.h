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
  void ReadMessage(std::string& replyTo, int& productID);
  void ReceiveMessage(Message message) { _messagebox.push_back(message); };
  std::string GetUserToRate();
  double GetRate() { return _rateTotal / _rateCount; };
  void AddNewRate(double newRate) {
    _rateTotal += newRate;
    _rateCount++;
  };

 private:
  std::string _username;
  std::string _address;
  long _phoneNum;
  double _accountBalance;
  std::vector<Message> _messagebox;
  std::vector<std::string> _userToRate;
  double _rateTotal;
  int _rateCount;
};

class Seller : public User {
 public:
  Seller(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount) : User(name, address, phoneNum, accountBalance, rateTotal, rateCount){};
  void AddProductForSale(int productID, Product* product);
  void ViewProductList();
  int GetProductlistSize() { return _productlist.size(); };
  Product* GetProductInfo(int productID);
  void AddToHistoryProducts(int productID);

 private:
  std::map<int, Product*> _productlist;
  std::vector<Product*> _historyProducts;
};

class Buyer : public User {
 public:
  Buyer(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount) : User(name, address, phoneNum, accountBalance, rateTotal, rateCount){};
  void AddBidToProduct(std::string, double bid);
  std::map<std::string, std::vector<double> > GetBidsHistory() { return _bidsHistory; }
  void ViewHistoryOrders();
  void AddToHistoryOrders(Product* p) { _historyOrders.push_back(p); };

 private:
  std::map<std::string, std::vector<double> > _bidsHistory;
  std::vector<Product*> _historyOrders;
};