#pragma once

#include <string>

namespace vulkan_thing_engine {
struct RendererSettings {
  std::string ApplicationName;
};

class Renderer {
public:
  virtual void Init(RendererSettings) = 0;
  virtual void Shutdown() = 0;
  virtual void RenderFrame() = 0;
};

} // namespace vulkan_thing_engine