#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <Eigen/Core>

class Light {
public:
    Eigen::Vector3f position;
    Eigen::Vector3f intensity;
    Light() {};
    Light(const Eigen::Vector3f& p, const Eigen::Vector3f& i) : position(p), intensity(i) {}
};
#endif