#include "TextUI.h"

/*
 * The constructor for instantiating TextUI.
 * If you want to add more categories or subcategories for the product you have, do it here.
 */

// Constructor loads factory of subcategorial products, combines and pushes 3 subcategories for each main product category
TextUI::TextUI() {
  std::vector<std::string> subcategories;
  subcategories.push_back("Camera");
  subcategories.push_back("Television");
  subcategories.push_back("Phone");
  _productCategories.insert(std::make_pair("Electronics", subcategories));  // pushes a mapping of all Electronics subcategories to product factory
  subcategories.clear();
  subcategories.push_back("Monitors");
  subcategories.push_back("Mouse");
  subcategories.push_back("Keyboard");
  _productCategories.insert(std::make_pair("Computers", subcategories));  // pushes a mapping of all Computers subcategories to product factory
  subcategories.clear();
  subcategories.push_back("Basketball");
  subcategories.push_back("Football");
  subcategories.push_back("Baseball");
  _productCategories.insert(std::make_pair("Sports", subcategories));  // pushes a mapping of all Sports subcategories to product factory
  subcategories.clear();
  subcategories.push_back("MenClothing");
  subcategories.push_back("WomenClothing");
  subcategories.push_back("Necklaces");
  _productCategories.insert(std::make_pair("Clothing", subcategories));  // pushes a mapping of all Clothing subcategories to product factory
  subcategories.clear();
  subcategories.push_back("Textbooks");
  subcategories.push_back("Novels");
  subcategories.push_back("Cookbooks");
  _productCategories.insert(std::make_pair("Books", subcategories));  // pushes a mapping of all Books subcategories to product factory
  subcategories.clear();
}

// initial login page, prompts user to sign in as a buyer/seller
std::string TextUI::DisplayRoleChoice() {
  std::string role;

  std::cout << "Welcome to BidToBuy. Choose a role to log in (buyer/seller): ";
  std::cin >> role;
  while (role != "buyer" && role != "seller") {
    std::cout << "Please enter a valid input. Choose a role to log in (buyer/seller): ";  // invalid buyer/seller selections will enter while loop until correct choice is made
    std::cin >> role;
  }
  return role;
}

/*
 * Read Users.csv to load in the data of users at the beginning of the program.
 */

// loads in initial user data, gets usertype, username, address, phone number, account balance, total rating,
// and total # of completed transaction fields and creates new user using this preloaded data
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
      MakeNewUser(username, address, stol(phoneNum), stod(accountBalance), stol(rateTotal), stoi(rateCount), userType);  // instantiates a new user with getline info read in from Users.csv
    }
  }
}

/*
 * Read Bids.csv to load in the data of historical orders at the beginning of the program.
 */

// loads in history of bids, gets product name, subcategory, seller, buyer, quality, base price,
// and current highest bid fields and pushes new factorized product to history orders vector
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
      // conditionals to properly sort products based on subcategory placement
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

/*
 * When the user executes the program, ask the user to choose a role to log in.
 */
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

/*
 * Ask the user to log in with their username. If it is not is user list, ask if they want to create a new account.
 * @param role The role of the user. Either buyer or seller.
 * @return A username that is in the list.
 */
std::string TextUI::LogInUsername(std::string role) {
  std::string username;
  // asks user to login username
  std::cout << "Please enter your username (for new users, enter your intended username): ";
  std::cin >> username;
  try {
    if (role == "seller") {
      if (GetSeller(username) == NULL) {  // if seller's username isn't recognized, user is given the option to create a new account or close the program
        CreateNewAccount(role, username);
      }
    } else {
      if (GetBuyer(username) == NULL) {  // if buyer's username isn't recognized, user is given the option to create a new account or close the program
        CreateNewAccount(role, username);
      }
    }
  } catch (std::exception&) {
    throw std::exception();  // excpetion thrown when trying to exit module
  }
  return username;  // username is passed to display functions in order to easily access information pertaining to the user
}

/*
 * The method that helps the user to create a new account with the given role and given username.
 * @param role The type of the account that the user wants to create. Either buyer or seller.
 * @param username The username of the user's new account.
 */

