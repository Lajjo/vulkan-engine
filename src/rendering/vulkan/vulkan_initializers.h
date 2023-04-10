#pragma once

#include <vulkan/vulkan.h>

namespace vulkan_thing_engine {
class VulkanInitializers {
public:
  static VkCommandPoolCreateInfo
  CommandPoolCreateInfo(uint32_t queueFamilyIndex,
                        VkCommandPoolCreateFlags flag = 0);
  static VkCommandBufferAllocateInfo CommandBufferAllocateInfo(
      VkCommandPool pool, uint32_t count = 1,
      VkCommandBufferLevel level = VK_COMMAND_BUFFER_LEVEL_PRIMARY);
};
} // namespace vulkan_thing_engine