#include "app.h"
#include <iostream>

void App::setMessage() {
    message = "wellcome to the app";
}
void App::sendMessage() {
    std::cout << message << std::endl;
}

