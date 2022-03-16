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

void TextUI::DisplayForBuyer(Buyer* b) {
  std::cout << "Please choose from the following list of buyer options: " << std::endl;
  std::cout << "1. View/Bid-On Products" << std::endl;
  std::cout << "2. View/Send Messages" << std::endl;
  std::cout << "3. Check Account Balance" << std::endl;
  std::cout << "4. Rate Seller" << std::endl;
  std::cout << "5. Update User Info" << std::endl;
  std::cout << "6. View Bid History" << std::endl;
  std::cout << "7. View Purchased Products" << std::endl;
  std::cout << "8. Log out" << std::endl;
  std::string option;
  std::cin >> option;
  while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8") {
    std::cout << "Please enter a valid option. Enter your option again (1-8): ";
    std::cin >> option;
  }

  if (option == "1") {
    if (_products.size() != 0) {
      std::cout << "Here's a list of all currently biddable products: " << std::endl;
      for (std::map<int, Product*>::iterator i = _products.begin(); i != _products.end(); i++) {
        std::cout << "Product ID: " << i->first << " | Name: " << i->second->GetProductName() << " | Quality: " << i->second->GetQuality() << " | Base Price: " << i->second->GetBasePrice() << " | Highest Bid: " << i->second->GetHighestBidInfo().first << std::endl;
      }
      std::cout << "Select item to bid on via Product ID (or select (e) to escape back to main page)" << std::endl;
      std::string productID;
      std::cin >> productID;
      while ((productID != "e" && _products.find(stoi(productID)) == _products.end()) || !_products.find(stoi(productID))->second->GetStatus()) {
        std::cout << "Please enter a valid option. Enter the option again (Product ID or (e) to exit): ";
        std::cin >> productID;
      }
      if (productID == "e") {
        return;
      }
      std::cout << "Please make a bid on the chosen product (bid > current highest bid OR base price && bid < user balance): ";
      std::string bidPrice;
      std::cin >> bidPrice;
      if (_products[stoi(productID)]->GetHighestBidInfo().first == 0) {
        while (stod(bidPrice) <= _products[stoi(productID)]->GetBasePrice() || stod(bidPrice) >= b->GetAccountBalance()) {
          if (stod(bidPrice) <= _products[stoi(productID)]->GetBasePrice()) {
            std::cout << "New bid price must exceed the base price (i.e newBid > " << _products[stoi(productID)]->GetBasePrice() << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be greater than the base price): ";
          } else {
            std::cout << "New bid price must not exceed your account balance (i.e newBid < " << b->GetAccountBalance() << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be less than your account balance): ";
          }
          std::cin >> bidPrice;
        }
      } else {
        while (stod(bidPrice) <= _products[stoi(productID)]->GetHighestBidInfo().first || stod(bidPrice) >= b->GetAccountBalance()) {
          if (stod(bidPrice) <= _products[stoi(productID)]->GetHighestBidInfo().first) {
            std::cout << "New bid price must exceed the current highest bid (i.e newBid > " << _products[stoi(productID)]->GetHighestBidInfo().first << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be greater than the current highest bid): ";
          } else {
            std::cout << "New bid price must not exceed your account balance (i.e newBid < " << b->GetAccountBalance() << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be less than your account balance): ";
          }
          std::cin >> bidPrice;
        }
      }
      b->AddBidToProduct(_products[stoi(productID)]->GetProductName(), stod(bidPrice));
      _products[stoi(productID)]->SetCurrentBid(stod(bidPrice), b->GetUsername());
    } else {
      std::cout << "There are currently no products to bid on, please check back for new product listings!" << std::endl;
    }
  }
  if (option == "2") {
    std::string* replyTo = NULL;
    int productID = -1;
    b->ReadMessage(&replyTo, productID);
    if (replyTo != NULL) {
      std::cout << "Please write the content of your message here:" << std::endl;
      std::string content;
      std::getline(std::cin, content);
      std::getline(std::cin, content);
      if (productID > 0) {
        Product* p = _pendingProducts[productID];
        Seller* s = GetSeller(*replyTo);
        double bid = p->GetHighestBidInfo().first;
        double deliverFee = p->IsToDeliver() ? p->GetHighestBidInfo().first * 0.05 : 0;
        while (bid + deliverFee > b->GetAccountBalance()) {
          std::cout << "Your account balance is not enough to purchase the product. Please save more money to your account." << std::endl;
          std::cout << "How much do you want to save to your account: ";
          std::string money;
          std::cin >> money;
          b->UpdateAccountBalance(stod(money));
        }
        b->UpdateAccountBalance((bid + deliverFee) * -1);
        b->AddToHistoryOrders(p);
        b->AddUserToRate(s->GetUsername());
        s->UpdateAccountBalance(bid);
        s->AddToHistoryProducts(productID);
        s->AddUserToRate(b->GetUsername());
        p->SetBuyer(b->GetUsername());
        _pendingProducts.erase(productID);
        _historyOrders.push_back(p);
      }
      SendMessage(b->GetUsername(), replyTo, "seller", content);
      std::cout << "The message is sent to " << *replyTo << "!" << std::endl;
    }
  }
  if (option == "3") {
    std::cout << "Your current balance is: " << b->GetAccountBalance() << std::endl;
  }
  if (option == "4") {
    std::string* userToRate = b->GetUserToRate();
    if (userToRate != NULL) {
      std::cout << "How would you like to rate " << *userToRate << "? (0-5): ";
      std::string rate;
      std::cin >> rate;
      while (rate != "0" && rate != "1" && rate != "2" && rate != "3" && rate != "4" && rate != "5") {
        std::cout << "Please enter a valid rate. Enter the rate again (0-5): ";
        std::cin >> rate;
      }
      Seller* s = GetSeller(*userToRate);
      s->AddNewRate(stod(rate));
      std::cout << "You just rated " << *userToRate << "!" << std::endl;
    }
  }
  if (option == "5") {
    std::cout << "Which one would you like to change?" << std::endl;
    std::cout << "1. Username 2. Phone number 3. Address" << std::endl;
    std::cout << "Please enter an option (1-3): ";
    std::string optionChangeInfo;
    std::cin >> optionChangeInfo;
    while (optionChangeInfo != "1" && optionChangeInfo != "2" && optionChangeInfo != "3") {
      std::cout << "Please enter a valid option. Enter the option again (1-3): ";
      std::cin >> optionChangeInfo;
    }
    if (optionChangeInfo == "1") {
      std::cout << "New username: ";
      std::string newName;
      std::cin >> newName;
      while (GetBuyer(newName) != NULL) {
        std::cout << "The username has been used by another user. Please try a new name: ";
        std::cin >> newName;
      }
      _buyers.erase(*b->GetUsername());
      b->UpdateUsername(newName);
      _buyers.insert(std::make_pair(newName, b));
      std::cout << "Your name has been changed to \"" << *b->GetUsername() << "\"!" << std::endl;
    }
    if (optionChangeInfo == "2") {
      std::cout << "New phone number: ";
      std::string newPhoneNum;
      std::cin >> newPhoneNum;
      b->UpdatePhoneNum(stol(newPhoneNum));
      std::cout << "Your phone number has been changed to \"" << b->GetPhoneNum() << "\"!" << std::endl;
    }
    if (optionChangeInfo == "3") {
      std::cout << "New address: ";
      std::string newAddress;
      std::getline(std::cin, newAddress);
      std::getline(std::cin, newAddress);
      b->UpdateAddress(newAddress);
      std::cout << "Your address has been changed to \"" << b->GetAddress() << "\"!" << std::endl;
    }
  }
  if (option == "6") {
    std::map<std::string, std::vector<double> > allBids = b->GetBidsHistory();
    for (std::map<std::string, std::vector<double> >::iterator i = allBids.begin(); i != allBids.end(); i++) {
      std::cout << "Product Name: " << i->first << " | Bid Prices: ";
      int size = i->second.size();
      for (int j = 0; j < size; j++) {
        std::cout << i->second[j];
        if (j != size - 1) {
          std::cout << ", ";
        }
      }
      std::cout << std::endl;
    }
  }
  if (option == "7") {
    b->ViewHistoryOrders();
  }
  if (option == "8") {
    throw std::exception();
  }
}