// instances where a username isn't recognized (loaded into Users.csv) the user can create a new account
void TextUI::CreateNewAccount(std::string role, std::string username) {
  std::string option;

  std::cout << "The username is not found in the " << role << " list." << std::endl
            << "Create a new account? (c)" << std::endl
            << "Exit the program? (e)" << std::endl
            << "Please enter an option (c/e): ";
  std::cin >> option;
  while (option != "c" && option != "e") {  // only accepts c and e entries
    std::cout << "Please enter a valid option. Enter your option again (c/e): ";
    std::cin >> option;
  }
  if (option == "c") {  // prompts user for address, phone number, and base account balance info
    std::string address;
    long phoneNum;
    double accountBalance;

    std::cout << "Address: ";
    std::getline(std::cin, address);
    std::getline(std::cin, address);
    std::cout << "Phone Number: ";
    std::cin >> phoneNum;
    std::cout << "Add money to account: ";
    std::cin >> accountBalance;

    // saves input username from initial prompting
    MakeNewUser(username, address, phoneNum, accountBalance, 0.0, 0, role);
  }
  if (option == "e") {  // throws error when option is = (e)
    throw std::exception();
  }
}

/*
 * The text UI that will be displayed to the user when they log in as a buyer.
 * It also executes the options that the user makes when running the program.
 */

