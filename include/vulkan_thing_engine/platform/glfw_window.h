#pragma once

#include <vulkan_thing_engine/platform/window.h>
#include <GLFW/glfw3.h>

class GlfwWindow : public Window {
    public:
        GlfwWindow();
        virtual void OpenWindow() override;
        virtual bool Update() override;
    private:
        GLFWwindow* _window;
};