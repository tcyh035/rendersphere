#include "renderer.h"

#include "scene.h"
#include "utils.hpp"

#include <Eigen/Core>

#include <iostream>
#include <optional>

#define PI 3.14159265358979323846

void Renderer::render(const Scene& scene, const std::string& filename) {
    std::vector<Eigen::Vector3f> framebuffer(scene.width * scene.height);
    float scale = std::tan(scene.fov * 0.5f * PI/180.0f);
    float imageAspectRatio = (float)scene.width / (float)scene.height;

    // assume eye pos is (0, 0, 0)
    // assume view dir is (0, 0, -1)
    Eigen::Vector3f eye_pos(0, 0, 0);
    int index = 0;
    for (int j = 0; j < scene.height; ++j) {
        for (int i = 0; i < scene.width; ++i) {
            float x = (2.0f * ((i + 0.5f) / (float)scene.width) - 1.0f) * scale * imageAspectRatio;
            float y = (1.0f - 2.0f * ((j + 0.5) / (float)scene.height)) * scale;

            Eigen::Vector3f dir = Eigen::Vector3f(x, y, -1).normalized();
            framebuffer[index++] = scene.castRay(eye_pos, dir);
        }
    }

    Utils::WriteImage(framebuffer, scene.width, scene.height, filename);
}
