#include "layer.h"

int Layer::layerCount = 0;

Layer::Layer()
{
    name = "unknown";
    visionType = OPAQUE;
    cornerX = cornerY = 0;
    width = height = 0;
    id = ++layerCount;
    M.create(0, 0, CV_8UC1);
}

Layer::Layer(string FILE_PATH, string name, int visionType, int cornerX, int cornerY)
    :name(name), visionType(visionType), cornerX(cornerX), cornerY(cornerY)
{
    M = imread(FILE_PATH);
    id = ++layerCount;
    width = M.cols;
    height = M.rows;
}

Layer::Layer(string name, int visionType, int width, int height, int cornerX, int cornerY, Mat M)
    :name(name), visionType(visionType), width(width), height(height), cornerX(cornerX), cornerY(cornerY), M(M)
{ }

void Layer::set_name(string name)
{
    this->name = name;
}
