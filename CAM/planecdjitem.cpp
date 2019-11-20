#include "planecdjitem.h"


//! [2]
PlaneCDJItem::PlaneCDJItem(int actType,
                 CDJShapeType CDJST,
                 QPointF endPoint,
                 QPointF startPoint,
                 CDJData data,
                 QGraphicsItem* parent)
    :PlaneItem(actType,parent)
{
    m_CDJShapeType=CDJST;
    m_StartPoint=startPoint;
    m_EndPoint=endPoint;
    m_CDJData=data;
//    myJLItem=new JLItem(myActType,this);
//    myJLItem->setPos(myStartPoint);
}

QRectF PlaneCDJItem::boundingRect()const
{
    return QRectF();
}

void PlaneCDJItem::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(QPen(Qt::black,2));
    painter->setBrush(Qt::NoBrush);
    painter->drawLine(m_StartPoint,m_EndPoint);

    switch (m_CDJShapeType) {
    case CDJShapeType::Roller:
        painter->drawEllipse(m_EndPoint,5,5);
        painter->drawEllipse(m_EndPoint,10,10);
        break;
    case CDJShapeType::Point:
        painter->setPen(QPen(Qt::black,2));
        painter->drawPoint(m_EndPoint);
        break;
    case CDJShapeType::Plane:
        painter->drawLine(QPointF(m_EndPoint.x()-50,m_EndPoint.y()) ,QPointF(m_EndPoint.x()+50,m_EndPoint.y()));
        break;
    default:
        break;
    }
}

//! [2]

