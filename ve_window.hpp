#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace ve
{
  class VEWindow
  {
  public:
    VEWindow(int w, int h, std::string name);
    ~VEWindow();

    VEWindow(const VEWindow&) = delete;
    VEWindow& operator=(const VEWindow&) = delete;

    bool shouldClose() { return glfwWindowShouldClose(window); }

  private:
    void initWindow();

    const int width;
    const int height;

    std::string windowName;
    GLFWwindow *window;
  };
}
