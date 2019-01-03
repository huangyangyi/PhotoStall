#include "layer.h"

int Layer::layerCount = 0;

Layer::Layer()
{
    name = "unknown";
    visionType = OPAQUE;
    minCol = minRow = 0;
    width = height = 0;
    id = ++layerCount;
    M = Mat(0, 0, CV_8UC3, Scalar(255, 255, 255));
    valued = Mat(0, 0, CV_8UC1, Scalar(0));
}

Layer::Layer(string FILE_PATH, string name, Transparency visionType, bool visibility, int minRow, int minCol)
    :name(name), visionType(visionType), minCol(minCol), minRow(minRow), visibility(visibility)
{
    M = imread(FILE_PATH);
    valued = Mat(M.rows, M.cols, CV_8UC1, Scalar(0));
    id = ++layerCount;
    width = M.cols;
    height = M.rows;
}

Layer::Layer(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol, Mat M)
    :name(name), visionType(visionType), visibility(visibility), width(width), height(height), minCol(minCol), minRow(minRow), M(M)
{
    valued = Mat(height, width, CV_8UC1, Scalar(0));
}

void Layer::create(string FILE_PATH, string name, Transparency visionType, bool visibility, int minRow, int minCol)
{
    M = imread(FILE_PATH);
    this->name = name;
    this->visionType = visionType;
    this->visibility = visibility;
    this->minRow = minRow;
    this->minCol = minCol;
    width = M.cols;
    height = M.rows;
    valued = Mat(M.rows, M.cols, CV_8UC1, Scalar(0));
}

void Layer::create(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol)
{
    M = Mat(height, width, CV_8UC3, Scalar(255, 255, 255));
    valued = Mat(height, width, CV_8UC1, Scalar(0));
    this->name = name;
    this->visionType = visionType;
    this->visibility = visibility;
    this->minRow = minRow;
    this->minCol = minCol;
    this->width = width;
    this->height = height;
}

void Layer::create(Mat M, string name, Transparency visionType, bool visibility, int minRow, int minCol)
{
    this->M = M;
    valued = Mat(M.rows, M.cols, CV_8UC1, Scalar(0));
    this->name = name;
    this->visionType = visionType;
    this->visibility = visibility;
    this->minRow = minRow;
    this->minCol = minCol;
    this->width = M.cols;
    this->height = M.rows;
}
