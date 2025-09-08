#include "scene.h"

Eigen::Vector3f Scene::castRay(const Eigen::Vector3f &orig, const Eigen::Vector3f &dir, int depth) const
{
    // only calulate depth up to 3
    if (depth > 3) {
        return Eigen::Vector3f();
    }

    Eigen::Vector3f hitColor = this->backgroundColor;
    // test if ray intersects with all spheres and return hit sphere
    float nearest_t = std::numeric_limits<float>::max();
    const Sphere* hitSphere = nullptr;
    for (const auto& sphere : spheres) {
        float t = std::numeric_limits<float>::max();
        if (sphere->intersect(orig, dir, t)) {
            if (t < nearest_t) {
                nearest_t = t;
                hitSphere = sphere.get();
            }
        }
    }

    // if hit sphere, calculate color
    // use sphere color to test
    if (hitSphere) {
        hitColor = hitSphere->color;
    }
    
    return hitColor;
}