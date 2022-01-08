#pragma once

#include "ve_window.hpp"
#include "ve_pipeline.hpp"

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
      VEPipeline vePipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
  };
}