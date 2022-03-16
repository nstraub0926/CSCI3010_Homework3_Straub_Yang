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
  TextUI& t = TextUI::GetInstance();  // singleton instance for displaying UI
  t.LoadInUserData("Users.csv");      // load in user data
  t.LoadInBidsData("Bids.csv");       // load in bid history data

  while (1) {  // always route back to selection of role, unless keyboard interrupts (e)
    std::string role = t.DisplayRoleChoice();
    std::string username;
    try {
      username = t.LogInUsername(role);  // returns username used to access user info
    } catch (std::exception&) {          // exit break response
      break;
    }
    if (role == "buyer") {  // buyer subroute
      std::cout << std::endl;
      std::cout << "Welcome " << username << "! ";
      t.CheckMessagebox("buyer", username);
      Buyer* b = t.GetBuyer(username);
      while (1) {  // always display buyer menu options until option 8 is selected
        try {
          t.DisplayForBuyer(b);
        } catch (std::exception&) {
          break;
        }
      }
    } else {  // seller subroute
      std::cout << std::endl;
      std::cout << "Welcome " << username << "! ";
      t.CheckMessagebox("seller", username);

      Seller* s = t.GetSeller(username);
      while (1) {  // always display seller menu options until option 8 is selected
        try {
          t.DisplayForSeller(s);
        } catch (std::exception&) {
          break;
        }
      }
    }
    std::cout << "Do you want to log in with another username? (yes/no): ";  // ask user if they want to log in using another user (implemented for testing purposes)
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
<<<<<<< HEAD
  t.WriteToUsersCSV();  // write all changes to data members back to Users.csv file
  t.WriteToBidsCSV();   // write all additional product sales to Bids.csv file
=======
  t.WriteToUsersCSV(); // write all changes to data members back to Users.csv file
  t.WriteToBidsCSV(); // write all additional product sales to Bids.csv file
>>>>>>> 5853e037276157532670c18908abdb9cc41ec63d
  std::cout << "Thank you for choosing BidToBuy. Visit again soon!" << std::endl;
}