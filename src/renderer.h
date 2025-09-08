#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <string>

class Scene;

class Renderer {
public:
    void render(const Scene& scene, const std::string& filename = "output.ppm");
};

#endif