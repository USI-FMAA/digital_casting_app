// MainWindow.hpp

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <imgui.h>
#include <GLFW/glfw3.h>

class MainWindow {

public:
    MainWindow(int width, int height, const char* title);
    ~MainWindow();

    void Render();
    void RunMainLoop();

private:
    GLFWwindow* window;
    ImVec4 clear_color;

    void InitializeImGui();
    void Cleanup();
};

#endif // MAINWINDOW_H
