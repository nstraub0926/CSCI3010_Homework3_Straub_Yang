#include <fstream>

#include "TextUI.h"

// Names:
// Peter Yang
// Nathan Straub

int main() {
  TextUI& t = TextUI::GetInstance();
  t.LoadInUserData("Users.csv");
  t.LoadInBidsData("Bids.csv");
  t.SendMessage("Nathan_Straub", "Peter_Yang", "seller", "test1");
  t.SendMessage("Nathan_Straub", "Peter_Yang", "seller", "test2");

  while (1) {
    std::string role = t.DisplayRoleChoice();
    std::string username;
    try {
      username = t.LogInUsername(role);
    } catch (std::exception&) {
      break;
    }
    if (role == "buyer") {
      std::cout << "Welcome " << username << "! ";
      t.CheckMessagebox("buyer", username);
      while (1) {
        try {
          t.DisplayForBuyer(username);
        } catch (std::exception&) {
          break;
        }
      }
    } else {
      std::cout << "Welcome " << username << "! ";
      t.CheckMessagebox("seller", username);
      while (1) {
        try {
          t.DisplayForSeller(username);
        } catch (std::exception&) {
          break;
        }
      }
    }
    std::cout << "Do you want to log in with another username? (yes/no): ";
    std::string option;
    std::cin >> option;
    while (option != "yes" && option != "no") {
      std::cout << "Please enter a valid option. Enter the option again (yes/no): ";
      std::cin >> option;
    }
    if (option == "no") {
      break;
    }
  }
  std::cout << "Thank you for choosing BidToBuy. We expect your next visit." << std::endl;
}