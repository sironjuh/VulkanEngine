#pragma once

#include "ve_device.hpp"
#include "ve_pipeline.hpp"
#include "ve_swap_chain.hpp"
#include "ve_window.hpp"
#include "ve_model.hpp"

#include <memory>
#include <vector>

namespace ve
{
  class VulkanEngine
  {
  public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    VulkanEngine();
    ~VulkanEngine();

    VulkanEngine(const VulkanEngine &) = delete;
    VulkanEngine &operator=(const VulkanEngine &) = delete;

    void run();

  private:
    void sierpinski(
        std::vector<VEModel::Vertex> &vertices,
        int depth,
        glm::vec2 left,
        glm::vec2 right,
        glm::vec2 top);
    void loadModels();
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();

    VEWindow veWindow{WIDTH, HEIGHT, "Vulkan Engine"};
    VEDevice veDevice{veWindow};
    VESwapChain veSwapChain{veDevice, veWindow.getExtent()};
    std::unique_ptr<VEPipeline> vePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    std::unique_ptr<VEModel> veModel;
  };
}