void TextUI::DisplayForSeller(Seller* s) {
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
    for (std::map<std::string, std::vector<std::string> >::iterator i = _productCategories.begin(); i != _productCategories.end(); i++) {
      std::cout << index << ". " << i->first << " ";
      index++;
    }
    std::cout << std::endl;
    std::cout << "Please enter your option (1-5): ";
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
    std::cout << std::endl;
    std::cout << "Please enter your option (1-3): ";
    std::string optionSubcategory;
    std::cin >> optionSubcategory;
    while (optionSubcategory != "1" && optionSubcategory != "2" && optionSubcategory != "3") {
      std::cout << "Please enter a valid option. Enter your option again (1-3): ";
      std::cin >> optionSubcategory;
    }
    std::cout << "Do you want to view prices of similar products that were historically sold? (yes/no): ";
    std::string viewHistoryOrdersOrNot;
    std::cin >> viewHistoryOrdersOrNot;
    while (viewHistoryOrdersOrNot != "yes" && viewHistoryOrdersOrNot != "no") {
      std::cout << "Please enter a valid option. Enter the option again (yes/no): ";
      std::cin >> viewHistoryOrdersOrNot;
    }
    if (viewHistoryOrdersOrNot == "yes") {
      int size = _historyOrders.size();
      for (int i = 0; i < size; i++) {
        if (_historyOrders[i]->GetProductSubcategory() == _productCategories[category][stoi(optionSubcategory) - 1]) {
          std::cout << "Product name: " << _historyOrders[i]->GetProductName() << ", bid: " << _historyOrders[i]->GetHighestBidInfo().first << std::endl;
        }
      }
    }
    std::cout << "The name of your product: ";
    std::string productName;
    std::getline(std::cin, productName);
    std::getline(std::cin, productName);
    std::cout << "The base price of your product: ";
    std::string basePrice;
    std::cin >> basePrice;
    std::cout << "The quality of your product (new, used-verygood, used-good, used-okay): ";
    std::string quality;
    std::cin >> quality;
    if (quality != "new" && quality != "used-verygood" && quality != "used-good" && quality != "used-okay") {
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
    std::string* replyTo = NULL;
    int productID = -1;
    s->ReadMessage(&replyTo, productID);
    if (replyTo != NULL) {
      std::cout << "Please write the content of your message here:" << std::endl;
      std::string content;
      std::getline(std::cin, content);
      std::getline(std::cin, content);
      SendMessage(s->GetUsername(), replyTo, "buyer", content);
      std::cout << "The message is sent to " << *replyTo << "!" << std::endl;
    }
  }
  if (option == "3") {
    std::cout << "Your current balance is: " << s->GetAccountBalance() << std::endl;
  }
  if (option == "4") {
    std::string* userToRate = s->GetUserToRate();
    if (userToRate != NULL) {
      std::cout << "How would you like to rate " << *userToRate << "? (0-5): ";
      std::string rate;
      std::cin >> rate;
      while (rate != "0" && rate != "1" && rate != "2" && rate != "3" && rate != "4" && rate != "5") {
        std::cout << "Please enter a valid rate. Enter the rate again (0-5): ";
        std::cin >> rate;
      }
      Buyer* b = GetBuyer(*userToRate);
      b->AddNewRate(stod(rate));
      std::cout << "You just rated " << *userToRate << "!" << std::endl;
    }
  }
  if (option == "5") {
    std::cout << "Which one would you like to change?" << std::endl;
    std::cout << "1. Name 2. Phone number 3. Address" << std::endl;
    std::cout << "Please enter an option (1-3): ";
    std::string optionChangeInfo;
    std::cin >> optionChangeInfo;
    while (optionChangeInfo != "1" && optionChangeInfo != "2" && optionChangeInfo != "3") {
      std::cout << "Please enter a valid option. Enter the option again (1-3): ";
      std::cin >> optionChangeInfo;
    }
    if (optionChangeInfo == "1") {
      std::cout << "New name: ";
      std::string newName;
      std::cin >> newName;
      while (GetSeller(newName) != NULL) {
        std::cout << "The username has been used by the other user. Please try a new name: ";
        std::cin >> newName;
      }
      _sellers.erase(*s->GetUsername());
      s->UpdateUsername(newName);
      _sellers.insert(std::make_pair(newName, s));
      std::cout << "Your name has been changed to \"" << *s->GetUsername() << "\"!" << std::endl;
    }
    if (optionChangeInfo == "2") {
      std::cout << "New phone number: ";
      std::string newPhoneNum;
      std::cin >> newPhoneNum;
      s->UpdatePhoneNum(stol(newPhoneNum));
      std::cout << "Your phone number has been changed to \"" << s->GetPhoneNum() << "\"!" << std::endl;
    }
    if (optionChangeInfo == "3") {
      std::cout << "New address: ";
      std::string newAddress;
      std::getline(std::cin, newAddress);
      std::getline(std::cin, newAddress);
      s->UpdateAddress(newAddress);
      std::cout << "Your address has been changed to \"" << s->GetAddress() << "\"!" << std::endl;
    }
  }
  if (option == "6") {
    s->ViewProductList();
  }
  if (option == "7") {
    if (s->GetProductlistSize() == 0) {
      std::cout << "You have no product to close" << std::endl;
      return;
    }
    std::cout << "Please choose a product to close:" << std::endl;
    s->ViewProductList();
    std::cout << "Enter a product id: ";
    std::string id;
    std::cin >> id;
    while (s->GetProductInfo(stoi(id)) == NULL && !s->GetProductInfo(stoi(id))->GetStatus()) {
      std::cout << "Please enter a valid product id. Enter the product id again: ";
      std::cin >> id;
    }
    std::cout << "Please choose how the buyer gets the product (delivery/pickup): ";
    std::string deliveryOption;
    std::cin >> deliveryOption;
    while (deliveryOption != "delivery" && deliveryOption != "pickup") {
      std::cout << "Please enter a valid option. Enter the option again (delivery/pickup): ";
      std::cin >> deliveryOption;
    }
    Product* p = s->GetProductInfo(stoi(id));
    p->SetStatus(false);
    _products.erase(stoi(id));
    _pendingProducts.insert(std::make_pair(stoi(id), p));
    if (p->GetHighestBidInfo().first != 0) {
      std::vector<std::string*> buyers = p->ExtractBuyers();
      std::string messageContent;
      if (deliveryOption == "pickup") {
        std::string address = s->GetAddress();
        if (s->GetAddress() == "") {
          std::cout << "Please enter an address for the buyer to pickup: ";
          std::getline(std::cin, address);
          std::getline(std::cin, address);
        }
        messageContent = "Congratulations! You just won the bid on " + p->GetProductName() + "! My address is: " + address + ", please come to pick up.";
      } else {
        p->SetToDeliver();
        messageContent = "Congratulations! You just won the bid on " + p->GetProductName() + "! Please message me back your address.";
      }
      SendMessage(s->GetUsername(), buyers[0], "buyer", messageContent, stoi(id));
      std::cout << "The notification message is sent to " << *buyers[0] << "!" << std::endl;
      if (buyers.size() > 1) {
        int size = buyers.size();
        for (int i = 1; i < size; i++) {
          SendMessage(s->GetUsername(), buyers[i], "buyer", "You have lost the bid on " + p->GetProductName() + ".");
        }
      }
    }
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

void TextUI::SendMessage(std::string* sender, std::string* receiver, std::string receiverRole, std::string content) {
  Message m(sender, receiver, content);
  if (receiverRole == "buyer") {
    Buyer* b = GetBuyer(*receiver);
    b->ReceiveMessage(m);
  } else {
    Seller* s = GetSeller(*receiver);
    s->ReceiveMessage(m);
  }
}

void TextUI::SendMessage(std::string* sender, std::string* receiver, std::string receiverRole, std::string content, int productID) {
  Message m(sender, receiver, content, productID);
  if (receiverRole == "buyer") {
    Buyer* b = GetBuyer(*receiver);
    b->ReceiveMessage(m);
  } else {
    Seller* s = GetSeller(*receiver);
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

void TextUI::WriteToUsersCSV() {
  std::ofstream f;
  f.open("Users.csv");
  for (std::map<std::string, Seller*>::iterator i = _sellers.begin(); i != _sellers.end(); i++) {
    f << "seller," << *(i->second->GetUsername()) << "," << i->second->GetAddress() << "," << i->second->GetPhoneNum() << "," << i->second->GetAccountBalance() << "," << i->second->GetRateTotal() << "," << i->second->GetRateCount() << "\n";
  }
  for (std::map<std::string, Buyer*>::iterator i = _buyers.begin(); i != _buyers.end(); i++) {
    f << "buyer," << *(i->second->GetUsername()) << "," << i->second->GetAddress() << "," << i->second->GetPhoneNum() << "," << i->second->GetAccountBalance() << "," << i->second->GetRateTotal() << "," << i->second->GetRateCount() << "\n";
  }
  f.close();
}

void TextUI::WriteToBidsCSV() {
  std::ofstream f;
  f.open("Bids.csv");
  int size = _historyOrders.size();
  for (int i = 0; i < size; i++) {
    Product* p = _historyOrders[i];
    f << p->GetProductName() << "," << p->GetProductSubcategory() << "," << *(p->GetSeller()) << "," << *(p->GetBuyer()) << "," << p->GetQuality() << "," << p->GetBasePrice() << "," << p->GetHighestBidInfo().first << "\n";
  }
  f.close();
}

int TextUI::id = 0;
