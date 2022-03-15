#pragma once

#include <iostream>
#include <queue>
#include <string>

class Product {
 public:
  Product(std::string name, double basePrice, std::string quality, std::string seller);
  Product(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid);
  std::string GetProductName() { return _name; };
  bool GetStatus() { return _status; };
  void SetStatus(bool status) { _status = status; };
  double GetBasePrice() { return _basePrice; };
  std::pair<double, std::string> GetHighestBidInfo() { return _bidList.empty() ? std::make_pair<double, std::string>(0, "") : _bidList.top(); };
  std::vector<std::string> CloseOnBid();
  void SetCurrentBid(double newBid, std::string buyer);
  std::string GetQuality() { return _quality; };

 private:
  std::string _name;
  bool _status;
  double _basePrice;
  std::string _quality;
  std::string _seller;
  std::string _buyer;
  std::priority_queue<std::pair<double, std::string> > _bidList;
};

class Electronics : public Product {
 public:
  Electronics(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
  Electronics(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Camera : public Electronics {
 public:
  Camera(std::string name, double basePrice, std::string quality, std::string seller) : Electronics(name, basePrice, quality, seller){};
  Camera(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Electronics(name, basePrice, quality, seller, bid){};
};

class Television : public Electronics {
 public:
  Television(std::string name, double basePrice, std::string quality, std::string seller) : Electronics(name, basePrice, quality, seller){};
  Television(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Electronics(name, basePrice, quality, seller, bid){};
};

class Phone : public Electronics {
 public:
  Phone(std::string name, double basePrice, std::string quality, std::string seller) : Electronics(name, basePrice, quality, seller){};
  Phone(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Electronics(name, basePrice, quality, seller, bid){};
};

class Computers : public Product {
 public:
  Computers(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
  Computers(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Monitors : public Computers {
 public:
  Monitors(std::string name, double basePrice, std::string quality, std::string seller) : Computers(name, basePrice, quality, seller){};
  Monitors(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Computers(name, basePrice, quality, seller, bid){};
};

class Mouse : public Computers {
 public:
  Mouse(std::string name, double basePrice, std::string quality, std::string seller) : Computers(name, basePrice, quality, seller){};
  Mouse(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Computers(name, basePrice, quality, seller, bid){};
};

class Keyboard : public Computers {
 public:
  Keyboard(std::string name, double basePrice, std::string quality, std::string seller) : Computers(name, basePrice, quality, seller){};
  Keyboard(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Computers(name, basePrice, quality, seller, bid){};
};

class Sports : public Product {
 public:
  Sports(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
  Sports(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Basketball : public Sports {
 public:
  Basketball(std::string name, double basePrice, std::string quality, std::string seller) : Sports(name, basePrice, quality, seller){};
  Basketball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Sports(name, basePrice, quality, seller, bid){};
};

class Football : public Sports {
 public:
  Football(std::string name, double basePrice, std::string quality, std::string seller) : Sports(name, basePrice, quality, seller){};
  Football(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Sports(name, basePrice, quality, seller, bid){};
};

class Baseball : public Sports {
 public:
  Baseball(std::string name, double basePrice, std::string quality, std::string seller) : Sports(name, basePrice, quality, seller){};
  Baseball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Sports(name, basePrice, quality, seller, bid){};
};

class Clothing : public Product {
 public:
  Clothing(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
  Clothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class MenClothing : public Clothing {
 public:
  MenClothing(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
  MenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Clothing(name, basePrice, quality, seller, bid){};
};

class WomenClothing : public Clothing {
 public:
  WomenClothing(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
  WomenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Clothing(name, basePrice, quality, seller, bid){};
};

class Necklaces : public Clothing {
 public:
  Necklaces(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
  Necklaces(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Clothing(name, basePrice, quality, seller, bid){};
};

class Books : public Product {
 public:
  Books(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
  Books(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Product(name, basePrice, quality, seller, bid){};
};

class Textbooks : public Books {
 public:
  Textbooks(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
  Textbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Books(name, basePrice, quality, seller, bid){};
};

class Novels : public Books {
 public:
  Novels(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
  Novels(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Books(name, basePrice, quality, seller, bid){};
};

class Cookbooks : public Books {
 public:
  Cookbooks(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
  Cookbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) : Books(name, basePrice, quality, seller, bid){};
};

class ProductFactory {
 public:
  static Camera* AddCamera(std::string name, double basePrice, std::string quality, std::string seller) { return new Camera(name, basePrice, quality, seller); };
  static Camera* AddCamera(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Camera(name, basePrice, quality, seller, bid); };
  static Television* AddTelevision(std::string name, double basePrice, std::string quality, std::string seller) { return new Television(name, basePrice, quality, seller); };
  static Television* AddTelevision(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Television(name, basePrice, quality, seller, bid); };
  static Phone* AddPhone(std::string name, double basePrice, std::string quality, std::string seller) { return new Phone(name, basePrice, quality, seller); };
  static Phone* AddPhone(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Phone(name, basePrice, quality, seller, bid); };
  static Monitors* AddMonitors(std::string name, double basePrice, std::string quality, std::string seller) { return new Monitors(name, basePrice, quality, seller); };
  static Monitors* AddMonitors(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Monitors(name, basePrice, quality, seller, bid); };
  static Mouse* AddMouse(std::string name, double basePrice, std::string quality, std::string seller) { return new Mouse(name, basePrice, quality, seller); };
  static Mouse* AddMouse(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Mouse(name, basePrice, quality, seller, bid); };
  static Keyboard* AddKeyboard(std::string name, double basePrice, std::string quality, std::string seller) { return new Keyboard(name, basePrice, quality, seller); };
  static Keyboard* AddKeyboard(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Keyboard(name, basePrice, quality, seller, bid); };
  static Basketball* AddBasketball(std::string name, double basePrice, std::string quality, std::string seller) { return new Basketball(name, basePrice, quality, seller); };
  static Basketball* AddBasketball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Basketball(name, basePrice, quality, seller, bid); };
  static Football* AddFootball(std::string name, double basePrice, std::string quality, std::string seller) { return new Football(name, basePrice, quality, seller); };
  static Football* AddFootball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Football(name, basePrice, quality, seller, bid); };
  static Baseball* AddBaseball(std::string name, double basePrice, std::string quality, std::string seller) { return new Baseball(name, basePrice, quality, seller); };
  static Baseball* AddBaseball(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Baseball(name, basePrice, quality, seller, bid); };
  static MenClothing* AddMenClothing(std::string name, double basePrice, std::string quality, std::string seller) { return new MenClothing(name, basePrice, quality, seller); };
  static MenClothing* AddMenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new MenClothing(name, basePrice, quality, seller, bid); };
  static WomenClothing* AddWomenClothing(std::string name, double basePrice, std::string quality, std::string seller) { return new WomenClothing(name, basePrice, quality, seller); };
  static WomenClothing* AddWomenClothing(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new WomenClothing(name, basePrice, quality, seller, bid); };
  static Necklaces* AddNecklaces(std::string name, double basePrice, std::string quality, std::string seller) { return new Necklaces(name, basePrice, quality, seller); };
  static Necklaces* AddNecklaces(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Necklaces(name, basePrice, quality, seller, bid); };
  static Textbooks* AddTextbooks(std::string name, double basePrice, std::string quality, std::string seller) { return new Textbooks(name, basePrice, quality, seller); };
  static Textbooks* AddTextbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Textbooks(name, basePrice, quality, seller, bid); };
  static Novels* AddNovels(std::string name, double basePrice, std::string quality, std::string seller) { return new Novels(name, basePrice, quality, seller); };
  static Novels* AddNovels(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Novels(name, basePrice, quality, seller, bid); };
  static Cookbooks* AddCookbooks(std::string name, double basePrice, std::string quality, std::string seller) { return new Cookbooks(name, basePrice, quality, seller); };
  static Cookbooks* AddCookbooks(std::string name, double basePrice, std::string quality, std::string seller, std::pair<double, std::string> bid) { return new Cookbooks(name, basePrice, quality, seller, bid); };
};