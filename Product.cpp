#include "Product.h"

Product::Product(std::string name, double basePrice, std::string quality, std::string seller) : _name(name), _basePrice(basePrice), _quality(quality), _seller(seller) {
  _status = true;
  _buyer = "";
};

void Product::SetCurrentBid(double newBid, std::string buyer) {
  _bidList.push(std::make_pair(newBid, buyer));
}