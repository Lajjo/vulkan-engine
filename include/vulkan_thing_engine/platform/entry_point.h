#pragma once

#include <iostream>
#include <glm/glm.hpp>

#include <vulkan_thing_engine/engine.h>
#include <vulkan_thing_engine/service_locator.h>

#include <vulkan_thing_engine/platform/game.h>

int main(int argc, char** argv){

    auto* _game = CreateGame();
    VulkanThingEngine::Init();

    ServiceLocator::GetWindow()->OpenWindow();

    while (!ServiceLocator::GetWindow()->Update())
    {
        /* code */
    }
    
}