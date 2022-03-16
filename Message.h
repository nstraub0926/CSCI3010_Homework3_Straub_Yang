#pragma once

#include <iostream>

class Message {
 public:
  // Constructor for the message that does not contain a productID
  Message(std::string* sender, std::string* receiver, std::string content) : _sender(sender), _receiver(receiver), _content(content) {
    _productID = -1;
    _isConfirmationMessage = false;
  };
  // Constructor for the message that contains a productID
  Message(std::string* sender, std::string* receiver, std::string content, int productID) : _sender(sender), _receiver(receiver), _content(content), _productID(productID) {
    _isConfirmationMessage = true;
  };

  std::string* GetSender() { return _sender; };                     // Getter method for sender
  std::string* GetReceiver() { return _receiver; };                 // Getter method for receiver
  std::string GetContent() { return _content; };                    // Getter method for content
  int GetProductID() { return _productID; };                        // Getter method for productID
  bool IsConfirmationMessage() { return _isConfirmationMessage; };  // check if the message is a confirmation message

 private:
  std::string* _sender;
  std::string* _receiver;
  std::string _content;
  int _productID;
  bool _isConfirmationMessage;
};