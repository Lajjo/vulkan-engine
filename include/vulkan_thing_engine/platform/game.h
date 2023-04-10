#pragma once

#include <string>

namespace vulkan_thing_engine {

class Game {
public:
  Game();
  explicit Game(std::string windowTitle);
  ~Game();

  void Run();

protected:
  virtual void PhysicsUpdate(float deltaTime){};
  virtual void Update(float deltaTime){};

private:
  void initializeServices();
  void shutdownServices();

public:
private:
  std::string _title;
  bool _running;
};

extern Game *CreateGame();
} // namespace vulkan_thing_engine