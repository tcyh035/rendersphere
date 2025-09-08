#include <iostream>
#include <cassert>
#include <cmath>

#include "../src/sphere.hpp"
#include "../src/scene.h"
#include "../src/renderer.h"

bool test_sphere_intersection() {
    std::cout << "enter test_sphere_intersection" << std::endl;
    
    Sphere sphere;
    sphere.center = Eigen::Vector3f(0.0f, 0.0f, -5.0f);
    sphere.radius = 1.0f;
    
    // 相交
    Eigen::Vector3f origin(0.0f, 0.0f, 0.0f);
    Eigen::Vector3f dir1(0.0f, 0.0f, -1.0f);
    dir1.normalize();
    
    float t;
    bool hit = sphere.intersect(origin, dir1, t);
    
    if (!hit || std::abs(t - 4.0f) > 0.001f) {
        std::cout << "Test Failed: test_sphere_intersection 1" << std::endl;
        return false;
    }
    
    // 不相交
    Eigen::Vector3f dir2(0.0f, 2.0f, -1.0f);
    dir2.normalize();
    
    hit = sphere.intersect(origin, dir2, t);
    if (hit) {
        std::cout << "Test Failed: test_sphere_intersection 2" << std::endl;
        return false;
    }
    
    std::cout << "test_sphere_intersection Pass" << std::endl;
    return true;
}

bool test_sphere_normal() {
    std::cout << "enter test_sphere_normal" << std::endl;
    
    Sphere sphere;
    sphere.center = Eigen::Vector3f(0.0f, 0.0f, 0.0f);
    sphere.radius = 1.0f;

    Eigen::Vector3f point(1.0f, 0.0f, 0.0f);
    Eigen::Vector3f normal = sphere.getNormal(point);
    
    if (std::abs(normal.x() - 1.0f) > 0.001f || 
        std::abs(normal.y()) > 0.001f || 
        std::abs(normal.z()) > 0.001f) {
        return false;
    }
    
    std::cout << "test_sphere_normal pass" << std::endl;
    return true;
}

bool test_scene_initialization() {
    std::cout << "test_scene" << std::endl;
    
    Scene scene(800, 600);
    
    if (scene.width != 800 || scene.height != 600) {
        std::cout << "Test Failed: scene width/height not correct" << std::endl;
        return false;
    }

    std::cout << "test_scene pass" << std::endl;
    return true;
}

int main() {
    std::cout << "Simple test" << std::endl;
    
    int passed = 0;
    int total = 3;
    
    if (test_sphere_intersection()) {
        passed++;
    }
    if (test_sphere_normal()) {
        passed++;
    }
    if (test_scene_initialization()) {
        passed++;
    }
    
    std::cout << "Test Result " << passed << "/" << total << "Pass" << std::endl;
    
    // fail return -1
    return passed == total ? 0 : -1;
}