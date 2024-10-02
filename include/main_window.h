#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <string>
#include <vector>

class MainWindow {

public:
  MainWindow(int width, int height, const std::string &title);
  ~MainWindow();
  void RunMainLoop();
  void MenuBar();
  void ToolBar(const std::string &barName,
               const std::vector<std::string> &buttonNames,
               bool &showWindow);


  // void Render();
private:
  GLFWwindow *window;
  // ImVec4 clear_color;
  // void InitializeImGui();
  // void Cleanup();
};

#endif // MAINWINDOW_H
