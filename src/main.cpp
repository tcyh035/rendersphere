#include <Eigen/Core>

#include "scene.hpp"
#include "sphere.hpp"
#include "light.hpp"

#include "renderer.h"

int main() {
    Scene scene(738, 553);
    auto sphere = std::make_unique<Sphere>();
    scene.Add(std::move(sphere));

    auto light = std::make_unique<Light>();
    scene.Add(std::move(light));

    Renderer renderer;
    renderer.render(scene);
}