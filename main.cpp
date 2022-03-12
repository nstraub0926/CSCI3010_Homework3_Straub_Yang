#include <fstream>

#include "TextUI.h"

// Names:
// Peter Yang
// Nathan Straub

int main() {
  TextUI& t = TextUI::GetInstance();
  t.LoadInData("Users.csv");
  Seller* s = t.GetSeller("Peter_Yang");
  std::cout << s->GetUsername() << ", address: " << s->GetAddress() << std::endl;
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