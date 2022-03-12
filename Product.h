#pragma once

#include <iostream>
#include <queue>
#include <string>

class Product {
 public:
  Product(std::string name, double basePrice, std::string quality, std::string seller);
  std::string GetProductName() { return _name; };
  bool GetStatus() { return _status; };
  void SetStatus(bool status) { _status = status; };
  double GetBasePrice() { return _basePrice; };
  std::pair<double, std::string> GetHighestBidInfo() { return _bidList.top(); };
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
};

class Camera : public Electronics {
 public:
  Camera(std::string name, double basePrice, std::string quality, std::string seller) : Electronics(name, basePrice, quality, seller){};
};

class Television : public Electronics {
 public:
  Television(std::string name, double basePrice, std::string quality, std::string seller) : Electronics(name, basePrice, quality, seller){};
};

class Phone : public Electronics {
 public:
  Phone(std::string name, double basePrice, std::string quality, std::string seller) : Electronics(name, basePrice, quality, seller){};
};

class Computers : public Product {
 public:
  Computers(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
};

class Monitors : public Computers {
 public:
  Monitors(std::string name, double basePrice, std::string quality, std::string seller) : Computers(name, basePrice, quality, seller){};
};

class Mouse : public Computers {
 public:
  Mouse(std::string name, double basePrice, std::string quality, std::string seller) : Computers(name, basePrice, quality, seller){};
};

class Keyboard : public Computers {
 public:
  Keyboard(std::string name, double basePrice, std::string quality, std::string seller) : Computers(name, basePrice, quality, seller){};
};

class Sports : public Product {
 public:
  Sports(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
};

class Basketball : public Sports {
 public:
  Basketball(std::string name, double basePrice, std::string quality, std::string seller) : Sports(name, basePrice, quality, seller){};
};

class Football : public Sports {
 public:
  Football(std::string name, double basePrice, std::string quality, std::string seller) : Sports(name, basePrice, quality, seller){};
};

class Baseball : public Sports {
 public:
  Baseball(std::string name, double basePrice, std::string quality, std::string seller) : Sports(name, basePrice, quality, seller){};
};

class Clothing : public Product {
 public:
  Clothing(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
};

class MenClothing : public Clothing {
 public:
  MenClothing(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
};

class WomenClothing : public Clothing {
 public:
  WomenClothing(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
};

class Necklaces : public Clothing {
 public:
  Necklaces(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
};

class Books : public Product {
 public:
  Books(std::string name, double basePrice, std::string quality, std::string seller) : Product(name, basePrice, quality, seller){};
};

class Textbooks : public Books {
 public:
  Textbooks(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
};

class Novels : public Books {
 public:
  Novels(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
};

class Cookbooks : public Books {
 public:
  Cookbooks(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
};

class ProductFactory {
 public:
  static Camera* AddCamera(std::string name, double basePrice, std::string quality, std::string seller) { return new Camera(name, basePrice, quality, seller); };
  static Television* AddTelevision(std::string name, double basePrice, std::string quality, std::string seller) { return new Television(name, basePrice, quality, seller); };
  static Phone* AddPhone(std::string name, double basePrice, std::string quality, std::string seller) { return new Phone(name, basePrice, quality, seller); };
  static Monitors* AddMonitors(std::string name, double basePrice, std::string quality, std::string seller) { return new Monitors(name, basePrice, quality, seller); };
  static Mouse* AddMouse(std::string name, double basePrice, std::string quality, std::string seller) { return new Mouse(name, basePrice, quality, seller); };
  static Keyboard* AddKeyboard(std::string name, double basePrice, std::string quality, std::string seller) { return new Keyboard(name, basePrice, quality, seller); };
  static Basketball* AddBasketball(std::string name, double basePrice, std::string quality, std::string seller) { return new Basketball(name, basePrice, quality, seller); };
  static Football* AddFootball(std::string name, double basePrice, std::string quality, std::string seller) { return new Football(name, basePrice, quality, seller); };
  static Baseball* AddBaseball(std::string name, double basePrice, std::string quality, std::string seller) { return new Baseball(name, basePrice, quality, seller); };
  static MenClothing* AddMenClothing(std::string name, double basePrice, std::string quality, std::string seller) { return new MenClothing(name, basePrice, quality, seller); };
  static WomenClothing* AddWomenClothing(std::string name, double basePrice, std::string quality, std::string seller) { return new WomenClothing(name, basePrice, quality, seller); };
  static Necklaces* AddNecklaces(std::string name, double basePrice, std::string quality, std::string seller) { return new Necklaces(name, basePrice, quality, seller); };
  static Textbooks* AddTextbooks(std::string name, double basePrice, std::string quality, std::string seller) { return new Textbooks(name, basePrice, quality, seller); };
  static Novels* AddNovels(std::string name, double basePrice, std::string quality, std::string seller) { return new Novels(name, basePrice, quality, seller); };
  static Cookbooks* AddCookbooks(std::string name, double basePrice, std::string quality, std::string seller) { return new Cookbooks(name, basePrice, quality, seller); };
};