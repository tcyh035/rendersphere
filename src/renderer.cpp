#include "renderer.h"

#include "scene.hpp"
#include "utils.hpp"

#include <Eigen/Core>

#include <iostream>

#define PI 3.14159265358979323846

void Renderer::render(const Scene& scene) {
    std::vector<Eigen::Vector3f> framebuffer(scene.width * scene.height);
    float scale = std::tan(scene.fov * 0.5f * PI/180.0f);
    float imageAspectRatio = (float)scene.width / (float)scene.height;

    for (int j = 0; j < scene.height; ++j) {
        for (int i = 0; i < scene.width; ++i) {
            framebuffer[i + j * scene.width] = scene.backgroundColor;
        }
    }


    Utils::WriteImage(framebuffer, scene.width, scene.height, "output.ppm");
}
