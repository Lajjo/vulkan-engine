#include <vulkan_thing_engine/engine.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vulkan_thing_engine/service_locator.h>
#include <vulkan_thing_engine/platform/glfw_window.h>

void VulkanThingEngine::Init(){
    std::cout << "Hello, I'm printing from the engine library!" << std::endl;

    ServiceLocator::Provide(new GlfwWindow);
}