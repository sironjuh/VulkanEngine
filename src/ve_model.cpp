#include "ve_model.hpp"

#include <cassert>
#include <cstring>

namespace ve
{
  VEModel::VEModel(VEDevice &device, const std::vector<Vertex> &vertices)
    : veDevice(device)
  {
    createVertexBuffer(vertices);
  }

  VEModel::~VEModel()
  {
    vkDestroyBuffer(veDevice.device(), vertexBuffer, nullptr);
    vkFreeMemory(veDevice.device(), vertexBufferMemory, nullptr);
  }

  void VEModel::bind(VkCommandBuffer commandBuffer)
  {
    VkBuffer vertexBuffers[] = {vertexBuffer};
    VkDeviceSize offsets[] = {0};
    vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);
  }

  void VEModel::draw(VkCommandBuffer commandBuffer)
  {
    vkCmdDraw(commandBuffer, vertexCount, 1, 0, 0);
  }

  void VEModel::createVertexBuffer(const std::vector<Vertex> &vertices)
  {
    vertexCount = static_cast<uint32_t>(vertices.size());
    assert(vertexCount >= 3 && "Model must have at least 3 vertices");
    VkDeviceSize bufferSize = sizeof(vertices[0]) * vertexCount;

    veDevice.createBuffer(
      bufferSize,
      VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
      VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
      vertexBuffer,
      vertexBufferMemory);

    void *data;
    vkMapMemory(veDevice.device(), vertexBufferMemory, 0, bufferSize, 0, &data);
    memcpy(data, vertices.data(), static_cast<size_t>(bufferSize));
    vkUnmapMemory(veDevice.device(), vertexBufferMemory);
  }

  std::vector<VkVertexInputBindingDescription> VEModel::Vertex::getBindingDescriptions()
  {
    std::vector<VkVertexInputBindingDescription> bindingDescriptions(1);
    bindingDescriptions[0].binding = 0;
    bindingDescriptions[0].stride = sizeof(Vertex);
    bindingDescriptions[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
    return bindingDescriptions;
  }
  
  std::vector<VkVertexInputAttributeDescription> VEModel::Vertex::getAttributeDescriptions()
  {
    std::vector<VkVertexInputAttributeDescription> attributeDescriptions(2);
    attributeDescriptions[0].binding = 0;
    attributeDescriptions[0].location = 0;
    attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
    attributeDescriptions[0].offset = offsetof(Vertex, position);

    attributeDescriptions[1].binding = 0;
    attributeDescriptions[1].location = 1;
    attributeDescriptions[1].format = VK_FORMAT_R32G32B32A32_SFLOAT;
    attributeDescriptions[1].offset = offsetof(Vertex, color);
    return attributeDescriptions;
  }
}
