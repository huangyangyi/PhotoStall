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
    layer.angle += PI * angle / 180;
    while(layer.angle > PI * 2)
        layer.angle -= PI * 2;
}

void LayerBasic::layerTranslation(Layer &layer, int x, int y)
{
	layer.minCol += x;
	layer.minRow += y;
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
	layer.minCol = rect.x;
	layer.minRow = rect.y;
	layer.width = rect.width;
	layer.height = rect.height;
    layer.M = dst;
}

void LayerBasic::layerLine(Layer & layer, Point pt1, Point pt2, const Scalar & color,
                           int state, int thickness, int lineType, int shift)
{
	if (state == 1)//draw
	{
		line(layer.M, pt1, pt2, color, thickness, lineType, shift);
		line(layer.valued, pt1, pt2, Scalar(1), thickness, lineType, shift);
	}
	else//erase
	{
        line(layer.M, pt1, pt2, Scalar(255, 255, 255), -1, lineType, shift);
        line(layer.valued, pt1, pt2, Scalar(0), -1, lineType, shift);
	}
}

void LayerBasic::layerCircle(Layer & layer, Point center, int radius, const Scalar & color,
                             int state, int thickness, int lineType, int shift)
{
	if (state == 1)
	{
		circle(layer.M, center, radius, color, thickness, lineType, shift);
		circle(layer.valued, center, radius, Scalar(1), thickness, lineType, shift);
	}
	else 
	{
        circle(layer.M, center, radius, Scalar(255, 255, 255), -1, lineType, shift);
        circle(layer.valued, center, radius, Scalar(0), -1, lineType, shift);
	}
}

void LayerBasic::layerRect(Layer & layer, Rect rect, const Scalar & color,
                           int state, int thickness, int lineType, int shift)
{
	if (state == 1)
	{
		rectangle(layer.M, rect, color, thickness, lineType, shift);
		rectangle(layer.valued, rect, Scalar(1), thickness, lineType, shift);
	}
	else
	{
        rectangle(layer.M, rect, Scalar(255, 255, 255), -1, lineType, shift);
        rectangle(layer.valued, rect, Scalar(0), -1, lineType, shift);
	}
}

