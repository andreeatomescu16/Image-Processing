//
// Created by Andreea on 22.03.2024.
//

#include "Size.h"

Size::Size(unsigned int g_width, unsigned int g_height) {
    this->width = g_width;
    this->height = g_height;
}

unsigned int Size::getHeight() const {
    return this->height;
}

unsigned int Size::getWidth() const {
    return this->width;
}

void Size::setHeight(unsigned int new_height) {
    this->height = new_height;
}

void Size::setWidth(unsigned int new_width) {
    this->width = new_width;
}

bool operator == (const Size& lsh, const Size& rsh) {
    return lsh.getWidth() * lsh.getHeight() == rsh.getWidth() * rsh.getHeight();
}

bool operator < (const Size& lsh, const Size& rsh) {
    return lsh.getWidth() * lsh.getHeight() < rsh.getWidth() * rsh.getHeight();
}

bool operator > (const Size& lsh, const Size& rsh) {
    return lsh.getWidth() * lsh.getHeight() > rsh.getWidth() * rsh.getHeight();
}

bool operator >= (const Size& lsh, const Size& rsh) {
    return lsh.getWidth() * lsh.getHeight() >= rsh.getWidth() * rsh.getHeight();
}

bool operator <= (const Size& lsh, const Size& rsh) {
    return lsh.getWidth() * lsh.getHeight() <= rsh.getWidth() * rsh.getHeight();
}