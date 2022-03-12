#pragma once

#include <iostream>

class Message {
 public:
  Message(std::string sender, std::string receiver, std::string content) : _sender(sender), _receiver(receiver), _content(content){};
  std::string GetSender() { return _sender; };
  std::string GetReceiver() { return _receiver; };
  std::string GetContent() { return _content; };

 private:
  std::string _sender;
  std::string _receiver;
  std::string _content;
};