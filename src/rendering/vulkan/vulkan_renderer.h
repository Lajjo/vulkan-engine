#pragma once

#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan_thing_engine/rendering/renderer.h>
namespace vulkan_thing_engine {

class VulkanRenderer : public Renderer {
public:
  virtual void Init(RendererSettings) override;
  virtual void Shutdown() override;
  virtual void RenderFrame() override;

private:
  void initCore();
  void createSwapchain();
  void createCommands();
  void createDefaultRenderPass();
  void createFramebuffers();
  void createSyncStructures();

private:
  uint64_t _frameNumber{0};

  RendererSettings _rendererSettings{};

  VkInstance _instance;
  VkDebugUtilsMessengerEXT _debugMessenger;
  VkPhysicalDevice _physicalDevice;
  VkDevice _device;
  VkSurfaceKHR _surface;

  VkSwapchainKHR _swapchain;
  VkFormat _swapchainImageFormat;
  std::vector<VkImage> _swapchainImages;
  std::vector<VkImageView> _swapchainImageViews;
  VkExtent2D _windowExtent;

  VkQueue _graphicsQueue;
  uint32_t _graphicsQueueFamily;

  VkCommandPool _commandPool;
  VkCommandBuffer _mainCommandBuffer;

  VkRenderPass _renderPass;
  std::vector<VkFramebuffer> _framebuffers{3};

  VkSemaphore _presentSemaphore, _renderSemaphore;
  VkFence _renderFence;
};

} // namespace vulkan_thing_engine