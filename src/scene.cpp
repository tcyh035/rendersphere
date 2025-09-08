#include "scene.h"

#include <cfloat>

Eigen::Vector3f Scene::castRay(const Eigen::Vector3f &orig, const Eigen::Vector3f &dir, int depth) const
{
    // only calulate depth up to 3
    if (depth > 3) {
        return Eigen::Vector3f();
    }

    Eigen::Vector3f hitColor = this->backgroundColor;
    // find nearest intersection
    // use FLT_MAX/2 to avoid overflow
    float nearest_t = FLT_MAX / 2;
    const Sphere* hitSphere = nullptr;
    for (const auto& sphere : spheres) {
        float t = FLT_MAX / 2;
        if (sphere->intersect(orig, dir, t)) {
            if (t < nearest_t) {
                nearest_t = t;
                hitSphere = sphere.get();
            }
        }
    }

    Eigen::Vector3f ambientLight(0.1f, 0.1f, 0.1f);
    // if hit sphere, calculate color
    // use sphere color to test
    if (hitSphere) {
        auto hitPoint = orig + dir * nearest_t;
        auto N = hitSphere->getNormal(hitPoint);
        auto V = -dir.normalized();

        Eigen::Vector3f color = {0.0f, 0.0f, 0.0f};
        for (const auto& light: lights) {
            // Blinn-Phong model
            auto L = (light->position - hitPoint).normalized();
            auto H = (L + V).normalized(); // w分量 is 2, so (L+V) is half vector

            float diff = std::max(0.0f, N.dot(L));
            float spec = std::pow(std::max(0.0f, N.dot(H)), hitSphere->specularExponent);
            
            auto ambient = hitSphere->Ka * hitSphere->color.cwiseProduct(ambientLight);
            auto diffuse = hitSphere->Kd * diff * hitSphere->color.cwiseProduct(light->intensity);
            auto specular = hitSphere->Ks * spec * light->intensity;
            color += ambient + diffuse + specular;
        }

        for (int i = 0; i < 3; ++i)
        {
            hitColor[i] = std::max(0.0f, std::min(1.0f, color[i]));
        }

    }
    
    return hitColor;
}