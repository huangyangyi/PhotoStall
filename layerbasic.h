#ifndef LAYERBASIC_H
#define LAYERBASIC_H

#include "layer.h"

// It is a friend class of Layer
// you can modify a layer directly

class LayerBasic
{
public:
    LayerBasic();

    // write operations as
    // *** func(Layer& layer, ....);

    // Geometric transformation function
    void layerResize(Layer& layer,double fx,double fy);
    // 放缩
    void layerRotate(Layer& layer,double angle);
    // 旋转
    void layerTranslation(Layer& layer,int x,int y);
    // 平移

    // Histogram
    Mat layerCalHist(Layer& layer);
    // 计算直方图
    Mat layerShowHist(Layer& layer);
    // 显示直方图
    void layerEqualizeHist(Layer& layer);
    // 直方图均衡化

    // Filter
    void layerBlur(Layer& layer);
    // 均值滤波
    void layerGaussBlur(Layer& layer);
    // 高斯滤波
    void layerMedianBlur(Layer& layer);
    // 中值滤波
    void layerBilateralFilter(Layer& layer);
    // 双边滤波

    // Tailoring
    void layerTailoring(Layer &layer,int x,int y,int width,int height);
};

#endif // LAYERBASIC_H
