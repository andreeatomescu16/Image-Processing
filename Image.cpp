//
// Created by Andreea on 23.03.2024.
//

#include "Image.h"
#include <fstream>
#include <iostream>
#include "Size.h"
#include <exception>
#include <cmath>


Image::Image() {
    this->m_data = nullptr;
    this->m_width = 0;
    this->m_height = 0;
}

Image::Image(unsigned int w, unsigned int h) {
    m_width = w;
    m_height = h;
    m_data = new unsigned char *[m_height];
    for (unsigned int i = 0; i < m_height; ++i) {
        m_data[i] = new unsigned char [m_width];
        for (unsigned int j = 0; j < m_width; ++j) {
            m_data[i][j] = 0;
        }
    }
}


Image::~Image() {
    for (int i = 0; i < this->m_height; i++) {
        delete[] this->m_data[i];
    }
    delete[] this->m_data;
}

unsigned int Image::getWidth() const {
    return this->m_width;
}

unsigned int Image::getHeight() const {
    return this->m_height;
}

unsigned char** Image::getData() const {
    return this->m_data;
}

void Image::setWidth(unsigned int new_width) {
    this->m_width = new_width;
}

void Image::setHeight(unsigned int new_height) {
    this->m_height = new_height;
}

void Image::setData(unsigned char** new_data) {
    this->m_data = new_data;
}

Image::Image(const Image& other) {
    this->m_width = other.m_width;
    this->m_height = other.m_height;
    this->m_data = new unsigned char*[this->m_height];
    for (int i = 0; i < this->m_height; i++) {
        this->m_data[i] = new unsigned char[this->m_width];
        for (int j = 0; j < this->m_width; j++) {
            this->m_data[i][j] = other.m_data[i][j];
        }
    }
}

Image& Image::operator=(const Image& other) {
    if (this != &other) {
        for (int i = 0; i < this->m_height; i++) {
            delete[] this->m_data[i];
        }
        delete[] this->m_data;
        this->m_width = other.m_width;
        this->m_height = other.m_height;
        this->m_data = new unsigned char*[this->m_height];
        for (int i = 0; i < this->m_height; i++) {
            this->m_data[i] = new unsigned char[this->m_width];
            for (int j = 0; j < this->m_width; j++) {
                this->m_data[i][j] = other.m_data[i][j];
            }
        }
    }
    return *this;
}

std::istream& operator >> (std::istream& is, Image& dt) {
    char magicnr[3], comment[1001];
    unsigned int width, height, maxnr_pixels;
    is >> magicnr;
    is >> width;
    is >> height;
    is >> maxnr_pixels;

    unsigned char** data = new unsigned char*[height];
    for (unsigned int i = 0; i < height; ++i) {
        data[i] = new unsigned char[width];
    }

    for (unsigned int i = 0; i < height; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            int pixelValue;
            is >> pixelValue;
            data[i][j] = pixelValue;
        }
    }

    dt.setWidth(width);
    dt.setHeight(height);
    dt.setData(data);

    return is;
}

bool Image::load(std::string imagePath) {
    std::ifstream file(imagePath);
    if (!file) {
        std::cerr << "Error opening file: " << imagePath << std::endl;
        return false;
    }
    char magicnr[3], comment[1001];
    int width, height, maxpixval;
    file >> magicnr;
    file>>width;
    file >> height;
    file >> maxpixval;

    unsigned char** data = new unsigned char*[height];
    for (unsigned int i = 0; i < height; ++i) {
        data[i] = new unsigned char[width];
    }

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++) {
            int pixvalues;
            file >> pixvalues;
            data[i][j] = pixvalues;
        }

    this->setWidth(width);
    this->setHeight(height);
    this->setData(data);
    return true;
}

bool Image::save(std::string imagePath) const {
    std::ofstream file(imagePath);
    if (!file) {
        throw std::exception();
        return false;
    }
    file << "P2"<<'\n';
    file << this->getWidth()<<'\n';
    file << this->getHeight()<<'\n';
    file << "255\n";

    unsigned char ** data = this->getData();

    for (int i = 0; i < this->getWidth(); i++){
        for (int j = 0; j < this->getHeight(); j++)
            file << static_cast<int>(data[i][j]) << ' ';
            file << '\n';
        }

    return true;
}

Image Image::operator + (const Image &i) {
    if (i.getWidth() != this->getWidth() || i.getHeight() != this->getHeight())
        throw std::exception();

    unsigned char ** new_data = new unsigned char *[this->getHeight()];
    for (int i = 0; i < this->getHeight(); i++)
        new_data[i] = new unsigned char [this->getWidth()];

    for (int k = 0; k < this->getWidth(); k++)
        for (int j = 0; j < this->getHeight(); j++)
            new_data[k][j] = this->getData()[k][j] + i.getData()[k][j];

    this->setData(new_data);
}

