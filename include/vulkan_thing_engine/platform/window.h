#pragma once

#include <any>
#include <string>
#include <tuple>
#include <unordered_map>

namespace vulkan_thing_engine {
enum class SurfaceArgs { INSTANCE, ALLOCATORS, OUT_SURFACE };
struct WindowData {
  std::string title;
  uint32_t width, height;
};

class Window {
public:
  virtual void OpenWindow(WindowData) = 0;
  virtual bool Update() = 0;

  virtual std::pair<int, int> GetWindowExtents() = 0;
  virtual void
  RequestDrawSurface(std::unordered_map<SurfaceArgs, std::any> args) = 0;
};
} // namespace vulkan_thing_engine