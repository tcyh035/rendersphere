#include "renderer.h"

#include "scene.hpp"
#include "utils.hpp"

#include <Eigen/Core>

#include <iostream>

void Renderer::render(const Scene& scene) {
    std::vector<Eigen::Vector3f> framebuffer(scene.width * scene.height);
    auto background_color = Eigen::Vector3f(0.2, 0.7, 0.8); // according to exam requirement
    for (int j = 0; j < scene.height; ++j) {
        for (int i = 0; i < scene.width; ++i) {
            framebuffer[i + j * scene.width] = background_color;
        }
    }

    Utils::WriteImage(framebuffer, scene.width, scene.height, "output.ppm");
}
