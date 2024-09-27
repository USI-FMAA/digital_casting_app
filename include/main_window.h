
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class MainWindow {

public:
  MainWindow(int width, int height, const char *title);
  ~MainWindow();
  void runMainLoop();
  void MenuBar();

  // void Render();
private:
  GLFWwindow *window;
  // ImVec4 clear_color;
  // void InitializeImGui();
  // void Cleanup();

};

#endif // MAINWINDOW_H
