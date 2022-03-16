#include <fstream>

#include "TextUI.h"

// Names:
// Peter Yang
// Nathan Straub

/*
 * Homework 3
 * This is a program that simulates eBay in CLI program.
 */

int main() {
  TextUI& t = TextUI::GetInstance();
  t.LoadInUserData("Users.csv");
  t.LoadInBidsData("Bids.csv");

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
      Buyer* b = t.GetBuyer(username);
      while (1) {
        try {
          t.DisplayForBuyer(b);
        } catch (std::exception&) {
          break;
        }
      }
    } else {
      std::cout << "Welcome " << username << "! ";
      t.CheckMessagebox("seller", username);
      Seller* s = t.GetSeller(username);
      while (1) {
        try {
          t.DisplayForSeller(s);
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
  t.WriteToUsersCSV();
  t.WriteToBidsCSV();
  std::cout << "Thank you for choosing BidToBuy. Visit again soon!" << std::endl;
}