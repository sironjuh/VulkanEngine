#pragma once

#include "device/ve_device.hpp"
#include "pipeline/ve_pipeline.hpp"
#include "swapchain/ve_swap_chain.hpp"
#include "window/ve_window.hpp"
#include "model/ve_model.hpp"

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
    void recreateSwapChain();
    void recordCommandBuffer(int imageIndex);

    VEWindow veWindow{WIDTH, HEIGHT, "Vulkan Engine"};
    VEDevice veDevice{veWindow};
    std::unique_ptr<VESwapChain> veSwapChain;
    std::unique_ptr<VEPipeline> vePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    std::unique_ptr<VEModel> veModel;
  };
}
