cmake_minimum_required(VERSION 3.8)
project(LonE)
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES Sandbox/main.cpp LonE-core/LonE.h)
add_executable(LonE ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)

find_package(glfw3 3.3.4 REQUIRED)
if (GLFW3_FOUND)
    message(STATUS "Found GLFW, Including and Linking now")
    include_directories(${GLFW3_INCLUDE_DIRS})
    target_link_libraries(LonE ${GLFW3_STATIC_LIBRARIES})
endif (GLFW3_FOUND)

find_package(Vulkan REQUIRED)
if (VULKAN_FOUND)
    message(STATUS "Found Vulkan, Including and Linking now")
    include_directories(${VULKAN_INCLUDE_DIR})
    target_link_libraries(LonE glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)
endif (VULKAN_FOUND)

find_package(glm REQUIRED)
if (GLM_FOUND)
    message(STATUS "Found GLM, Including and Linking now")
    include_directories(${GLM_INCLUDE_DIRS})
    target_link_libraries(LonE ${GLM_STATIC_LIBRARIES})
endif (GLM_FOUND)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")


