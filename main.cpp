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

    if (role == "buyer") {
      t.GetBuyer(username);
    } else {
      t.GetSeller(username);
    }
    break;
  }
}