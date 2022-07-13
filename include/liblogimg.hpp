#pragma once

#include "Logic.hpp"
#include <vector>
#include <string>

class Image {
private:
    std::vector<Rgb> colors;
public:
    unsigned width, height;
    std::string path;
    
    Image(const char *path);

    unsigned load();
    Rgb at(uint8_t x, uint8_t y);
};

void drawImage(unsigned int x, unsigned int y, Image &image);