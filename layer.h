#ifndef LAYER_H
#define LAYER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <cstring>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

enum Transparency { TRANSPARENT, OPAQUE };
class Layer
{
private:
    string name;
    // name of this layer
    int id;
    // the ID of this layer
    int visionType;
    // The type of how this Layer is seen.
    // TRANSPARENT : only the valued pixels will be mapped on the screen
    // OPAQUE: all pixels of this layer will be mapped
    int width, height;
    // Size
    int cornerX, cornerY;
    // Position of this layer on the Canvas
    Mat M;

public:
    Layer();
    Layer(string FILE_PATH, string name, int visionType, int cornerX = 0, int cornerY = 0);
    Layer(string name, int visionType, int width, int height, int cornerX, int cornerY, Mat M);
    void set_name(string name);
    static int layerCount;
    friend class ImageProject;
};

#endif // LAYER_H
