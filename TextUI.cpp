#include "TextUI.h"

TextUI::TextUI() {
  std::vector<std::string> subcategories;
  subcategories.push_back("Camera");
  subcategories.push_back("Television");
  subcategories.push_back("Phone");
  _productCategories.insert(std::make_pair("Electronics", subcategories));
  subcategories.clear();
  subcategories.push_back("Monitors");
  subcategories.push_back("Mouse");
  subcategories.push_back("Keyboard");
  _productCategories.insert(std::make_pair("Computers", subcategories));
  subcategories.clear();
  subcategories.push_back("Basketball");
  subcategories.push_back("Football");
  subcategories.push_back("Baseball");
  _productCategories.insert(std::make_pair("Sports", subcategories));
  subcategories.clear();
  subcategories.push_back("MenClothing");
  subcategories.push_back("WomenClothing");
  subcategories.push_back("Necklaces");
  _productCategories.insert(std::make_pair("Clothing", subcategories));
  subcategories.clear();
  subcategories.push_back("Textbooks");
  subcategories.push_back("Novels");
  subcategories.push_back("Cookbooks");
  _productCategories.insert(std::make_pair("Books", subcategories));
  subcategories.clear();
}

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

void TextUI::LoadInUserData(std::string filename) {
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
      std::string rateTotal;
      getline(str, rateTotal, ',');
      std::string rateCount;
      getline(str, rateCount, ',');
      MakeNewUser(username, address, stol(phoneNum), stod(accountBalance), stol(rateTotal), stoi(rateCount), userType);
    }
  }
}

