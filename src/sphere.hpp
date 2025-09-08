#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <Eigen/Core>

class Sphere {
public:
    Eigen::Vector3f center;
    float radius;
    
    // material properties
    Eigen::Vector3f color;
    float Kd, Ks, Ka;

    float specularExponent;

    static bool solveQuadratic(const float& a, const float& b,
         const float& c, float& x0, float& x1)
    {
        float discr = b * b - 4 * a * c;
        if (discr < 0) {
            return false;
        }
        else if (discr == 0) {
            x0 = x1 = -0.5 * b / a;
        } else {
            float q = (b > 0) ? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
            x0 = q / a;
            x1 = c / q;
        }
        if (x0 > x1) {
            std::swap(x0, x1);
        }

        return true;
    }

    bool intersect(const Eigen::Vector3f& orig, const Eigen::Vector3f& dir, float& tnear) const
    {
        Eigen::Vector3f L = orig - center;
        float a = dir.dot(dir);
        float b = 2 * dir.dot(L);
        float c = L.dot(L) - radius * radius;
        float t0, t1;
        if (!solveQuadratic(a, b, c, t0, t1)) {
            return false;
        }
        if (t0 < 0) {
            t0 = t1;
        }
        if (t0 < 0) {
            return false;
        }

        tnear = t0;
        return true;
    }

    Eigen::Vector3f getNormal(const Eigen::Vector3f& hitPoint) const {
        return (hitPoint - center).normalized();
    }
};

#endif