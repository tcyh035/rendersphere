#include "renderer.h"

#include "scene.hpp"
#include "utils.hpp"

#include <Eigen/Core>

#include <iostream>

void Renderer::render(const Scene& scene) {
    std::vector<Eigen::Vector3f> framebuffer(scene.width * scene.height);
    
    

    Utils::WriteImage(framebuffer, scene.width, scene.height, "output.ppm");
    std::cout << "Test" << std::endl;
}
