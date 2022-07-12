#pragma once

#include <vector>

class Image {
private:
    std::vector<unsigned char> image;
public:
    unsigned width, height;
    
    Image(const char *path);
};

void drawImage(unsigned int x, unsigned int y, const Image &image);