#include "layergroup.h"

LayerGroup::LayerGroup(int maxHeight, int maxWidth)
{
    layerNum = 2;
    this->maxHeight = maxHeight;
    this->maxWidth = maxWidth;
    vec_id.clear();
    vec_layer.clear();

    Layer bottom, up;
    bottom.create("bottom layer", OPAQUE, maxWidth, maxHeight, 1, 0, 0);
    up.create("upmost layer", TRANSPARENT, maxWidth, maxHeight, 1, 0, 0);

    vec_id.push_back(bottom.id);
    vec_layer.push_back(bottom);

    vec_id.push_back(up.id);
    vec_layer.push_back(up);
}

bool LayerGroup::insert(Layer layer, int id)
{
    if (id == vec_id[layerNum - 1])
        return 0;
    if (id == -1)
    {
        layerNum++;
        vec_id.push_back(layer.id);
        vec_layer.push_back(layer);
        swap(vec_id[layerNum - 1], vec_id[layerNum - 2]);
        swap(vec_layer[layerNum - 1], vec_layer[layerNum - 2]);
        return 1;
    }
    else
    {
        int place = -1;
        vector<int>::iterator it_id = vec_id.begin();
        vector<Layer>::iterator it_layer = vec_layer.begin();
        for (int i = 0; i < layerNum; i++)
        {
            it_id++;
            it_layer++;
            if (vec_id[i] == id)
            {
                place = i;
                break;
            }
        }
        if (place == -1)
            return 0;
        layerNum++;
        vec_id.insert(it_id, id);
        vec_layer.insert(it_layer, layer);
        return 1;
    }
}
QImage LayerGroup::get_preview()
{
    //TODO:完成合成预览图的逻辑
    if (vec_layer.size()>2)
        return vec_layer[1].toQImage_ref(QImage::Format_RGB888);
    else
        return QImage(500, 500, QImage::Format_RGB888);
}
bool LayerGroup::reorder(vector<int> new_id)
{
    if (vec_id.size() != new_id.size())
        return 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        int p = -1;
        for (int j = 0; j < i; j++)
        {
            if (new_id[j] == new_id[i])
                return 0;
        }
        for (int j = 0; j < vec_id.size(); j++)
        {
            if (vec_id[j] == new_id[i])
            {
                p = j;
                break;
            }
        }
        if (p == -1)
            return 0;
    }
    for (int i = 0; i < vec_id.size(); i++)
    {
        if (vec_id[i] == new_id[i])
            continue;
        int pos = -1;
        for (int j = i + 1; j < vec_id.size(); j++)
        {
            if (vec_id[j] == new_id[i])
            {
                pos = j;
                break;
            }
        }
        swap(vec_id[i], vec_id[pos]);
        swap(vec_layer[i], vec_layer[pos]);
    }
    return 1;
}
