#include <fstream>

#include "TextUI.h"

// Names:
// Peter Yang
// Nathan Straub

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

    try {
      if (role == "buyer") {
        while (1) {
          t.DisplayForBuyer(username);
        }
      } else {
        while (1) {
          t.DisplayForSeller(username);
        }
      }
    } catch (std::exception&) {
      break;
    }
  }
  std::cout << "Thank you for choosing BidToBuy. We expect your next visit." << std::endl;
}