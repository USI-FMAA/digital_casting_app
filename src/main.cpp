#include "main_window.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Wellcome to digital casting app" << "\n";
  int widthRes = 1920;
  int heightRes = 1080;

  MainWindow mainWindow(widthRes, heightRes, "DIGITAL CASTING SYSTEM v0.1.0");
  mainWindow.RunMainLoop();

  return 0;
}
