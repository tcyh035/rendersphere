#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <Eigen/Core>

class Sphere {
public:
    Eigen::Vector3f center;
    float radius;
    
    // material properties
    Eigen::Vector3f color;
    float Kd, Ks;

    float specularExponent;
};


#endif