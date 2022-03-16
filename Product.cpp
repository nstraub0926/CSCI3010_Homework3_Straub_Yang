#include "Product.h"

#include <set>

/*
 * The constructor for instantiating a product.
 * @param name The name of the product.
 * @param basePrice The basePrice of the product.
 * @param quality The quality of the product.
 * @param seller The pointer to the seller.
 */

// instantiates new product with assigned fields, buyer username and delivery boolean set to NULL
Product::Product(std::string name, double basePrice, std::string quality, std::string* seller) : _name(name), _basePrice(basePrice), _quality(quality), _seller(seller) {
  _buyer = NULL;
  _delivery = false;
  _status = true;
};

/*
 * The constructor for instantiating a product when reading from Bids.csv.
 * @param name The name of the product.
 * @param basePrice The basePrice of the product.
 * @param quality The quality of the product.
 * @param seller The pointer to the seller.
 * @param bid A pair that contains the information of the highest bid and the person who won the product previously.
 */

// constructor for adding info about bidded on item to appropriate buyer
Product::Product(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : _name(name), _basePrice(basePrice), _quality(quality) {
  _seller = new std::string(seller);
  _buyer = new std::string(bid.second);
  _bidList.push(std::make_pair(bid.first, _buyer));
  _status = false;
};

/*
 * The method that returns the pointers to the names of buyers who placed bids on the product.
 * @return The buyers who placed bid on the product. The vector should not have duplicate names.
 */
std::vector<std::string*> Product::ExtractBuyers() {
  std::vector<std::string*> output;
  std::priority_queue<std::pair<double, std::string*> > tmp = _bidList;
  std::set<std::string> checkDuplicateBuyer;
  while (!tmp.empty()) {
    if (checkDuplicateBuyer.find(*tmp.top().second) == checkDuplicateBuyer.end()) {
      checkDuplicateBuyer.insert(*tmp.top().second);
      output.push_back(tmp.top().second);
    }
    tmp.pop();
  }
  return output;
}

/*
 * The method that lets a buyer place a bid on the product.
 * @param newBid The bid that the buyer wants to place on the product.
 * @param buyer The pointer to the buyer.
 * @return
 */

// pushes newest bid to top of priority queue
void Product::SetCurrentBid(double newBid, std::string* buyer) {
  _bidList.push(std::make_pair(newBid, buyer));
}