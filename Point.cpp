//
// Created by Andreea on 22.03.2024.
//

#include "Point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int given_x, int given_y) {
    this->x = given_x;
    this->y = given_y;
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int new_x) {
    this->x = new_x;
}

void Point::setY(int new_y) {
    this->y = new_y;
}

