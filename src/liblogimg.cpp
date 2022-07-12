#include "liblogimg.hpp"
#include "lodepng.h"
#include <iostream>

Image::Image(const char *path) {
    std::vector<unsigned char> image;
    unsigned width, height;
    unsigned error = lodepng::decode(image, width, height, path);
    std::cout << error << std::endl;

    this->image = image;
    this->width = width;
    this->height = height;
}