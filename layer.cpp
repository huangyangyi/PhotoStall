#include "layer.h"

int Layer::layerCount = 0;

Layer::Layer()
{
    name = "unknown";
    visionType = OPAQUE;
    minCol = minRow = 0;
    width = height = 0;
    id = ++layerCount;
    M.create(0, 0, CV_8UC3);
}

Layer::Layer(string FILE_PATH, string name, Transparency visionType, bool visibility, int minRow, int minCol)
    :name(name), visionType(visionType), minCol(minCol), minRow(minRow), visibility(visibility)
{
    M = imread(FILE_PATH);
    id = ++layerCount;
    width = M.cols;
    height = M.rows;
}

Layer::Layer(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol, Mat M)
    :name(name), visionType(visionType), visibility(visibility), width(width), height(height), minCol(minCol), minRow(minRow), M(M)
{ }

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
}

void Layer::create(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol)
{
    (this->M).create(height, width, CV_8UC3);
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
    this->name = name;
    this->visionType = visionType;
    this->visibility = visibility;
    this->minRow = minRow;
    this->minCol = minCol;
    this->width = M.cols;
    this->height = M.rows;
}

void Layer::set_name(string name)
{
    this->name = name;
}

string Layer::get_name()
{
    return this->name;
}

void Layer::set_id(int id)
{
    this->id = id;
}

int Layer::get_id()
{
    return this->id;
}

int Layer::get_height(){
    return this->height;
}

int Layer::get_width(){
    return this->width;
}
