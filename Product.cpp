#include "Product.h"

#include <set>

Product::Product(std::string name, double basePrice, std::string quality, std::string seller) : _name(name), _basePrice(basePrice), _quality(quality), _seller(seller) {
  _buyer = "";
  _delivery = false;
};

Product::Product(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : _name(name), _basePrice(basePrice), _quality(quality), _seller(seller) {
  _bidList.push(bid);
  _buyer = bid.second;
};

std::vector<std::string> Product::ExtractBuyers() {
  std::vector<std::string> output;
  std::priority_queue<std::pair<double, std::string> > tmp = _bidList;
  std::set<std::string> checkDuplicateBuyer;
  while (!tmp.empty()) {
    if (checkDuplicateBuyer.find(tmp.top().second) == checkDuplicateBuyer.end()) {
      checkDuplicateBuyer.insert(tmp.top().second);
      output.push_back(tmp.top().second);
    }
    tmp.pop();
  }
  return output;
}

void Product::SetCurrentBid(double newBid, std::string buyer) {
  _bidList.push(std::make_pair(newBid, buyer));
}