void TextUI::LoadInBidsData(std::string filename) {
  std::fstream file(filename, std::ios::in);
  std::string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      std::stringstream str(line);
      std::string productName;
      getline(str, productName, ',');
      std::string subcategory;
      getline(str, subcategory, ',');
      std::string seller;
      getline(str, seller, ',');
      std::string buyer;
      getline(str, buyer, ',');
      std::string quality;
      getline(str, quality, ',');
      std::string basePrice;
      getline(str, basePrice, ',');
      std::string bid;
      getline(str, bid, ',');
      if (subcategory == "Camera") _historyOrders.push_back(ProductFactory::AddCamera(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Television") _historyOrders.push_back(ProductFactory::AddTelevision(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Phone") _historyOrders.push_back(ProductFactory::AddPhone(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Monitors") _historyOrders.push_back(ProductFactory::AddMonitors(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Mouse") _historyOrders.push_back(ProductFactory::AddMouse(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Keyboard") _historyOrders.push_back(ProductFactory::AddKeyboard(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Basketball") _historyOrders.push_back(ProductFactory::AddBasketball(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Football") _historyOrders.push_back(ProductFactory::AddFootball(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Baseball") _historyOrders.push_back(ProductFactory::AddBaseball(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "MenClothing") _historyOrders.push_back(ProductFactory::AddMenClothing(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "WomenClothing") _historyOrders.push_back(ProductFactory::AddWomenClothing(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Necklaces") _historyOrders.push_back(ProductFactory::AddNecklaces(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Textbooks") _historyOrders.push_back(ProductFactory::AddTextbooks(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Novels") _historyOrders.push_back(ProductFactory::AddNovels(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
      if (subcategory == "Cookbooks") _historyOrders.push_back(ProductFactory::AddCookbooks(productName, stod(basePrice), quality, seller, std::make_pair(stod(bid), buyer)));
    }
  }
}

std::string TextUI::LogInUsername(std::string role) {
  std::string username;

  std::cout << "Username: ";
  std::cin >> username;
  try {
    if (role == "seller") {
      if (GetSeller(username) == NULL) {
        CreateNewAccount(role, username);
      }
    } else {
      if (GetBuyer(username) == NULL) {
        CreateNewAccount(role, username);
      }
    }
  } catch (std::exception&) {
    throw std::exception();
  }
  return username;
}

void TextUI::CreateNewAccount(std::string role, std::string username) {
  std::string option;

  std::cout << "The username is not found in the " << role << " list." << std::endl
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

    MakeNewUser(username, address, phoneNum, accountBalance, 0.0, 0, role);
  }
  if (option == "e") {
    throw std::exception();
  }
}

void TextUI::DisplayForBuyer(std::string name) {
  Buyer* b = GetBuyer(name);

  std::string option;
  std::cout << "Please choose from the following list of buyer options: " << std::endl;
  std::cout << "1. View/Bid-On Products" << std::endl;
  std::cout << "2. View/Send Messages" << std::endl;
  std::cout << "3. Check Account Balance" << std::endl;
  std::cout << "4. Update User Info" << std::endl;
  std::cout << "5. View Bid History" << std::endl;
  std::cout << "6. View Purchased Products" << std::endl;
  std::cout << "7. Log out" << std::endl;
  std::cin >> option;

  while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7") {
    std::cout << "Please enter a valid option. Enter your option again (1-7): ";
    std::cin >> option;
  }

  if (option == "1") {
    std::cout << "Here's a list of all currently biddable products: " << std::endl;
  }
  if (option == "2") {
    std::string replyTo;
    b->ReadMessage(replyTo);
    if (replyTo != "") {
      std::cout << "Please write the content of your message here:" << std::endl;
      std::string content;
      std::cin >> content;
      SendMessage(b->GetUsername(), replyTo, "seller", content);
      std::cout << "The message is sent to " << replyTo << "!" << std::endl;
    }
  }
  if (option == "3") {
    std::cout << "Your account balance is: $" << b->GetAccountBalance() << std::endl;
  }
  if (option == "4") {
  }
  if (option == "5") {
  }
  if (option == "6") {
  }
  if (option == "7") {
    throw std::exception();
  }
}

void TextUI::DisplayForSeller(std::string name) {
  Seller* s = GetSeller(name);

  std::cout << "Please choose from the following list of seller options: " << std::endl;
  std::cout << "1. Post a product for sale" << std::endl;
  std::cout << "2. View/Send messages" << std::endl;
  std::cout << "3. Check account balance" << std::endl;
  std::cout << "4. Rate a buyer" << std::endl;
  std::cout << "5. Update user info" << std::endl;
  std::cout << "6. View product list" << std::endl;
  std::cout << "7. Close bid on a product" << std::endl;
  std::cout << "8. Log out" << std::endl;
  std::string option;
  std::cin >> option;
  while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8") {
    std::cout << "Please enter a valid option. Enter your option again (1-8): ";
    std::cin >> option;
  }

  if (option == "1") {
    std::cout << "Please choose one of the following categories of your product." << std::endl;
    int index = 1;
    for (auto i = _productCategories.begin(); i != _productCategories.end(); i++) {
      std::cout << index << ". " << i->first << " ";
      index++;
    }
    std::cout << std::endl
              << "Please enter your option (1-5): ";
    std::string optionCategory;
    std::cin >> optionCategory;
    while (optionCategory != "1" && optionCategory != "2" && optionCategory != "3" && optionCategory != "4" && optionCategory != "5") {
      std::cout << "Please enter a valid option. Enter your option again (1-5): ";
      std::cin >> optionCategory;
    }
    std::string category;
    if (optionCategory == "1") {
      category = "Books";
    }
    if (optionCategory == "2") {
      category = "Clothing";
    }
    if (optionCategory == "3") {
      category = "Computers";
    }
    if (optionCategory == "4") {
      category = "Electronics";
    }
    if (optionCategory == "5") {
      category = "Sports";
    }
    std::cout << "Please choose one of the following subcategories of your product." << std::endl;
    for (int i = 0; i < 3; i++) {
      std::cout << i + 1 << ". " << _productCategories[category][i] << " ";
    }
    std::cout << std::endl
              << "Please enter your option (1-3): ";
    std::string optionSubcategory;
    std::cin >> optionSubcategory;
    while (optionSubcategory != "1" && optionSubcategory != "2" && optionSubcategory != "3") {
      std::cout << "Please enter a valid option. Enter your option again (1-3): ";
      std::cin >> optionSubcategory;
    }
    std::cout << "The name of your product: ";
    std::string productName;
    std::cin >> productName;
    std::cout << "The base price of your product: ";
    std::string basePrice;
    std::cin >> basePrice;
    std::cout << "The quality of your product (new, used-verygood, used-good, used-okay): ";
    std::string quality;
    std::cin >> quality;
    if (quality != "New" && quality != "used-verygood" && quality != "used-good" && quality != "used-okay") {
      std::cout << "Please enter a valid quality. Enter the quality again (new, used-verygood, used-good, used-okay): ";
      std::cin >> quality;
    }
    if (optionCategory == "1") {
      if (optionSubcategory == "1") {
        AddNewProduct(ProductFactory::AddTextbooks(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "2") {
        AddNewProduct(ProductFactory::AddNovels(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "3") {
        AddNewProduct(ProductFactory::AddCookbooks(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
    }
    if (optionCategory == "2") {
      if (optionSubcategory == "1") {
        AddNewProduct(ProductFactory::AddMenClothing(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "2") {
        AddNewProduct(ProductFactory::AddWomenClothing(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "3") {
        AddNewProduct(ProductFactory::AddNecklaces(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
    }
    if (optionCategory == "3") {
      if (optionSubcategory == "1") {
        AddNewProduct(ProductFactory::AddMonitors(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "2") {
        AddNewProduct(ProductFactory::AddMouse(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "3") {
        AddNewProduct(ProductFactory::AddKeyboard(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
    }
    if (optionCategory == "4") {
      if (optionSubcategory == "1") {
        AddNewProduct(ProductFactory::AddCamera(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "2") {
        AddNewProduct(ProductFactory::AddTelevision(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "3") {
        AddNewProduct(ProductFactory::AddPhone(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
    }
    if (optionCategory == "5") {
      if (optionSubcategory == "1") {
        AddNewProduct(ProductFactory::AddBasketball(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "2") {
        AddNewProduct(ProductFactory::AddFootball(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
      if (optionSubcategory == "3") {
        AddNewProduct(ProductFactory::AddBaseball(productName, stod(basePrice), quality, s->GetUsername()), s);
      }
    }
    std::cout << "Your product " << productName << " is added to the list for sale!" << std::endl;
  }
  if (option == "2") {
    std::string replyTo;
    s->ReadMessage(replyTo);
    if (replyTo != "") {
      std::cout << "Please write the content of your message here:" << std::endl;
      std::string content;
      std::cin >> content;
      SendMessage(s->GetUsername(), replyTo, "buyer", content);
      std::cout << "The message is sent to " << replyTo << "!" << std::endl;
    }
  }
  if (option == "3") {
    std::cout << "Your current balance is: " << s->GetAccountBalance() << std::endl;
  }
  if (option == "4") {
  }
  if (option == "5") {
  }
  if (option == "6") {
  }
  if (option == "7") {
  }
  if (option == "8") {
    throw std::exception();
  }
}

void TextUI::CheckMessagebox(std::string role, std::string name) {
  if (role == "buyer") {
    if (!GetBuyer(name)->MessageboxIsEmpty()) {
      std::cout << "You have new message(s)!";
    }
  } else {
    if (!GetSeller(name)->MessageboxIsEmpty()) {
      std::cout << "You have new message(s)!";
    }
  }
  std::cout << std::endl;
}

void TextUI::SendMessage(std::string sender, std::string receiver, std::string receiverRole, std::string content) {
  Message m(sender, receiver, content);
  if (receiverRole == "buyer") {
    Buyer* b = GetBuyer(receiver);
    b->ReceiveMessage(m);
  } else {
    Seller* s = GetSeller(receiver);
    s->ReceiveMessage(m);
  }
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

bool TextUI::MakeNewUser(std::string name, std::string address, long phoneNum, double accountBalance, double rateTotal, int rateCount, std::string userType) {
  if (userType == "seller") {
    _sellers.insert(std::make_pair(name, new Seller(name, address, phoneNum, accountBalance, rateTotal, rateCount)));
    return true;
  } else if (userType == "buyer") {
    _buyers.insert(std::make_pair(name, new Buyer(name, address, phoneNum, accountBalance, rateTotal, rateCount)));
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
