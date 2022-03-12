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
  MenClothing(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
};

class Necklaces : public Clothing {
 public:
  MenClothing(std::string name, double basePrice, std::string quality, std::string seller) : Clothing(name, basePrice, quality, seller){};
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
  Textbooks(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
};

class Cookbooks : public Books {
 public:
  Textbooks(std::string name, double basePrice, std::string quality, std::string seller) : Books(name, basePrice, quality, seller){};
};


class ProductFactory {
 public:
  static Camera* AddCamera(std::string name, double basePrice, std::string quality, std::string seller) { return new Camera(name, basePrice, quality, seller); };
  static Television* AddTelevision();
  static Phone* AddPhone();
  static Monitors* AddMonitors();
  static Mouse* AddMouse();
  static Keyboard* AddKeyboard();
  static Basketball* AddBasketball();
  static Football* AddFootball();
  static Baseball* AddBaseball();
  static MenClothing* AddMenClothing();
  static WomenClothing* AddWomenClothing();
  static Necklace* AddNecklace();
  static Textbooks* AddTextbooks();
  static Novels* AddNovels();
  static Cookbooks* AddCookbooks();
};