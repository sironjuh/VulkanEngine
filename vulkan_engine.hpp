#pragma once

#include "ve_window.hpp"

namespace ve
{
  class VulkanEngine
  {
    public:
      static constexpr int WIDTH = 800;
      static constexpr int HEIGHT = 600;

      void run();

    private:
      VEWindow veWindow{WIDTH, HEIGHT, "Vulkan Engine"};
  };
}