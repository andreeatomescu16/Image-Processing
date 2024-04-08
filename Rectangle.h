//
// Created by Andreea on 22.03.2024.
//

#ifndef EXTRA2_Rectangle_H
#define EXTRA2_Rectangle_H
#include "Point.h"


class Rectangle {
public:
    Rectangle();
    Rectangle(int x, int y, unsigned int width, unsigned int height);

    int getX() const;
    int getY() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setX(int new_x);
    void setY(int new_y);
    void setWidth(unsigned int new_width);
    void setHeight(unsigned int new_height);

    friend Rectangle operator + (const Rectangle& lhs, const Point& rhs);
    friend Rectangle operator - (const Rectangle& lhs, const Point& rhs);
    friend Rectangle operator & (const Rectangle& lhs, const Rectangle& rhs);
    friend Rectangle operator | (const Rectangle& lhs, const Rectangle& rhs);

private:
    int x;
    int y;
    unsigned int width;
    unsigned int height;
};


#endif //EXTRA2_Rectangle_H
