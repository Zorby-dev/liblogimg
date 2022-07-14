#include "liblogimg.hpp"
#include "lodepng.h"
#include <iostream>

Image::Image(const char *path) {
    this->path = path;
}

unsigned Image::load() {
    std::vector<unsigned char> raw_image;
    unsigned width, height;
    unsigned error = lodepng::decode(raw_image, width, height, this->path);

    if (error) return error;

    std::vector<Rgb> colors = {};
    unsigned short pos = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0;
    for (unsigned char byte : raw_image) {
        switch (pos) {
        case 0:
            r = byte;
            break;
        case 1:
            g = byte;
            break;
        case 2:
            b = byte;
            break;
        case 3:
            a = byte;
            break;
        }
        if (pos == 3) {
            colors.push_back(Rgb(r, g, b, a));
            pos = 0;
        } else {
            pos++;
        }
    }
    
    this->colors = colors;
    this->width = width;
    this->height = height;

    return error;
}

Rgb Image::at(uint8_t x, uint8_t y) {
    return this->colors[this->width * y + x];
}

void drawImage(unsigned int x, unsigned int y, Image &image) {
    auto width = image.width;
    auto height = image.height;

    for (int o = x; o < width; o++) {
        for (int i = y; i < height; i++) {
            display.setColor(x + o, y + i, image.at(o, i));
        }
    }
}