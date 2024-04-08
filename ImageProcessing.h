//
// Created by Andreea on 28.03.2024.
//

#ifndef EXTRA2_IMAGEPROCESSING_H
#define EXTRA2_IMAGEPROCESSING_H
#include "Image.h"

class ImageProcessing {
public:
    ImageProcessing() = default;
    virtual void process (const Image& src, Image& dst) = 0;
};

class BrightAndContrast : public ImageProcessing {
public:
    BrightAndContrast();
    BrightAndContrast(double alpha, double beta);
    void process (const Image& src, Image& dst) override;
private:
    double alpha;
    double beta;
};

class GammaCorrection : public ImageProcessing {
public:
    GammaCorrection(double gamma);
    void process (const Image& src, Image& dst) override;

private:
    double gamma;
};

class ImageConvulsion : public ImageProcessing {
public:
    ImageConvulsion(int** kernel, std::function<unsigned char(double)> scalingFunction);
    void process (const Image& src, Image& dst) override;

private:
    int** kernel;
    std::function<unsigned char(double)> scalingFunction;
};


#endif //EXTRA2_IMAGEPROCESSING_H
