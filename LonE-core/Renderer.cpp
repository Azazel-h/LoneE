//
// Created by Azazel.h on 23.09.2021.
//

#include <iostream>
#include "Renderer.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace lone {
    renderer::Window::Window(int width, int height, const char *name) {
        this->width = width;
        this->height = height;
        this->name = name;
        Init();
    }

    void renderer::Window::Init() const {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        if (glfwInit()) {
            GLFWwindow *window = glfwCreateWindow(this->width, this->height, this->name, nullptr, nullptr);
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
            }
            glfwDestroyWindow(window);
            glfwTerminate();
        }
    }
}
