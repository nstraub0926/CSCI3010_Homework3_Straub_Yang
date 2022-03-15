#pragma once

#include <iostream>

class Message {
 public:
  Message(std::string* sender, std::string* receiver, std::string content) : _sender(sender), _receiver(receiver), _content(content) {
    _productID = -1;
    _isConfirmationMessage = false;
  };
  Message(std::string* sender, std::string* receiver, std::string content, int productID) : _sender(sender), _receiver(receiver), _content(content), _productID(productID) {
    _isConfirmationMessage = true;
  };

  std::string* GetSender() { return _sender; };
  std::string* GetReceiver() { return _receiver; };
  std::string GetContent() { return _content; };
  int GetProductID() { return _productID; };
  bool IsConfirmationMessage() { return _isConfirmationMessage; };

 private:
  std::string* _sender;
  std::string* _receiver;
  std::string _content;
  int _productID;
  bool _isConfirmationMessage;
};