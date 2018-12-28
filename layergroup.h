#ifndef LAYERGROUP_H
#define LAYERGROUP_H

#include "layer.h"

const int defaultSize = 1000;

class LayerGroup
{
private:
    int layerNum;
    int maxHeight, maxWidth;
    vector<int> vec_id;
    vector<Layer> vec_layer;
public:
    LayerGroup(int maxHeight = defaultSize, int maxWidth = defaultSize);

    bool insert(Layer layer, int id = -1);
};

#endif // LAYERGROUP_H
