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

void TextUI::DisplayForBuyer(std::string name) {
  std::string option;
  std::cout << "Welcome buyer! Please choose from the following list of buyer options: " << std::endl;
  std::cout << "1. View/Bid-On Products" << std::endl;
  std::cout << "2. View/Send Messages" << std::endl;
  std::cout << "3. Check Account Balance" << std::endl;
  std::cout << "4. Update User Info" << std::endl;
  std::cout << "5. View Bid History" << std::endl;
  std::cout << "6. View Purchased Products" << std::endl;
  std::cout << "7. Exit the program?" << std::endl;
  std::cin >> option;
  
  while (option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6' && option != '7') {
    std::cout << "Please enter a valid option. Enter your option again (1-7): ";
    std::cin >> option;
  }
  
  if (option == 1) {
    std::cout << "Here's a list of all currently biddable products: " << std::endl;
  }
  if (option == 2) {
     std::cout << "Messages" << std::endl;
  }
  if (option == 3) {
    
  }
  if (option == 4) {
  
  }
  if (option == 5) {
  
  }
  if (option == 6) {
  
  }
  if (option == 7) {
  
  }
  
}

void TextUI::LoadInData(std::string filename) {
  std::fstream file(filename, std::ios::in);
  std::string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      std::stringstream str(line);
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
      MakeNewUser(username, address, stol(phoneNum), stod(accountBalance), userType);
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
      while (option != "c" && option != "e") {
        std::cout << "Please enter a valid option. Enter your option again (c/e): ";
        std::cin >> option;
      }
      if (option == "c") {
        std::string address;
        long phoneNum;
        double accountBalance;

        std::cout << "Address: ";
        std::cin >> address;
        std::cout << "Phone Number: ";
        std::cin >> phoneNum;
        std::cout << "Add money to account: ";
        std::cin >> accountBalance;

        MakeNewUser(username, address, phoneNum, accountBalance, "Buyer");
      }
      if (option == "e") {
        throw std::exception();
      }
    }
  } else {
    if (GetSeller(username) == NULL) {
      std::string option;

      std::cout << "The username is not found in the user list." << std::endl
                << "Create a new account? (c)" << std::endl
                << "Exit the program? (e)" << std::endl
                << "Please enter an option (c/e): ";
      std::cin >> option;
      while (option != "c" && option != "e") {
        std::cout << "Please enter a valid option. Enter your option again (c/e): ";
        std::cin >> option;
      }
      if (option == "c") {
        std::string address;
        long phoneNum;
        double accountBalance;

        std::cout << "Address: ";
        std::cin >> address;
        std::cout << "Phone Number: ";
        std::cin >> phoneNum;
        std::cout << "Add money to account: ";
        std::cin >> accountBalance;

        MakeNewUser(username, address, phoneNum, accountBalance, "Seller");
      }
      if (option == "e") {
        throw std::exception();
      }
    }
  }
  return username;
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

bool TextUI::MakeNewUser(std::string name, std::string address, long phoneNum, double accountBalance, std::string userType) {
  if (userType == "seller") {
    _sellers.insert(std::make_pair(name, new Seller(name, address, phoneNum, accountBalance)));
    return true;
  } else if (userType == "buyer") {
    _buyers.insert(std::make_pair(name, new Buyer(name, address, phoneNum, accountBalance)));
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
