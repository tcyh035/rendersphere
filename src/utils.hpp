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
        FILE* fp = fopen(filename.c_str(), "wb");
        fwrite("P3\n", 1, 3, fp);
        fprintf(fp, "%d %d\n", width, height);
        fwrite("255\n", 1, 4, fp);
        for (auto i = 0; i < width * height; ++i) {
            static unsigned char color[3];
            color[0] = (unsigned char)(255 * std::max(0.f, std::min(1.0f, framebuffer[i].x())));
            color[1] = (unsigned char)(255 * std::max(0.f, std::min(1.0f, framebuffer[i].y())));
            color[2] = (unsigned char)(255 * std::max(0.f, std::min(1.0f, framebuffer[i].z())));
            fwrite(color, 1, 3, fp);
        }
        fclose(fp);
    }
};

#endif