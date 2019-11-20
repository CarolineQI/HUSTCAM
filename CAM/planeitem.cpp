#include "planeitem.h"

PlaneItem::PlaneItem(int actType, QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    m_actType=actType;
//    m_jlItem=new JLItem(m_actType,this);
}
