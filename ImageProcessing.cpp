//
// Created by Andreea on 28.03.2024.
//
#include "ImageProcessing.h"

BrightAndContrast::BrightAndContrast() {
    this->alpha = 1;
    this->beta = 0;
}

BrightAndContrast::BrightAndContrast(double alpha, double beta) {
    this->alpha = alpha;
    this->beta = beta;
}

void BrightAndContrast::process(const Image &src, Image &dst) {
    for (int i = 0; i < src.getHeight(); i++)
        for (int j = 0; j < src.getWidth(); j++) {
            double newValue = alpha * src.getData()[i][j] + beta;
            newValue = std::max(0.0, std::min(255.0, newValue));
            dst.at(j, i) = static_cast<unsigned char>(newValue);
        }
}

GammaCorrection::GammaCorrection(double gamma) {
    this->gamma = gamma;
}

void GammaCorrection::process(const Image &src, Image &dst) {
    for (int i = 0; i < src.getHeight(); i++)
        for (int j = 0; j < src.getWidth(); j++)
            dst.at(j, i) = pow(src.getData()[i][j], gamma);
}

ImageConvulsion::ImageConvulsion(int** kernel, std::function<unsigned char(double)> scalingFunction) {
    this->kernel = kernel;
    this->scalingFunction = scalingFunction;
}

void ImageConvulsion::process(const Image &src, Image &dst) {
    int kernelWidth = 3;
    int kernelHeight = 3;
    int kernelCenterX = (kernelWidth - 1) / 2;
    int kernelCenterY = (kernelHeight - 1) / 2;

    unsigned char ** new_data = new unsigned char * [src.getHeight()];
    for (int i = 0; i < src.getHeight(); i++)
        new_data[i] = new unsigned char [src.getWidth()];


    for (int i = 0; i < src.getHeight(); i++) {
        for (int j = 0; j < src.getWidth(); j++) {
            double sum = 0;
            for (int u = 0; u < kernelWidth; u++) {
                for (int v = 0; v < kernelHeight; v++) {
                    int srcX = i - u + kernelCenterX;
                    int srcY = j - v + kernelCenterY;

                    if (srcX >= 0 && srcX < src.getHeight() && srcY >= 0 && srcY < src.getWidth()) {
                        sum += kernel[u][v] * src.getData()[srcX][srcY];
                    }
                }
            }
            new_data[i][j] = scalingFunction(sum);
        }
    }

    dst.setData(new_data);
}
