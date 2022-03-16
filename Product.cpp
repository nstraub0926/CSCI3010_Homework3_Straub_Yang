#include "Product.h"

#include <set>

// instantiates new product with assigned fields, buyer username and delivery boolean set to NULL
Product::Product(std::string name, double basePrice, std::string quality, std::string seller) : _name(name), _basePrice(basePrice), _quality(quality), _seller(seller) {
  _buyer = "";
  _delivery = false;
};

// constructor for adding info about bidded on item to appropriate buyer
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

// pushes newest bid to top of priority queue
void Product::SetCurrentBid(double newBid, std::string buyer) {
  _bidList.push(std::make_pair(newBid, buyer));
}