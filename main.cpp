#include <iostream>
#include "Image.h"
#include "Rectangle.h"
#include "ImageProcessing.h"
#include <exception>
#include "Drawing.h"

unsigned char scaleToRange(double value) {
    if (value < 0.0)
        value = 0.0;
    if (value > 255.0)
        value = 255.0;
    return static_cast<unsigned char>(value);
}

int main() {
    Image img;
    std::string imagePath = "/Users/Asus/Documents/oop/extra2/cmake-build-debug/baboon.ascii.pgm";
    bool loaded = img.load(imagePath);
    if (!loaded) {
        throw std::exception();
    }

    Image processedImage(img.getWidth(), img.getHeight());
    ImageProcessing* imgProc = new GammaCorrection(1);
    ImageProcessing* imgProc2 = new BrightAndContrast(1,1);

    int ** kernel;
    kernel = new int * [3];
    for (int i = 0; i < img.getHeight(); i++)
        kernel[i] = new int [3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            std::cin>>kernel[i][j];

    ImageProcessing* imgProc3 = new ImageConvulsion(kernel, scaleToRange);
    imgProc->process(img, processedImage);
    imgProc2->process(processedImage, processedImage);
    imgProc3->process(processedImage, processedImage);

    drawRectangle(processedImage, Point(300,100), Point(400,500),1);

    for (int i = 0; i < 3; i++)
        delete kernel[i];

    delete kernel[3];

    std::string processedImagePath = "/Users/Asus/Documents/oop/extra2/cmake-build-debug/photo.pgm";
    bool saved = processedImage.save(processedImagePath);
    if (saved) {
        std::cout << "Processed image saved successfully!" << std::endl;
    } else {
        throw std::exception();
    }


    return 0;
}