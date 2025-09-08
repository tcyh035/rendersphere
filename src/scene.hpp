#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include <memory>

#include "sphere.hpp"
#include "light.hpp"

class Scene {
public:
    int width;
    int height;
    Scene(int w, int h) : width(w), height(h) {}

    void Add(std::unique_ptr<Sphere> sphere) {
        spheres.push_back(std::move(sphere));
    }

    void Add(std::unique_ptr<Light> light) {
        lights.push_back(std::move(light));
    }

    std::vector<std::unique_ptr<Sphere>> spheres;
    std::vector<std::unique_ptr<Light>> lights;
};

#endif