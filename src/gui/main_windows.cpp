#include "imgui.h"
#include "main_window.h"
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <stdio.h>

static void glfw_error_callback(int error, const char *description) {
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

MainWindow::MainWindow(int width, int height, const std::string &title) {

  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    // return 1;
    throw std::runtime_error("Failed to initialize GLFW");

// Decide GL+GLSL versions
#if defined(__APPLE__)
  const char *glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
  const char *glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

  // Create window with graphics context
  window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
  if (!window)
    throw std::runtime_error("Failed to create GLFW window");

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  // ImPlot::CreateContext();

  ImGuiIO &io = ImGui::GetIO();

  // font
  io.FontGlobalScale = 1.8f;
  std::filesystem::path rootDir = std::filesystem::current_path();
  std::filesystem::path fontDir =
      rootDir / "assets" / "font" / "Roboto-Regular.ttf";

  ImFont *appFont =
      io.Fonts->AddFontFromFileTTF(fontDir.string().c_str(), 16.0f);

  // ImFont *appFont = io.Fonts ->
  // AddFontFromFileTTF("C:/Users/weitingchen/work/99_Github/
  // 02_USI/digital_casting_app_dev/assets/font/Roboto-Regular.ttf ", 16.0f);

  if (appFont == nullptr) {
    throw std::runtime_error("Failed to load font");
  } else {
    io.FontDefault = appFont;
  }

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  // ImGui::StyleColorsLight();
  ImGuiStyle *style = &ImGui::GetStyle();
  // style->Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
  // style->Colors[ImGuiCol_Button] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);  // Change button color


  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);
};

MainWindow::~MainWindow() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();

  glfwDestroyWindow(window);
  glfwTerminate();
}

void MainWindow::RunMainLoop() {
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    // show the menu bar
    MenuBar();

    // show thr toolbar
    // std::string buttonArray[] = {"Main", "Inline Mixer", "Concrete Pump",
    //                              "Dosing PumpH", "Dosing PumpL"};
    // size_t arrSize = sizeof(buttonArray) / sizeof(buttonArray[0]);
    // std::vector<std::string> buttonNames(buttonArray, buttonArray + arrSize);

    // TODO : move this to the head file.
    static std::map<std::string, bool> windowStates = {

        {"Main", false},
        {"Inline Mixer", false},
        {"Concrete Pump", false},
        {"Dosing PumpH", false},
        {"Dosing PumpL", false}

    };

    static std::map<std::string, bool> dataWindowStates = windowStates;

    ToolBar("Control", windowStates);
    ToolBar("Data Visual", dataWindowStates);

    // Render windows
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w, clear_color.w);

    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
  }
}

// MenuBar
void MainWindow::MenuBar() {
  if (ImGui::BeginMainMenuBar()) {
    // File menu
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("New")) {
        printf("New\n");
      }
      if (ImGui::MenuItem("Open", "Ctrl+O")) {
        printf("open\n");
      }
      if (ImGui::MenuItem("Save", "Ctrl+S")) {
        printf("save\n");
      }
      if (ImGui::MenuItem("Close", "Ctrl+W")) {
        printf("close\n");
      }

      ImGui::EndMenu();
    }
    // setting menu
    if (ImGui::BeginMenu("Setting")) {
      if (ImGui::MenuItem("New")) {
        printf("New\n");
      }
      ImGui::EndMenu();
    }
    // simulation menu
    if (ImGui::BeginMenu("Simulation")) {
      if (ImGui::MenuItem("New")) {
        printf("New\n");
      }
      ImGui::EndMenu();
    }
    // about menu
    if (ImGui::BeginMenu("About")) {
      if (ImGui::MenuItem("New")) {
        printf("New\n");
      }
      ImGui::EndMenu();
    }
  }
  ImGui::EndMainMenuBar();
}

// ToolBar
void MainWindow::ToolBar(const std::string &barName,
                         std::map<std::string, bool> &windowStates) {

  // Create the main window
  ImGui::Begin(barName.c_str());
  // Create Button
  for (auto &buttonName : windowStates) {
    if (ImGui::Button(buttonName.first.c_str())) {
      // Set the flag to true when the button is clicked }
      buttonName.second = true;
    }
  }
  ImGui::End();

  // Create the new window if the flag is true
  for (auto &buttonName : windowStates) {
    if (buttonName.second) {
      std::string windowName = barName + " " + buttonName.first;
      ImGui::Begin(windowName.c_str(), &buttonName.second);
      // TODO: add function here
      ImGui::Text("Here is the ");

      if (ImGui::Button("Close")) {
        buttonName.second = false;
      }
      ImGui::End();
    }
  }
}
