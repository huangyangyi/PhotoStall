#ifndef LAYERGROUP_H
#define LAYERGROUP_H

#include "layer.h"
#include <vector>
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
    LayerGroup(string file_name, string name = "unknown");
    // Insert function
    // default is to be inserted at the tail
    // otherwise inserted after layer with id
    // cannot insert after the last layer or before the first layer
    bool insert(Layer layer, int id = -1);

    // Delete function
    // delete the layer with this->id == id,
    // cannot delete the first and the last layer
    //bool remove(int id);

    // given a new layer_id order
    // to reorder vec_id and vec_layer
    bool reorder(vector<int> new_id);
};

#endif // LAYERGROUP_H
