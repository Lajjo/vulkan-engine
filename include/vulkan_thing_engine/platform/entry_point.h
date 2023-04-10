#pragma once

#include <glm/glm.hpp>
#include <iostream>

#include <vulkan_thing_engine/platform/game.h>
#include <vulkan_thing_engine/service_locator.h>

int main(int argc, char **argv) {

  auto *_game = vulkan_thing_engine::CreateGame();

  _game->Run();

  delete _game;
}