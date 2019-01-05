#include "layerbasic.h"

LayerBasic::LayerBasic()
{

}

void LayerBasic::layerResize(Layer &layer, double fx, double fy)
{
    Mat src = layer.M;
    Mat dst;
    resize(src,dst,Size(src.cols*fx,src.rows*fy));
    layer.M = dst;
}

void LayerBasic::layerRotate(Layer& layer,double angle)
{
    Mat src = layer.M;
    Mat dst;

    Size src_sz = src.size();
    Size dst_sz(src_sz.height, src_sz.width);
    int len = std::max(src.cols, src.rows);

    //指定旋转中心
    Point2f center(len / 2., len / 2.);
    //获取旋转矩阵（2x3矩阵）
    Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0);
    //根据旋转矩阵进行仿射变换
    warpAffine(src, dst, rot_mat, dst_sz);

    layer.M = dst;
}

void LayerBasic::layerTranslation(Layer &layer, int x, int y)
{
	if (layer.minCol + x > 0)layer.minCol += x;
	else layer.minCol = 0;
	if (layer.minRow + y > 0)layer.minRow += y;
	else layer.minRow = 0;
}

Mat LayerBasic::layerCalHist(Layer &layer)
{
    Mat image = layer.M;
    Mat hist;
    int channels[] = {0};
    int dims = 1;
    int histSize[] = {256};
    float granges[] = {0, 255};
    const float *ranges[] = {granges};
    calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
    return hist;
}

Mat LayerBasic::layerShowHist(Layer &layer)
{
    Mat hist = LayerBasic::layerCalHist(layer);
    Mat showImage(256,256, CV_8U,Scalar(0));
    int i;
    double maxValue = 0;
    minMaxLoc(hist, 0, &maxValue, 0, 0);
    for(i = 0; i < 256; i++)
    {
        float value = hist.at<float>(i);
        int intensity = saturate_cast<int>(256 - 256* (value/maxValue));
        rectangle(showImage, Point(i,256 - 1), Point((i+1)-1, intensity), Scalar(255));
    }
    return showImage;

}

void LayerBasic::layerEqualizeHist(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    Mat matArray[3];
    split(src,matArray);
    for(int i=0;i<3;i++)
    {
        equalizeHist(matArray[i],matArray[i]);
    }
    merge(matArray,3,dst);

    layer.M = dst;
}

void LayerBasic::layerBlur(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    blur(src,dst,Size(3,3),Point(-1,-1));
    layer.M = dst;
}

void LayerBasic::layerGaussBlur(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    GaussianBlur(src,dst,Size(5,5),5,5);
    layer.M = dst;
}

void LayerBasic::layerMedianBlur(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    medianBlur(src,dst,5);
    layer.M = dst;
}

void LayerBasic::layerBilateralFilter(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    bilateralFilter(src,dst,5,100,3);
    layer.M = dst;
}

void LayerBasic::layerTailoring(Layer &layer,Rect rect)
{
    Mat src= layer.M;
    Mat dst = src(rect);
    layer.M = dst;
}

void LayerBasic::layerLine(Layer & layer, Point pt1, Point pt2, const Scalar & color,
                           int state=1, int thickness=1, int lineType=8, int shift=0)
{
    if(state == 1)//draw
        line(layer.M, pt1, pt2, color, thickness, lineType, shift);
    else//erase
        line(layer.M, pt1, pt2, Scalar(255,255,255), thickness, lineType, shift);
    if(layer.visionType == TRANSPARENT)
        line(layer.valued, pt1, pt2, Scalar(255), thickness, lineType, shift);
}

void LayerBasic::layerCircle(Layer & layer, Point center, int radius, const Scalar & color,
                             int state=1, int thickness=1, int lineType=8, int shift=0)
{
    if(state == 1)
        circle(layer.M, center, radius, color, thickness, lineType, shift);
    else
        circle(layer.M, center, radius, Scalar(255,255,255), thickness, lineType, shift);
    if(layer.visionType == TRANSPARENT)
        circle(layer.valued, center, radius, Scalar(255), thickness, lineType, shift);
}

void LayerBasic::layerRect(Layer & layer, Rect rect, const Scalar & color,
                           int state=1, int thickness=1, int lineType=8, int shift=0)
{
    if(state == 1)
        rectangle(layer.M, rect, color, thickness, lineType, shift);
    else
        rectangle(layer.M, rect, Scalar(255,255,255), thickness, lineType, shift);
    if(layer.visionType == TRANSPARENT)
        rectangle(layer.valued, rect, Scalar(255), thickness, lineType, shift);
}

