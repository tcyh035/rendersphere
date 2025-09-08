#ifndef _UTILS_H_
#define _UTILS_H_

#include <Eigen/Core>

#include <vector>
#include <string>

class Utils {
public:
    static void WriteImage(std::vector<Eigen::Vector3f> framebuffer,
        int width, int height, const std::string& filename) {
        // Header Format
        // P3
        // <width> <height>
        // <max_color_value>
        // <pixel data>
        FILE* fp = fopen(filename.c_str(), "w");
        fwrite("P3\n", 1, 3, fp);
        fprintf(fp, "%d %d\n", width, height);
        fwrite("255\n", 1, 4, fp);
        for (auto i = 0; i < width * height; ++i) {
            int r = (int)(255 * std::max(0.f, std::min(1.0f, framebuffer[i].x())));
            int g = (int)(255 * std::max(0.f, std::min(1.0f, framebuffer[i].y())));
            int b = (int)(255 * std::max(0.f, std::min(1.0f, framebuffer[i].z())));
            fprintf(fp, "%d %d %d ", r, g, b);
        }
        fclose(fp);
    }
};

#endif