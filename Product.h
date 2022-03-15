#pragma once

#include <iostream>
#include <queue>
#include <string>

class Product {
 public:
  Product(std::string name, double basePrice, std::string quality, std::string* seller);
  Product(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid);
  std::string GetProductName() { return _name; };
  double GetBasePrice() { return _basePrice; };
  std::pair<double, std::string*> GetHighestBidInfo() { return _bidList.empty() ? std::make_pair<double, std::string*>(0, NULL) : _bidList.top(); };
  std::vector<std::string*> ExtractBuyers();
  void SetCurrentBid(double newBid, std::string* buyer);
  std::string GetQuality() { return _quality; };
  void SetDelivery() { _delivery = true; };
  bool IsDelivered() { return _delivery; };
  std::string* GetSeller() { return _seller; };
  void SetBuyer(std::string* buyer) { _buyer = buyer; };
  std::string* GetBuyer() { return _buyer; };
  void SetProductSubcategory(std::string subcategory) { _productSubcategory = subcategory; };
  std::string GetProductSubcategory() { return _productSubcategory; };

 private:
  std::string _name;
  double _basePrice;
  std::string _quality;
  std::string* _seller;
  std::string* _buyer;
  std::priority_queue<std::pair<double, std::string*> > _bidList;
  bool _delivery;
  std::string _productSubcategory;
};

