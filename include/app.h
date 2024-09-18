#pragma once
#ifdef APP_H
#define APP_H

#include <string>

class App {
private:
  std::string message;

public:
  void sendMessage();
}

#endif // APP_H
