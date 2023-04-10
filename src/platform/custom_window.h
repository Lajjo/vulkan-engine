#pragma once
#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <vulkan_thing_engine/platform/window.h>

namespace vulkan_thing_engine {

class CustomWindow : public Window {
public:
  CustomWindow();
  
  virtual void OpenWindow(WindowData) override;
  virtual bool Update() override;

  virtual std::pair<int, int> GetWindowExtents() override;
  virtual void
  RequestDrawSurface(std::unordered_map<SurfaceArgs, std::any> args) override;

private:
  GLFWwindow *_window;
};
} // namespace vulkan_thing_engine