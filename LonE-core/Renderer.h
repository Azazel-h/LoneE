#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace lone::renderer {
        class Window {
        private:
            int width, height;
            const char *name;
            VkInstance instance;
            GLFWwindow *window;
        public:
            Window(int width, int height, const char *name);
            void initVulcan();
            void cleanUp();
        protected:
            void createInstance();
        };
    }

