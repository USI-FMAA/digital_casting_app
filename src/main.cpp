#include "main_window.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Wellcome to digital casting app" << "\n";

  MainWindow mainWindow(1920, 1080, "DIGITAL CASTING SYSTEM v0.1.0");
  mainWindow.runMainLoop();

  return 0;
}
