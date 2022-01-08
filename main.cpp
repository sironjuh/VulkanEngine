#include "vulkan_engine.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
    ve::VulkanEngine app;

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
