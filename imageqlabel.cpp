#include "imageqlabel.h"
#include <QDebug>
ImageQLabel::ImageQLabel()
{

}
ImageQLabel::ImageQLabel(QWidget *parent):QLabel(parent)
{

}
void ImageQLabel::SetPreview(const QPixmap &new_preview)
{
    preview_ = new_preview.copy();
    RefreshView();
}
void ImageQLabel::SetZoomLevel(qreal delta_level)
{
    zoom_level_+=delta_level;
    zoom_level_ = zoom_level_ > 0?(zoom_level_<1.0?zoom_level_:1.0):0.0;
    RefreshView();
}
void ImageQLabel::RefreshView(){
    if (preview_.isNull()) return ;
    resize(preview_.size()*zoom_level_);
    setPixmap(preview_.scaled(preview_.size()*zoom_level_));
}
void ImageQLabel::mousePressEvent(QMouseEvent *event){
    clicked_pos=QPoint(event->x(),event->y());
}
void ImageQLabel::mouseReleaseEvent(QMouseEvent *event){
    QPoint endpoint=QPoint(event->x(),event->y());
    emit dragged(clicked_pos,endpoint);
}
void ImageQLabel::ResetZoom(){
    zoom_level_=1.0;
    RefreshView();
}


qreal ImageQLabel::GetZoomLevel()const{
    return zoom_level_;
}
