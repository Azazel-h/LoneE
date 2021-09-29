//
// Created by Azazel.h on 23.09.2021.
//

#include <iostream>
#include "Renderer.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

namespace lone::renderer {
    Window::Window(int width, int height, const char *name) {
        this->width = width;
        this->height = height;
        this->name = name;
        initVulcan();
        cleanUp();
    }

    void Window::createInstance() {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = this->name;
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;


        vkEnumerateInstanceExtensionProperties(nullptr, &glfwExtensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(glfwExtensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &glfwExtensionCount, extensions.data());

        std::cout << "available extensions:\n";
        for (const auto& extension : extensions) {
            std::cout << '\t' << extension.extensionName << '\n';
        }

        if (vkCreateInstance(&createInfo, nullptr, &this->instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance!");
        }
    };

    void Window::initVulcan() {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        if (glfwInit()) {
            this->window = glfwCreateWindow(this->width, this->height, this->name, nullptr, nullptr);
            createInstance();
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
                VkSurfaceKHR surface;
                VkResult err = glfwCreateWindowSurface(this->instance, window, nullptr, &surface);

            }
        }
    }

    void Window::cleanUp() {
        vkDestroyInstance(this->instance, nullptr);
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
