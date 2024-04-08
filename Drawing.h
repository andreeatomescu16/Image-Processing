//
// Created by Andreea on 01.04.2024.
//

#ifndef EXTRA2_DRAWING_H
#define EXTRA2_DRAWING_H

#include "Image.h"
#include "Point.h"
#include "Rectangle.h"

void drawCircle(Image& img, Point center, int radius, unsigned char color);
void drawLine(Image &img, Point p1, Point p2, unsigned char color);
void drawRectangle(Image &img, Rectangle r, unsigned char color);
void drawRectangle(Image &img, Point tl, Point br, unsigned char color);

#endif //EXTRA2_DRAWING_H
