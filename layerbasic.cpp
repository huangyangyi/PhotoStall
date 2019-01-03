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
    Mat src = layer.M;
    Mat dst;

    Size dst_sz = src.size();

    //定义平移矩阵
    Mat t_mat = Mat::zeros(2,3,CV_32FC1);
    t_mat.at<float>(0,0) = 1;
    t_mat.at<float>(0,2) = x;
    t_mat.at<float>(1,1) = 1;
    t_mat.at<float>(1,2) = y;

    //根据平移矩阵进行仿射变换
    warpAffine(src,dst,t_mat,dst_sz);
    layer.M = dst;
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

void LayerBasic::layerTailoring(Layer &layer,int x,int y,int width,int height)
{
    Mat src= layer.M;
    Rect rect(x,y,width,height);
    Mat dst = src(rect);
    layer.M = dst;
}
