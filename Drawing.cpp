//
// Created by Andreea on 01.04.2024.
//
#include "Image.h"
#include "Point.h"
#include "Rectangle.h"
#include <cmath>

void drawRectangle(Image& img, Rectangle r, unsigned char color) {
    unsigned char** new_data = new unsigned char * [r.getHeight()];
    for (int i = 0; i < r.getHeight(); i++)
        new_data[i] = new unsigned char [r.getWidth()];

    for (int i = 0; i < r.getHeight(); i++)
        for (int j = 0; j < r.getWidth(); j++)
            new_data[i][j] = color;

    for (int i = 0; i < r.getHeight(); i++)
        for (int j = 0; j < r.getWidth(); j++)
            img.at(j+r.getY(), i+r.getX()) = new_data[i][j];

}

void drawRectangle(Image& img, Point tl, Point br, unsigned char color) {

    int x = tl.getX();
    int y = tl.getY();
    int height = br.getX() - x;
    int width = br.getY() - y;

    unsigned char** new_data = new unsigned char * [height];
    for (int i = 0; i < height; i++)
        new_data[i] = new unsigned char [width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            new_data[i][j] = color;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            img.at(j+y, i+x) = new_data[i][j];
}

void drawCircle(Image& img, Point center, int radius, unsigned char color) {
    unsigned char ** new_data = new unsigned char * [img.getHeight()];
    for (int i = 0; i < img.getHeight(); i++)
        new_data[i] = new unsigned char [img.getWidth()];

    new_data = img.getData();

    for (int i = 0; i < img.getHeight(); i++)
        for (int j = 0; j < img.getWidth(); j++)
            if ((i - center.getX()) * (i - center.getX()) + (j - center.getY()) * (j - center.getY()) <= radius * radius)
                new_data[i][j] = color;

    img.setData(new_data);
}

void drawLine(Image &img, Point p1, Point p2, unsigned char color) {
    double m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    double b = p1.getY() - m * p1.getX();

    unsigned char ** new_data = new unsigned char * [img.getHeight()];
    for (int i = 0; i < img.getHeight(); i++)
        new_data[i] = new unsigned char [img.getWidth()];

    new_data = img.getData();

    for (int i = 0; i < img.getHeight(); i++)
        for (int j = 0; j < img.getWidth(); j++)
            if (j == m * i + b && i >= p1.getX() && i <= p2.getX() && j >= p1.getY() && j <= p2.getY())
                new_data[i][j] = color;
}