#include <fstream>

#include "TextUI.h"

// Names:
// Peter Yang
// Nathan Straub

int main() {
  TextUI& t = TextUI::GetInstance();
  while (1) {
    std::string role = t.DisplayRoleChoice();
    t.LogInUsername(role);

    if (role == "buyer") {
    } else {
    }
    break;
  }
}