#ifndef IMAGEPROJECT_H
#define IMAGEPROJECT_H

#include "layer.h"

struct LayerNode
{
    Layer layer;
    LayerNode* next;
};

struct LayerList
{
    LayerNode* head;
};

class ImageProject
{
private:
    int maxWidth, maxHeight;
    LayerList* list;
    Layer* currentLayer;
public:
    ImageProject(int maxWidth = 1000, int maxHeight = 1000);
};

#endif // IMAGEPROJECT_H
