#include "jlitem.h"


JLItem::JLItem(int actType, QGraphicsItem *parent)
    :QGraphicsObject(parent){
    m_actType=actType;
}

QRectF JLItem::boundingRect()const
{
    return QRectF(-25,-25,50,50);
}
void JLItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(m_JLPen);
    painter->setBrush(Qt::white);
    switch (m_actType) {
    case ActType::MoveHorizontal:
        painter->drawLine(QPointF(-25,0),QPointF(25,0));
        for(float left=-25;left<25;left+=5)
        {
             painter->drawLine(QPointF(left,-5),QPointF(left+5,0));
        }
        break;
    case ActType::MoveVertical:
        painter->drawLine(QPointF(-15,-25),QPointF(-15,25));
        painter->drawLine(QPointF(15,-25),QPointF(15,25));
        for(float up=-25;up<25;up+=5)
        {
             painter->drawLine(QPointF(-15,up),QPointF(-20,up+5));
             painter->drawLine(QPointF(20,up),QPointF(15,up+5));
        }
        break;
    case ActType::Rotate:
        painter->drawLine(QPointF(0,0),QPointF(-20,20));
        painter->drawLine(QPointF(0,0),QPointF(20,20));
        painter->drawEllipse(QPointF(0,0),qreal(8),qreal(8));
        painter->drawLine(QPointF(-25,20),QPointF(25,20));
        for(float left=-25;left<25;left+=5)
        {
             painter->drawLine(QPointF(left,25),QPointF(left+5,20));
        }
        break;
    default:
        break;
    }

}

