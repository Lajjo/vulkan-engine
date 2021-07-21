#include <vulkan_thing_engine/platform/glfw_window.h>

    GlfwWindow::GlfwWindow() {
        _window = nullptr;
    }

    void GlfwWindow::OpenWindow() {
        glfwInit();

        _window = glfwCreateWindow(800, 600, "test", nullptr, nullptr);
        
    }

    bool GlfwWindow::Update() {
        glfwPollEvents();

        return glfwWindowShouldClose(_window);
        }