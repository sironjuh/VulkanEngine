#include "vulkan_engine.hpp"

namespace ve
{
  void VulkanEngine::run()
  {
    while (!veWindow.shouldClose()) {
      glfwPollEvents();
    }
  }
}