Image Image::operator-(const Image &i) {
    if (i.getWidth() != this->getWidth() || i.getHeight() != this->getHeight())
        throw std::exception();

    unsigned char ** new_data;
    new_data = new unsigned char*[this->getHeight()];
    for (int i = 0; i < this->getHeight(); i++)
        new_data[i] = new unsigned char [this->getWidth()];

    for (int k = 0; k < this->getWidth(); k++)
        for (int j = 0; j < this->getHeight(); j++)
            new_data[k][j] = abs(this->getData()[k][j] - i.getData()[k][j]);

    this->setData(new_data);
}

Image Image::operator*(double s) {
    unsigned char ** new_data;

    new_data = new unsigned char * [this->getHeight()];
    for (int i = 0; i < this->getHeight(); i++)
        new_data[i] = new unsigned char [this->getWidth()];

    for (int k = 0; k < this->getWidth(); k++)
        for (int j = 0; j < this->getHeight(); j++)
            new_data[k][j] = this->getData()[k][j] * s;

    this->setData(new_data);
}

Image Image::zeros(unsigned int width, unsigned int height) {
    return Image(width, height);
}

Image Image::ones(unsigned int width, unsigned int height) {
    Image img;
    unsigned char ** new_data;

    new_data = new unsigned char * [height];
    for (int i = 0; i < height; i++)
        new_data[i] = new unsigned char [width];

    for (int k = 0; k < width; k++)
        for (int j = 0; j < height; j++)
            new_data[k][j] = 1;

    img.setData(new_data);
    img.setWidth(width);
    img.setHeight(height);

    return img;
}

unsigned char& Image::at (unsigned int x, unsigned int y) {
    if (y >= m_height || x >= m_width) {
        // Handle out-of-bounds access (you may choose to throw an exception or handle it differently)
        throw std::out_of_range("Pixel coordinates out of bounds");
    }

    return m_data[y][x];}

unsigned char& Image::at(Point pt) {
    return this->getData()[pt.getY()][pt.getX()];
}

unsigned char* Image::row(int y) {
    if (y < 0 || y >= this->getHeight())
        throw std::exception();

    return &this->getData()[y][0];
}

bool Image::isEmpty() const {
    return (this->getHeight() == 0 && this->getWidth() == 0 && this->getData() == nullptr);
}

Size Image::size() const {
    return Size(this->getWidth(), this->getHeight());
}

bool Image::getROI(Image &roiImg, Rectangle roiRect) {

    int lu = roiRect.getX();
    int ru = roiRect.getY();
    int ld = lu + roiRect.getHeight();
    int rd = ld + roiRect.getWidth();

    if (lu < 0 || ru < 0 || ld > getHeight() || rd > getWidth()) {
        return false;
    }

    unsigned char ** new_data = new unsigned char * [roiRect.getHeight()];
    for (int i = 0; i < getHeight(); i++)
        new_data[i] = new unsigned char [roiRect.getWidth()];

    int x = 0;
    int y = 0;
    for (int i = 0; i < this->getHeight(); i++){
        for (int j = 0; j < this->getWidth(); j++)
            if (i >= lu && i < ld && j >= ru && j < ld)
                new_data[x][y++] = this->getData()[i][j];
        x++;
        y = 0;
    }

    roiImg.setWidth(roiRect.getWidth());
    roiImg.setHeight(roiRect.getHeight());
    roiImg.setData(new_data);

    return true;
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    int lu = x;
    int ru = y;
    int ld = lu + height;
    int rd = ld + width;

    if (lu < 0 || ru < 0 || ld > getHeight() || rd > getWidth()) {
        return false;
    }

    unsigned char ** new_data = new unsigned char * [height];
    for (int i = 0; i < getHeight(); i++)
        new_data[i] = new unsigned char [width];

    int x2 = 0;
    int y2 = 0;
    for (int i = 0; i < this->getHeight(); i++){
        for (int j = 0; j < this->getWidth(); j++)
            if (i >= lu && i < ld && j >= ru && j < ld)
                new_data[x2][y2++] = this->getData()[i][j];
        x2++;
        y2 = 0;
    }

    roiImg.setWidth(width);
    roiImg.setHeight(height);
    roiImg.setData(new_data);

    return true;
}

void Image::release() {
    for (int i = 0; i < this->getHeight(); i++) {
        delete[] this->getData()[i];
    }
    delete[] this->getData();
}

std::ostream& operator << (std::ostream& os, const Image& dt) {
    os << "P2\n";
    os << dt.getWidth() << '\n';
    os << dt.getHeight() << '\n';
    os << "255\n";

    unsigned char ** data = dt.getData();

    for (int i = 0; i < dt.getWidth(); i++){
        for (int j = 0; j < dt.getHeight(); j++)
            os << static_cast<int>(data[i][j]) << ' ';
        os << '\n';
    }

    return os;
}

