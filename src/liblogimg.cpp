#include "liblogimg.hpp"
#include "lodepng.h"

Image::Image(const char *path) {
    std::vector<unsigned char> image;
    unsigned width, height;
    unsigned error = lodepng::decode(image, width, height, path);

    this->image = image;
    this->width = width;
    this->height = height;
}