#include "custom_window.h"

#include <iostream>
#include <stdexcept>

namespace vulkan_thing_engine {

CustomWindow::CustomWindow() { _window = nullptr; }

void CustomWindow::OpenWindow(WindowData data) {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  _window = glfwCreateWindow(static_cast<int>(data.width),
                             static_cast<int>(data.height), data.title.c_str(),
                             nullptr, nullptr);
}

bool CustomWindow::Update() {
  glfwPollEvents();

  return glfwWindowShouldClose(_window);
}

std::pair<int, int> CustomWindow::GetWindowExtents() {
  int width, height;
  glfwGetFramebufferSize(_window, &width, &height);

  return {width, height};
}

void CustomWindow::RequestDrawSurface(
    std::unordered_map<SurfaceArgs, std::any> args) {
  try {
    auto vkInstance = std::any_cast<VkInstance>(args[SurfaceArgs::INSTANCE]);
    auto allocationCallbacks = args[SurfaceArgs::ALLOCATORS].has_value()
                                   ? std::any_cast<VkAllocationCallbacks *>(
                                         args[SurfaceArgs::ALLOCATORS])
                                   : nullptr;
    auto outSurface =
        std::any_cast<VkSurfaceKHR *>(args[SurfaceArgs::OUT_SURFACE]);

    if (vkInstance == VK_NULL_HANDLE) {
      throw std::runtime_error("Must provide an instance!");
    }

    if (glfwCreateWindowSurface(vkInstance, _window, allocationCallbacks,
                                outSurface) != VK_SUCCESS) {
      throw std::runtime_error("Failed to create window surface!");
    }
  } catch (const std::bad_any_cast &e) {
    std::cout << "Failed to cast window surface arguments: " << e.what()
              << std::endl;
  }
}

} // namespace vulkan_thing_engine