// populated menu options for users that are of type buyer
void TextUI::DisplayForBuyer(Buyer* b) {
  std::cout << "\n";
  std::string option;
  std::cout << "Please choose from the following list of buyer options: " << std::endl;
  std::cout << "1. View/Bid-On Products" << std::endl;     // displays all possible products to bid on with option to bid if user chooses too (exit and return to main page otherwise)
  std::cout << "2. View/Send Messages" << std::endl;       // populates messages when seller closes a bid, message from buyer to sender required when delivery method is selected
  std::cout << "3. Check Account Balance" << std::endl;    // accesses buyer's account balance field and is printed to the screen
  std::cout << "4. Rate Seller" << std::endl;              // populates a list of sellers to rate (only sellers that have closed bids with the given user are shown)
  std::cout << "5. Update User Info" << std::endl;         // buyer can update any of the following fields: username, address, or phone number
  std::cout << "6. View Bid History" << std::endl;         // a mapped vector stores all bids the current buyer has made and displays this history to the user
  std::cout << "7. View Purchased Products" << std::endl;  // anytime a seller closes a bid, the product sold is pushed to the history orders vector and is displayed using this selection
  std::cout << "8. Log out" << std::endl;                  // logs buyer out of their account with an option to sign in using a different username
  std::cin >> option;
  std::cout << "\n";

  // weed out all unecessary option selections (option != 1-8)
  while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8") {
    std::cout << "Please enter a valid option. Enter your option again (1-8): ";
    std::cin >> option;
  }

  if (option == "1") {
    if (_products.size() != 0) {  // conditional checking if any products are currently being sold
      std::cout << "Here's a list of all currently biddable products: " << std::endl;
      for (std::map<int, Product*>::iterator i = _products.begin(); i != _products.end(); i++) {
        std::cout << "Product ID: " << i->first << " | Name: " << i->second->GetProductName() << " | Quality: " << i->second->GetQuality() << " | Base Price: " << i->second->GetBasePrice() << " | Highest Bid: " << i->second->GetHighestBidInfo().first << std::endl;
      }
      std::cout << "Select item to bid on via Product ID (or select (e) to escape back to main page)" << std::endl;  // options to bid on any of the products listed or exit to the main page
      std::string productID;
      std::cin >> productID;
      while ((productID != "e" && _products.find(stoi(productID)) == _products.end()) || !_products.find(stoi(productID))->second->GetStatus()) {
        std::cout << "Please enter a valid option. Enter the option again (Product ID or (e) to exit): ";
        std::cin >> productID;
      }
      if (productID == "e") {  // returns to main display page
        return;
      }
      std::cout << "Please make a bid on the chosen product (bid > current highest bid OR base price && bid < user balance): ";
      std::string bidPrice;
      std::cin >> bidPrice;
      if (_products[stoi(productID)]->GetHighestBidInfo().first == 0) {  // conditionals checking that bid amount is greater than base price (when no bids have been made prior) and that the buyer can adequately pay for the product
        while (stod(bidPrice) <= _products[stoi(productID)]->GetBasePrice() || stod(bidPrice) >= b->GetAccountBalance()) {
          if (stod(bidPrice) <= _products[stoi(productID)]->GetBasePrice()) {  // bid price is too low
            std::cout << "New bid price must exceed the base price (i.e newBid > " << _products[stoi(productID)]->GetBasePrice() << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be greater than the base price): ";
          } else {  // bid price is too high
            std::cout << "New bid price must not exceed your account balance (i.e newBid < " << b->GetAccountBalance() << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be less than your account balance): ";
          }
          std::cin >> bidPrice;
        }
      } else {
        while (stod(bidPrice) <= _products[stoi(productID)]->GetHighestBidInfo().first || stod(bidPrice) >= b->GetAccountBalance()) {
          if (stod(bidPrice) <= _products[stoi(productID)]->GetHighestBidInfo().first) {  // bid price is too low
            std::cout << "New bid price must exceed the current highest bid (i.e newBid > " << _products[stoi(productID)]->GetHighestBidInfo().first << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be greater than the current highest bid): ";
          } else {  // bid price is too high
            std::cout << "New bid price must not exceed your account balance (i.e newBid < " << b->GetAccountBalance() << ")" << std::endl;
            std::cout << "Please make a bid on the chosen product (bid must be less than your account balance): ";
          }
          std::cin >> bidPrice;
        }
      }
      b->AddBidToProduct(_products[stoi(productID)]->GetProductName(), stod(bidPrice));  // add bid to product if all prior conditionals are met
      _products[stoi(productID)]->SetCurrentBid(stod(bidPrice), b->GetUsername());       // sets the currently highest bid to the most recent
    } else {                                                                             // doesn't print any products if there aren't any currently being sold
      std::cout << "There are currently no products to bid on, please check back for new product listings!" << std::endl;
    }
  }
  if (option == "2") {
    std::string* replyTo = NULL;
    int productID = -1;
    b->ReadMessage(&replyTo, productID);  // if message box is empty, no actions to be done; otherwise, user is prompted whether or not they want to respond to any of their messages
    if (replyTo != NULL) {                // replyTo is NULL if user doesn't want to reply or is a pointer linking to the seller
      std::cout << "Please write the content of your message here:" << std::endl;
      std::string content;  // write message content (typically requires an address)
      std::getline(std::cin, content);
      std::getline(std::cin, content);
      if (productID > 0) {
        Product* p = _pendingProducts[productID];
        Seller* s = GetSeller(*replyTo);
        double bid = p->GetHighestBidInfo().first;
        double deliverFee = p->IsToDeliver() ? p->GetHighestBidInfo().first * 0.05 : 0;
        while (bid + deliverFee > b->GetAccountBalance()) {  // if cost price exceeds buyer's bid plus delivery fee charges, user is prompted to add more $ to account
          std::cout << "Your account balance is not enough to purchase the product. Please save more money to your account." << std::endl;
          std::cout << "How much do you want to save to your account: ";
          std::string money;
          std::cin >> money;
          b->UpdateAccountBalance(stod(money));
        }
        b->UpdateAccountBalance((bid + deliverFee) * -1);  // price of bid + delivery fee (if applicable) are subtracted from buyer's account
        b->AddToHistoryOrders(p);                          // order is added to order history
        b->AddUserToRate(s->GetUsername());                // another message for the buyer, asking to review the seller
        s->UpdateAccountBalance(bid);                      // cost of product is added to seller's account
        s->AddToHistoryProducts(productID);                // added to seller's product history
        s->AddUserToRate(b->GetUsername());                // another message for the seller, asking to review the buyer
        p->SetBuyer(b->GetUsername());                     // product's buyer is set relative to the product
        _pendingProducts.erase(productID);                 // product is taken down from active selling list
        _historyOrders.push_back(p);
      }
      SendMessage(b->GetUsername(), replyTo, "seller", content);
      std::cout << "The message is sent to " << *replyTo << "!" << std::endl;
    }
  }
  if (option == "3") {  // prints account balance
    std::cout << "Your current balance is: " << b->GetAccountBalance() << std::endl;
  }
  if (option == "4") {  // used to rate sellers
    std::string* userToRate = b->GetUserToRate();
    if (userToRate != NULL) {  // only allows ratings of sellers that have sold products to given user
      std::cout << "How would you like to rate " << *userToRate << "? (0-5): ";
      std::string rate;
      std::cin >> rate;
      while (rate != "0" && rate != "1" && rate != "2" && rate != "3" && rate != "4" && rate != "5") {  // rating must be between 0-5
        std::cout << "Please enter a valid rate. Enter the rate again (0-5): ";
        std::cin >> rate;
      }
      Seller* s = GetSeller(*userToRate);
      s->AddNewRate(stod(rate));
      std::cout << "You just rated " << *userToRate << "!" << std::endl;
    }
  }
  if (option == "5") {  // three user info changes prompted to the user
    std::cout << "Which one would you like to change?" << std::endl;
    std::cout << "1. Username 2. Phone number 3. Address" << std::endl;
    std::cout << "Please enter an option (1-3): ";
    std::string optionChangeInfo;
    std::cin >> optionChangeInfo;
    while (optionChangeInfo != "1" && optionChangeInfo != "2" && optionChangeInfo != "3") {  // in case bad selections are made
      std::cout << "Please enter a valid option. Enter the option again (1-3): ";
      std::cin >> optionChangeInfo;
    }
    if (optionChangeInfo == "1") {  // changing username, involves pointers to match previous username entitites to the newly changed username
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
    if (optionChangeInfo == "2") {  // changing buyer's phone number
      std::cout << "New phone number: ";
      std::string newPhoneNum;
      std::cin >> newPhoneNum;
      b->UpdatePhoneNum(stol(newPhoneNum));
      std::cout << "Your phone number has been changed to \"" << b->GetPhoneNum() << "\"!" << std::endl;
    }
    if (optionChangeInfo == "3") {  // changing buyer's address, in most cases we are changing an already NULL value
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
    for (std::map<std::string, std::vector<double> >::iterator i = allBids.begin(); i != allBids.end(); i++) {  // product history is listed by name of product and iterates through a vector of all possible bids made on that product
      std::cout << "Product Name: " << i->first << " | Bid Prices: ";
      int size = i->second.size();
      for (int j = 0; j < size; j++) {  // prints history of all bids made on any given product
        std::cout << i->second[j];
        if (j != size - 1) {
          std::cout << ", ";
        }
      }
      std::cout << std::endl;
    }
  }
  if (option == "7") {  // displays all transaction orders that have been completed
    b->ViewHistoryOrders();
  }
  if (option == "8") {  // exit exception
    throw std::exception();
  }
}

/*
 * The text UI that will be displayed to the user when they log in as a seller.
 * It also executes the options that the user makes when running the program.
 */

// main page displayed to seller, reroutes back here any time module is completed or escaped from
void TextUI::DisplayForSeller(Seller* s) {
  std::cout << "\n";
  std::cout << "Please choose from the following list of seller options: " << std::endl;
  std::cout << "1. Post a product for sale" << std::endl;  // allows seller to post new products for buyers to view and bid on
  std::cout << "2. View/Send messages" << std::endl;       // option to view messages/replies that have been sent back to the seller
  std::cout << "3. Check account balance" << std::endl;    // checks seller's account baalnce
  std::cout << "4. Rate a buyer" << std::endl;             // once transaction is complete, seller is able to rate the buyers of their products
  std::cout << "5. Update user info" << std::endl;         // update private fields inclduing username, address, and phone number
  std::cout << "6. View product list" << std::endl;        // view all currently biddable products posted by given seller
  std::cout << "7. Close bid on a product" << std::endl;   // closes the bidablity of any product currently being listed and send winner/loosers of the bid according messages
  std::cout << "8. Log out" << std::endl;                  // logs the seller out, with options to log in using a different username
  std::string option;
  std::cin >> option;
  std::cout << "\n";

  while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8") {
    std::cout << "Please enter a valid option. Enter your option again (1-8): ";
    std::cin >> option;
  }

  // method used to post products (sorted by catergory and subcategory) for buyers to view and select from
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
    // initial category sorting
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
    // product factory, of 3 subcategories, seller select which one best suits the product they are trying to sell
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
    // input new product information
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
    // final sorting of subcategorials
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
  // used to view and respond to buyer messages
  if (option == "2") {
    std::string* replyTo = NULL;
    int productID = -1;
    s->ReadMessage(&replyTo, productID);
    if (replyTo != NULL) {  // reply to field isn't empty, meaning that content needs to be written to send to buyer
      std::cout << "Please write the content of your message here:" << std::endl;
      std::string content;
      std::getline(std::cin, content);
      std::getline(std::cin, content);
      SendMessage(s->GetUsername(), replyTo, "buyer", content);
      std::cout << "The message is sent to " << *replyTo << "!" << std::endl;
    }
  }
  // display's sellers current balance
  if (option == "3") {
    std::cout << "Your current balance is: " << s->GetAccountBalance() << std::endl;
  }
  // populates buyers to rate that have completed transactions with given seller, else "No users to rate"
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
  // option to change seller private fields i.e username, address, or phone number
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
    // new username
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
    // new phone number
    if (optionChangeInfo == "2") {
      std::cout << "New phone number: ";
      std::string newPhoneNum;
      std::cin >> newPhoneNum;
      s->UpdatePhoneNum(stol(newPhoneNum));
      std::cout << "Your phone number has been changed to \"" << s->GetPhoneNum() << "\"!" << std::endl;
    }
    // new address
    if (optionChangeInfo == "3") {
      std::cout << "New address: ";
      std::string newAddress;
      std::getline(std::cin, newAddress);
      std::getline(std::cin, newAddress);
      s->UpdateAddress(newAddress);
      std::cout << "Your address has been changed to \"" << s->GetAddress() << "\"!" << std::endl;
    }
  }
  // view all currently active products being sold by given seller
  if (option == "6") {
    s->ViewProductList();
  }
  // close any given product once bid meets seller's standards/expected return
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
    // seller decides whether buyer gets the product delivered or whether they have to pick it up
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
          s->UpdateAddress(address);
        }
        // message content contains statement that buyer won the bid
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
          // else, message content contains statement that buyer lost the bid
          SendMessage(s->GetUsername(), buyers[i], "buyer", "You have lost the bid on " + p->GetProductName() + ".");
        }
      }
    }
  }
  // exit the program
  if (option == "8") {
    throw std::exception();
  }
}

