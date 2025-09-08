#include <Eigen/Core>

#include "scene.h"
#include "sphere.hpp"
#include "light.hpp"

#include "renderer.h"

int main(int argc, char** argv) {
    Scene scene(738, 553);
    auto sphere = std::make_unique<Sphere>();
    sphere->center = Eigen::Vector3f(0.0f, 0.0f, -1.8f); // is almost same as exam result
    sphere->radius = 1.0f;
    sphere->color = Eigen::Vector3f(1,0,0);
    sphere->Kd = 0.8f;
    sphere->Ks = 0.3f;
    sphere->specularExponent = 50.0f;

    scene.Add(std::move(sphere));

    auto light = std::make_unique<Light>();
    scene.Add(std::move(light));

    Renderer renderer;
    if (argc == 2) {
        renderer.render(scene, argv[1]);
    } else {
        renderer.render(scene);
    }
}