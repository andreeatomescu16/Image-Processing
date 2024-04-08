//
// Created by Andreea on 22.03.2024.
//

#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {
    this->x = 0;
    this->x = 0;
    this->width = 0;
    this->height = 0;
}

Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height) {
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
}

int Rectangle::getX() const {
    return this->x;
}

int Rectangle::getY() const {
    return this->y;
}

unsigned int Rectangle::getWidth() const {
    return this->width;
}

unsigned int Rectangle::getHeight() const {
    return this->height;
}

void Rectangle::setX(int new_x) {
    this->x = new_x;
}

void Rectangle::setY(int new_y) {
    this->y = new_y;
}

void Rectangle::setWidth(unsigned int new_width) {
    this->width = new_width;
}

void Rectangle::setHeight(unsigned int new_height) {
    this->height = new_height;
}

Rectangle operator +(const Rectangle& lhs, const Point& rhs) {
    return Rectangle(lhs.getX()+rhs.getX(), lhs.getY()+rhs.getY(), lhs.getWidth(), lhs.getHeight());
}

Rectangle operator -(const Rectangle& lhs, const Point& rhs) {
    return Rectangle(lhs.getX()-rhs.getX(), lhs.getY()-rhs.getY(), lhs.getWidth(), lhs.getHeight());
}

Rectangle operator & (const Rectangle& lhs, const Rectangle& rhs) {
    int x = std::max(lhs.getX(), rhs.getX());
    int y = std::max(lhs.getY(), rhs.getY());
    unsigned int width = std::min(lhs.getX()+lhs.getWidth(), rhs.getX()+rhs.getWidth()) - x;
    unsigned int height = std::min(lhs.getY()+lhs.getHeight(), rhs.getY()+rhs.getHeight()) - y;
    return Rectangle(x, y, width, height);
}

Rectangle operator | (const Rectangle& lhs, const Rectangle& rhs) {
    int x = std::min(lhs.getX(), rhs.getX());
    int y = std::min(lhs.getY(), rhs.getY());
    unsigned int width = std::max(lhs.getX()+lhs.getWidth(), rhs.getX()+rhs.getWidth()) - x;
    unsigned int height = std::max(lhs.getY()+lhs.getWidth(), rhs.getX()+rhs.getWidth()) - y;
    return Rectangle(x, y, width, height);
}