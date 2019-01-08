#ifndef LAYERLISTVIEW_H
#define LAYERLISTVIEW_H

#include <QTableView>
#include <QMouseEvent>
#include <QDebug>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QContextMenuEvent>
#include <QMenu>
#include "layertablemodel.h"
#include "layerdelegate.h"

class LayerTableView : public QTableView
{
    Q_OBJECT
signals:
    void tableDataChanged();
    void currentLayerChanged(int index);
public:
    LayerTableView(vector<Layer *> *layerlist,QWidget *parent = nullptr);
    ~LayerTableView();
    void setLayerSize(QSize s);

public slots:
    void addNewLayer(int);
    void deleteLayer(int);

protected:
    void mouseMoveEvent(QMouseEvent * event);
    void contextMenuEvent(QContextMenuEvent * event);

private:
    LayerDelegate *delegate;
    LayerTableModel *model;
    QSize layerSize;

private slots:
    void itemClicked(const QModelIndex&);
    void modelDataChanged(const QModelIndex&,const QModelIndex&,const QVector<int> &);
};

#endif // LAYERLISTVIEW_H
