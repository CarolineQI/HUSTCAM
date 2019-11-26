#include "planecamitem.h"


//! [0]
PlaneCamItem::PlaneCamItem(int actType,
                 TLShapeType TLST,
                 PlaneCAMData planeCAMData,
                 QGraphicsItem* parent)
    :PlaneItem(actType,parent)
{
    m_pCAMData=planeCAMData;
    m_TLShapeType=TLST;
}
QRectF PlaneCamItem::boundingRect()const
{
    return m_RectF;
}
void PlaneCamItem::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
   // myJLItem=new JLItem(myActType,this);
    painter->setPen(QPen(Qt::blue,2));
    painter->setBrush(Qt::NoBrush);
    switch (m_TLShapeType) {
    case TLShapeType::PlaneCam:
    {
        //draw base circle
        painter->setPen(m_PenBase);
        painter->drawEllipse(QPointF(0,0),m_pCAMData.m_fBR,m_pCAMData.m_fBR);

        painter->setPen(m_PenHCAct);
        painter->drawLines(m_pCAMData.m_arcPoints);

        painter->setPen(QPen(QBrush(Qt::blue),1,Qt::DashLine));
        painter->drawLine(QPointF(0,0),QPointF(0,0));
        break;
    }
    case TLShapeType::CylindricalCam:
    {
        painter->drawRect(-200,-400,200,400);
        break;
    }
    case TLShapeType::ConicalCam:
       {
        static const QPointF points[4] = {
             QPointF(-10.0, -80.0),
             QPointF(-20.0, -10.0),
             QPointF(80.0, 30.0),
             QPointF(90.0, 70.0)
         };
         painter->drawConvexPolygon(points, 4);
        break;
    }

    default:
        break;
    }
}

//void CamItem::rotate()
//{
////    QParallelAnimationGroup *parallelAnimation=new QParallelAnimationGroup(this);
//    QPropertyAnimation* animation=new QPropertyAnimation(this,"rotation");
//    animation->setDuration(2000);
//    animation->setStartValue(0);
//    animation->setEndValue(360);
//    animation->start();

//}
//! [0]

