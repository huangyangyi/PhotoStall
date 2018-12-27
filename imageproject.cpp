#include "imageproject.h"

ImageProject::ImageProject(int maxWidth, int maxHeight)
    :maxWidth(maxWidth), maxHeight(maxHeight)
{
    list = new LayerList;
    LayerNode* bottom = new LayerNode;
    LayerNode* up = new LayerNode;

    // set bottom
    bottom->layer.name = "bottom_layer";
    bottom->layer.height = maxHeight;
    bottom->layer.width = maxWidth;
    bottom->layer.M.create(maxHeight, maxWidth, CV_8UC1);

    //set up
    up->layer.name = "up_layer";
    up->layer.visionType = TRANSPARENT;
    up->layer.height = maxHeight;
    up->layer.width = maxWidth;
    up->layer.M.create(maxHeight, maxWidth, CV_8UC1);

    bottom->next = up;
    up->next = NULL;
    list->head = bottom;

    currentLayer = NULL;
}