class Electronics : public Product {
 public:
  Electronics(std::string name, double basePrice, std::string quality, std::string* seller) : Product(name, basePrice, quality, seller){};
  Electronics(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Camera : public Electronics {
 public:
  Camera(std::string name, double basePrice, std::string quality, std::string* seller) : Electronics(name, basePrice, quality, seller) {
    SetProductSubcategory("Camera");
  };
  Camera(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Electronics(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Camera");
  };
};

class Television : public Electronics {
 public:
  Television(std::string name, double basePrice, std::string quality, std::string* seller) : Electronics(name, basePrice, quality, seller) {
    SetProductSubcategory("Television");
  };
  Television(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Electronics(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Television");
  };
};

class Phone : public Electronics {
 public:
  Phone(std::string name, double basePrice, std::string quality, std::string* seller) : Electronics(name, basePrice, quality, seller) {
    SetProductSubcategory("Phone");
  };
  Phone(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Electronics(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Phone");
  };
};

class Computers : public Product {
 public:
  Computers(std::string name, double basePrice, std::string quality, std::string* seller) : Product(name, basePrice, quality, seller){};
  Computers(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Monitors : public Computers {
 public:
  Monitors(std::string name, double basePrice, std::string quality, std::string* seller) : Computers(name, basePrice, quality, seller) {
    SetProductSubcategory("Monitors");
  };
  Monitors(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Computers(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Monitors");
  };
};

class Mouse : public Computers {
 public:
  Mouse(std::string name, double basePrice, std::string quality, std::string* seller) : Computers(name, basePrice, quality, seller) {
    SetProductSubcategory("Mouse");
  };
  Mouse(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Computers(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Mouse");
  };
};

class Keyboard : public Computers {
 public:
  Keyboard(std::string name, double basePrice, std::string quality, std::string* seller) : Computers(name, basePrice, quality, seller) {
    SetProductSubcategory("Keyboard");
  };
  Keyboard(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Computers(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Keyboard");
  };
};

class Sports : public Product {
 public:
  Sports(std::string name, double basePrice, std::string quality, std::string* seller) : Product(name, basePrice, quality, seller){};
  Sports(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Basketball : public Sports {
 public:
  Basketball(std::string name, double basePrice, std::string quality, std::string* seller) : Sports(name, basePrice, quality, seller) {
    SetProductSubcategory("Basketball");
  };
  Basketball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Sports(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Basketball");
  };
};

class Football : public Sports {
 public:
  Football(std::string name, double basePrice, std::string quality, std::string* seller) : Sports(name, basePrice, quality, seller) {
    SetProductSubcategory("Football");
  };
  Football(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Sports(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Football");
  };
};

class Baseball : public Sports {
 public:
  Baseball(std::string name, double basePrice, std::string quality, std::string* seller) : Sports(name, basePrice, quality, seller) {
    SetProductSubcategory("Baseball");
  };
  Baseball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Sports(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Baseball");
  };
};

class Clothing : public Product {
 public:
  Clothing(std::string name, double basePrice, std::string quality, std::string* seller) : Product(name, basePrice, quality, seller){};
  Clothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class MenClothing : public Clothing {
 public:
  MenClothing(std::string name, double basePrice, std::string quality, std::string* seller) : Clothing(name, basePrice, quality, seller) {
    SetProductSubcategory("MenClothing");
  };
  MenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Clothing(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("MenClothing");
  };
};

class WomenClothing : public Clothing {
 public:
  WomenClothing(std::string name, double basePrice, std::string quality, std::string* seller) : Clothing(name, basePrice, quality, seller) {
    SetProductSubcategory("WomenClothing");
  };
  WomenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Clothing(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("WomenClothing");
  };
};

class Necklaces : public Clothing {
 public:
  Necklaces(std::string name, double basePrice, std::string quality, std::string* seller) : Clothing(name, basePrice, quality, seller) {
    SetProductSubcategory("Necklaces");
  };
  Necklaces(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Clothing(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Necklaces");
  };
};

class Books : public Product {
 public:
  Books(std::string name, double basePrice, std::string quality, std::string* seller) : Product(name, basePrice, quality, seller){};
  Books(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Textbooks : public Books {
 public:
  Textbooks(std::string name, double basePrice, std::string quality, std::string* seller) : Books(name, basePrice, quality, seller) {
    SetProductSubcategory("Textbooks");
  };
  Textbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Books(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Textbooks");
  };
};

class Novels : public Books {
 public:
  Novels(std::string name, double basePrice, std::string quality, std::string* seller) : Books(name, basePrice, quality, seller) {
    SetProductSubcategory("Novels");
  };
  Novels(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Books(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Novels");
  };
};

class Cookbooks : public Books {
 public:
  Cookbooks(std::string name, double basePrice, std::string quality, std::string* seller) : Books(name, basePrice, quality, seller) {
    SetProductSubcategory("Cookbooks");
  };
  Cookbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Books(name, basePrice, quality, seller, bid) {
    SetProductSubcategory("Cookbooks");
  };
};

class ProductFactory {
 public:
  static Camera* AddCamera(std::string name, double basePrice, std::string quality, std::string* seller) { return new Camera(name, basePrice, quality, seller); };
  static Camera* AddCamera(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Camera(name, basePrice, quality, seller, bid); };
  static Television* AddTelevision(std::string name, double basePrice, std::string quality, std::string* seller) { return new Television(name, basePrice, quality, seller); };
  static Television* AddTelevision(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Television(name, basePrice, quality, seller, bid); };
  static Phone* AddPhone(std::string name, double basePrice, std::string quality, std::string* seller) { return new Phone(name, basePrice, quality, seller); };
  static Phone* AddPhone(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Phone(name, basePrice, quality, seller, bid); };
  static Monitors* AddMonitors(std::string name, double basePrice, std::string quality, std::string* seller) { return new Monitors(name, basePrice, quality, seller); };
  static Monitors* AddMonitors(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Monitors(name, basePrice, quality, seller, bid); };
  static Mouse* AddMouse(std::string name, double basePrice, std::string quality, std::string* seller) { return new Mouse(name, basePrice, quality, seller); };
  static Mouse* AddMouse(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Mouse(name, basePrice, quality, seller, bid); };
  static Keyboard* AddKeyboard(std::string name, double basePrice, std::string quality, std::string* seller) { return new Keyboard(name, basePrice, quality, seller); };
  static Keyboard* AddKeyboard(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Keyboard(name, basePrice, quality, seller, bid); };
  static Basketball* AddBasketball(std::string name, double basePrice, std::string quality, std::string* seller) { return new Basketball(name, basePrice, quality, seller); };
  static Basketball* AddBasketball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Basketball(name, basePrice, quality, seller, bid); };
  static Football* AddFootball(std::string name, double basePrice, std::string quality, std::string* seller) { return new Football(name, basePrice, quality, seller); };
  static Football* AddFootball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Football(name, basePrice, quality, seller, bid); };
  static Baseball* AddBaseball(std::string name, double basePrice, std::string quality, std::string* seller) { return new Baseball(name, basePrice, quality, seller); };
  static Baseball* AddBaseball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Baseball(name, basePrice, quality, seller, bid); };
  static MenClothing* AddMenClothing(std::string name, double basePrice, std::string quality, std::string* seller) { return new MenClothing(name, basePrice, quality, seller); };
  static MenClothing* AddMenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new MenClothing(name, basePrice, quality, seller, bid); };
  static WomenClothing* AddWomenClothing(std::string name, double basePrice, std::string quality, std::string* seller) { return new WomenClothing(name, basePrice, quality, seller); };
  static WomenClothing* AddWomenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new WomenClothing(name, basePrice, quality, seller, bid); };
  static Necklaces* AddNecklaces(std::string name, double basePrice, std::string quality, std::string* seller) { return new Necklaces(name, basePrice, quality, seller); };
  static Necklaces* AddNecklaces(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Necklaces(name, basePrice, quality, seller, bid); };
  static Textbooks* AddTextbooks(std::string name, double basePrice, std::string quality, std::string* seller) { return new Textbooks(name, basePrice, quality, seller); };
  static Textbooks* AddTextbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Textbooks(name, basePrice, quality, seller, bid); };
  static Novels* AddNovels(std::string name, double basePrice, std::string quality, std::string* seller) { return new Novels(name, basePrice, quality, seller); };
  static Novels* AddNovels(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Novels(name, basePrice, quality, seller, bid); };
  static Cookbooks* AddCookbooks(std::string name, double basePrice, std::string quality, std::string* seller) { return new Cookbooks(name, basePrice, quality, seller); };
  static Cookbooks* AddCookbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Cookbooks(name, basePrice, quality, seller, bid); };
};