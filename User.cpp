#include "User.h"

void User::ReadMessage(std::string& replyTo) {
  int size = _messagebox.size();
  std::cout << "You have " << size << " message(s)." << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << i + 1 << ". From " << _messagebox[i].GetSender() << std::endl;
  }
  std::cout << "Which message do you want to read? Or enter (e) to exit." << std::endl;
  std::cout << "Please enter an option (1-" << size << "/e): ";
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
  _messagebox.erase(_messagebox.begin() + (stoi(option) - 1));
}

void User::ReceiveMessage(Message message) {
  _messagebox.push_back(message);
}

void Seller::AddProductForSale(int productID, Product* product) {
  _productlist.insert(std::make_pair(productID, product));
}

void Seller::ViewProductList() {
  for (std::map<int, Product*>::iterator i = _productlist.begin(); i != _productlist.end(); i++) {
    std::cout << "product id: " << i->first << ", product name: " << i->second->GetProductName() << std::endl;
  }
}

Product* Seller::GetProductInfo(int productID) {
  if (_productlist.find(productID) != _productlist.end()) {
    return _productlist[productID];
  } else {
    return NULL;
  }
}

void Buyer::AddBidToProduct(Product* product, double bid) {
  _bidsOverview.insert(std::make_pair(product, bid));
}
