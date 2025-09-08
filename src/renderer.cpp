#include "renderer.h"

#include "scene.hpp"
#include "utils.hpp"

#include <Eigen/Core>

#include <iostream>

void Renderer::render(const Scene& scene) {
    std::vector<Eigen::Vector3f> framebuffer(scene.width * scene.height);
    for (int j = 0; j < scene.height; ++j) {
        for (int i = 0; i < scene.width; ++i) {
            framebuffer[i + j * scene.width] = Eigen::Vector3f(0.1, 0.2, 0.3); // test background color
        }
    }

    Utils::WriteImage(framebuffer, scene.width, scene.height, "output.ppm");
    std::cout << "Test" << std::endl;
}
