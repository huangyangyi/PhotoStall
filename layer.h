#ifndef LAYER_H
#define LAYER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QImage>
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
    Transparency visionType;
    // The type of how this Layer is seen.
    // TRANSPARENT : only the valued pixels will be mapped on the screen
    // OPAQUE: all pixels of this layer will be mapped
    bool visibility;
    // determine whether this layer should be mapped
    int width, height;
    // Size
    int minRow, minCol;
    // Position of this layer on the Canvas
    Mat M;

public:
    static int layerCount;
    friend class ImageProject;
    friend class LayerGroup;
    friend class LayerBasic;
    // To write other operations of different types
    // you can add other friend classes

    Layer();
    Layer(string FILE_PATH, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
    Layer(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol, Mat M);

    void create(string FILE_PATH, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
    void create(Mat M, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
    void create(string name, Transparency visionType = OPAQUE, int width = 0, int height = 0, bool visibility = 1, int minRow = 0, int minCol = 0);

    void set_name(string name);
    string get_name();
    void set_id(int id);
    int get_id();
    int get_width();
    int get_height();
    QImage toQImage_ref(QImage::Format format) {
        return QImage(M.data, M.cols, M.rows, static_cast<int>(M.step), format);
    }
};

#endif // LAYER_H
