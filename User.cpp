#include "User.h"

// displays 0 messages for empty messagebox, else iterates through all possible messages to read 
// and asks for user to choose which message to respond to via an option number
void User::ReadMessage(std::string& replyTo, int& productID) {
  int size = _messagebox.size();
  std::cout << "You have " << size << " message(s)." << std::endl;
  if (size == 0) {
    return;
  }
  for (int i = 0; i < size; i++) {
    std::cout << i + 1 << ". From " << _messagebox[i].GetSender();
    if (_messagebox[i].IsConfirmationMessage()) {
      std::cout << ", this is a confirmation message for purchasing a product (product id " << _messagebox[i].GetProductID() << ")." << std::endl;
    }
  }
  std::cout << "Which message do you want to read? Or enter (e) to exit." << std::endl;
  if (size == 1) {
    std::cout << "Please enter an option (1/e): ";
  } else {
    std::cout << "Please enter an option (1-" << size << "/e): ";
  }
  std::string option;
  std::cin >> option;
  if (option == "e") {
    return;
  }
  while (stoi(option) > size || stoi(option) < 1) {
    std::cout << "Please enter a valid option. Enter the option again (1-" << size << "): ";
    std::cin >> option;
  }
  std::cout << "From: " << _messagebox[stoi(option) - 1].GetSender() << std::endl;
  std::cout << _messagebox[stoi(option) - 1].GetContent() << std::endl;
  if (_messagebox[stoi(option) - 1].IsConfirmationMessage()) {
    replyTo = _messagebox[stoi(option) - 1].GetSender();
    productID = _messagebox[stoi(option) - 1].GetProductID();
  } else {
    std::cout << "Do you want to reply? (yes/no): ";
    std::string replyOrNot;
    std::cin >> replyOrNot;
    while (replyOrNot != "yes" && replyOrNot != "no") {
      std::cout << "Please enter a valid option. Enter the option again (yes/no): ";
      std::cin >> replyOrNot;
    }
    if (replyOrNot == "yes") {
      replyTo = _messagebox[stoi(option) - 1].GetSender();
    } else {
      replyTo = "";
    }
  }
  _messagebox.erase(_messagebox.begin() + (stoi(option) - 1));
}

// returns will NULL print statement if there are no completed purchases made by user, else iterates through 
// all potential user's to rate and requests the user rate one based off their option number
std::string User::GetUserToRate() {
  int size = _userToRate.size();
  if (size == 0) {
    std::cout << "There is no user to rate." << std::endl;
    return "";
  }

  std::cout << "Please choose a user to rate:" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << i + 1 << ". " << _userToRate[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Please choose an option (1-" << size << "): ";
  std::string option;
  std::cin >> option;
  while (stoi(option) > size || stoi(option) < 1) {
    std::cout << "Please enter a valid option. Enter the option again (1-" << size << "): ";
    std::cin >> option;
  }
  std::string userToRate = _userToRate[stoi(option) - 1];
  _userToRate.erase(_userToRate.begin() + (stoi(option) - 1));
  return userToRate;
}

void Seller::AddProductForSale(int productID, Product* product) {
  _productlist.insert(std::make_pair(productID, product));
}

void Seller::ViewProductList() {
  for (std::map<int, Product*>::iterator i = _productlist.begin(); i != _productlist.end(); i++) {
    std::cout << "Product id: " << i->first << ", product name: " << i->second->GetProductName() << ", base price: " << i->second->GetBasePrice() << ", current highest bid: " << i->second->GetHighestBidInfo().first << std::endl;
  }
}

// returns seller's biddable product info, parameter being passed in is the product's ID
Product* Seller::GetProductInfo(int productID) {
  if (_productlist.find(productID) != _productlist.end()) {
    return _productlist[productID];
  } else {
    return NULL;
  }
}

// adding a product to a seller's history list
void Seller::AddToHistoryProducts(int productID) {
  Product* p = _productlist[productID];
  _productlist.erase(productID);
  _historyProducts.push_back(p);
}

// pushes all bids made by user to bidsHistory vector
void Buyer::AddBidToProduct(std::string name, double bid) {
  _bidsHistory[name].push_back(bid);
}

// iterates through all completed orders and displays product name and final bid
void Buyer::ViewHistoryOrders() {
  int size = _historyOrders.size();
  for (int i = 0; i < size; i++) {
    std::cout << "Product name: " << _historyOrders[i]->GetProductName() << ", bid: " << _historyOrders[i]->GetHighestBidInfo().first << std::endl;
  }
}