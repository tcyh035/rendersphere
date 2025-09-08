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
    float fov;
    Eigen::Vector3f backgroundColor;

    Scene(int w, int h) : width(w), height(h) {
        fov = 90.0f;
        backgroundColor = Eigen::Vector3f(0.2, 0.7, 0.8); // according to exam requirement
    }

    void Add(std::unique_ptr<Sphere> sphere) {
        spheres.push_back(std::move(sphere));
    }

    void Add(std::unique_ptr<Light> light) {
        lights.push_back(std::move(light));
    }

    std::vector<std::unique_ptr<Sphere>> spheres;
    std::vector<std::unique_ptr<Light>> lights;
    
    Eigen::Vector3f castRay(const Eigen::Vector3f &orig, const Eigen::Vector3f &dir, int depth) const;
};

#endif