/*
 * When logging in, check if there are any messages and notify the user.
 * @param role The role of the user.
 * @param name The username of the user's account.
 */
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

/*
 * The method that helps a user send a message to another user.
 * @param sender The pointer to the name of the sender.
 * @param receiver The pointer to the name of the receiver.
 * @param receiverRole The role of the receiver.
 * @param content The content of the message.
 */
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

/*
 * The method that helps a seller send a message which contains a product ID to the winner.
 * @param sender The pointer to the name of the sender.
 * @param receiver The pointer to the name of the receiver.
 * @param receiverRole The role of the receiver.
 * @param content The content of the message.
 * @param productID The ID of the product that the winner won.
 */
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

/*
 * Print the list of the products that are for sale.
 */
void TextUI::ViewProductsForSale() {
  for (std::map<int, Product*>::iterator i = _products.begin(); i != _products.end(); i++) {
    std::cout << "product id: " << i->first << ", product name: " << i->second->GetProductName() << std::endl;
  }
}

/*
 * The method that returns the pointer to the matching seller.
 * @param name The username of the account.
 * @return The pointer to the matching seller.
 */

// returns pointer of seller identified by username else NULL if not recognized
Seller* TextUI::GetSeller(std::string name) {
  if (_sellers.find(name) != _sellers.end()) {
    return _sellers[name];
  } else {
    return NULL;
  }
}

/*
 * The method that returns the pointer to the matching buyer.
 * @param name The username of the account.
 * @return The pointer to the matching buyer.
 */

// returns pointer of buyer identified by username else NULL if not recognized
Buyer* TextUI::GetBuyer(std::string name) {
  if (_buyers.find(name) != _buyers.end()) {
    return _buyers[name];
  } else {
    return NULL;
  }
}

/*
 * The method that pushes the information of a user to the user list.
 * @param name The username of the account.
 * @param address The address of the user.
 * @param phoneNum The phone number of the user.
 * @param accountBalance The account balance of the user.
 * @param rateTotal The total rate of the user.
 * @param rateCount The count of the rate the user has.
 * @param userType The type of the user's account.
 * @return True if it pushes successfully. False if it fails.
 */
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

/*
 * The method that pushes a product to TextUI's product list and the seller's product list.
 * @param p The pointer to an instance of a product class.
 * @param seller The pointer to the seller.
 * @return True if it pushes successfully. False if it fails.
 */
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

/*
 * Before the program ends, the method stores the information of all users in user list in Users.csv.
 */
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

/*
 * Before the program ends, the method stores the information of all historical orders in Bids.csv.
 */
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
