//
// Created by Andreea on 23.03.2024.
//

#ifndef EXTRA2_IMAGE_H
#define EXTRA2_IMAGE_H
#include <iostream>
#include "Rectangle.h"
#include "Size.h"
#include "Point.h"


class Image
{
public:
    Image();
    Image(unsigned int w, unsigned int h);
    Image(const Image &other);
    Image& operator=(const Image &other);
    ~Image();
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned char** getData() const;

    void setWidth(unsigned int new_width);
    void setHeight(unsigned int new_height);
    void setData(unsigned char** new_data);

    bool load(std::string imagePath);
    bool save(std::string imagePath) const;
    Image operator+(const Image &i);
    Image operator-(const Image &i);
    Image operator*(double s);
    bool getROI(Image &roiImg, Rectangle roiRect);
    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    bool isEmpty() const;
    Size size() const;
    unsigned char& at(unsigned int x, unsigned int y);
    unsigned char& at(Point pt);
    unsigned char* row(int y);
    void release();
    friend std::ostream& operator<<(std::ostream& os, const Image& dt);
    friend std::istream& operator>>(std::istream& is, Image& dt);
    static Image zeros(unsigned int width, unsigned int height);
    static Image ones(unsigned int width, unsigned int height);
private:
    unsigned char** m_data;
    unsigned int m_width;
    unsigned int m_height;
};

#endif //EXTRA2_IMAGE_H
