#ifndef JLITEM_H
#define JLITEM_H
#include"planeitem.h"

#include<QGraphicsObject>
#include<QPen>
#include<QPainter>
#include<QtMath>

class JLItem: public QGraphicsObject
{
    Q_OBJECT
public:
    JLItem(int actType,QGraphicsItem* parent=nullptr);
    QRectF boundingRect()const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem*option,
               QWidget *widget=nullptr)Q_DECL_OVERRIDE;
private:

   int m_actType;

   const QPen m_JLPen=QPen(QBrush(Qt::gray),1);

};
#endif // JLITEM_H
