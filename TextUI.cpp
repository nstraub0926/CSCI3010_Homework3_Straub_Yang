#include "TextUI.h"

TextUI::TextUI() {}

std::string TextUI::DisplayRoleChoice() {
  std::string role;

  std::cout << "Welcome to BidToBuy. Choose a role to log in (buyer/seller): ";
  std::cin >> role;
  while (role != "buyer" && role != "seller") {
    std::cout << "Please enter a valid input. Choose a role to log in (buyer/seller): ";
    std::cin >> role;
  }
  return role;
}

void TextUI::LoadInData(std::string filename) {
  fstream file(filename, std::ios::in)
  std::string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      stringstream str(line);
      std::string userType;
      getline(str, userType, ',');
      std::string username;
      getline(str, username, ',');
      std::string address;
      getline(str, address, ',');
      std::string phoneNum;
      getline(str, phoneNum, ',');
      std::string accountBalance;
      getline(str, accountBalance, ',');
      std::string avgRating;
      getline(str, avgRating, ',');
      std::string orderCount;
      getline(str, orderCount, ',');
    }
  }
}

std::string TextUI::LogInUsername(std::string role) {
  std::string username;

  std::cout << "Username: ";
  std::cin >> username;
  if (role == "buyer") {
    if (GetBuyer(username) == NULL) {
      std::string option;

      std::cout << "The username is not found in the user list." << std::endl
                << "Create a new account? (c)" << std::endl
                << "Exit the program? (e)" << std::endl
                << "Please enter an option (c/e): ";
      std::cin >> option;
      while (option != "t" && option != "c" && option != "e") {
        std::cout << "Please enter a valid option. Enter your option again (t/c/e): ";
        std::cin >> option;
      }
      if (option == "c") {
        std::string username;
        long phoneNum;
        double accountBalance;

        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Phone Number: ";
        std::cin >> phoneNum;
        std::cout << "Add money to account: ";
        std::cin >> accountBalance;

        MakeNewUser(username, phoneNum, accountBalance, "Buyer");
        return username;
      }
      if (option == "e") {
        throw std::exception();
      }
    } else {
      return username;
    }
  } else {
    if (GetSeller(username) == NULL) {
      std::string option;

      std::cout << "The username is not found in the user list." << std::endl
                << "Create a new account? (c)" << std::endl
                << "Exit the program? (e)" << std::endl
                << "Please enter an option (t/c/e): ";
      std::cin >> option;
      while (option != "t" && option != "c" && option != "e") {
        std::cout << "Please enter a valid option. Enter your option again (t/c/e): ";
        std::cin >> option;
      }
      if (option == "c") {
        std::string username;
        long phoneNum;
        double accountBalance;

        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Phone Number: ";
        std::cin >> phoneNum;
        std::cout << "Add money to account: ";
        std::cin >> accountBalance;

        MakeNewUser(username, phoneNum, accountBalance, "Seller");
        return username;
      }
      if (option == "e") {
        throw std::exception();
      }
    } else {
      return username;
    }
  }
  return "";
}

void TextUI::ViewProductsForSale() {
  for (std::map<int, Product*>::iterator i = _products.begin(); i != _products.end(); i++) {
    std::cout << "product id: " << i->first << ", product name: " << i->second->GetProductName() << std::endl;
  }
}

Seller* TextUI::GetSeller(std::string name) {
  if (_sellers.find(name) != _sellers.end()) {
    return _sellers[name];
  } else {
    return NULL;
  }
}

Buyer* TextUI::GetBuyer(std::string name) {
  if (_buyers.find(name) != _buyers.end()) {
    return _buyers[name];
  } else {
    return NULL;
  }
}

bool TextUI::MakeNewUser(std::string name, long phoneNum, double accountBalance, std::string userType) {
  if (userType == "seller") {
    _sellers.insert(std::make_pair(name, new Seller(name, phoneNum, accountBalance)));
    return true;
  } else if (userType == "buyer") {
    _buyers.insert(std::make_pair(name, new Buyer(name, phoneNum, accountBalance)));
    return true;
  } else {
    return false;
  }
}

bool TextUI::AddNewProduct(Product* p, Seller* seller) {
  int id = GetID();
  if (_products.find(id) == _products.end()) {
    _products.insert(std::make_pair(id, p));
    seller->AddProductForSale(id, p);
    return true;
  } else {
    return false;
  }
}

bool TextUI::AddBidToProduct(int id, double bid, Buyer* buyer) {
  if (_products.find(id) != _products.end()) {
    buyer->AddBidToProduct(_products[id], bid);
    _products[id]->SetCurrentBid(bid, buyer->GetUsername());
    return true;
  } else {
    std::cout << "The product id is not in the list." << std::endl;
    return false;
  }
}

int TextUI::id = 0;
