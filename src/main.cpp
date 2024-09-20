#include "MainWindow.h"
#include <cstdio> // Add this line for fprintf and stderr


int main(int argc, char **argv) {
  try {
    MainWindow mainWindow(1920, 1080, "Digital Casting System v0.1.0");
    mainWindow.RunMainLoop();
  } catch (const std::exception &e) {
    fprintf(stderr, "Exception: %s\n", e.what());
    return 1;
  }
  return 0;
}
