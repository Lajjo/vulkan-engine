#include "vulkan_thing_engine/platform/game.h"
#include "custom_window.h"
#include "src/rendering/vulkan/vulkan_renderer.h"
#include <iostream>
#include <vulkan_thing_engine/service_locator.h>

namespace vulkan_thing_engine {

Game::Game() : Game("Vulkan Engine!") {}

Game::Game(std::string windowTitle)
    : _title(std::move(windowTitle)), _running(true) {
  initializeServices();
}

Game::~Game() { shutdownServices(); }

void Game::Run() {

  while (_running) {
    if (ServiceLocator::GetWindow()->Update()) {
      _running = false;
      continue;
    }

    float deltaTime = 0.f;
    Update(deltaTime);

    ServiceLocator::GetRenderer()->RenderFrame();
  }
}

void Game::initializeServices() {
  ServiceLocator::Provide(new CustomWindow);

  ServiceLocator::GetWindow()->OpenWindow({
      .title = _title,
      .width = 800,
      .height = 600,
  });

  RendererSettings settings{
      .ApplicationName = _title,
  };

  ServiceLocator::Provide(new VulkanRenderer(), settings);
}

void Game::shutdownServices() { ServiceLocator::ShutdownServices(); }

} // namespace vulkan_thing_engine