#ifndef ITEMPART_H
#define ITEMPART_H
#include<QGraphicsObject>
#include"jlitem.h"

namespace ActType {
    const int MoveHorizontal   = 0;
    const int MoveVertical     = 1;
    const int Rotate           = 2;
};

class PlaneItem:public QGraphicsObject
{
public:

    PlaneItem(int actType,QGraphicsItem*parent=nullptr);
protected:
    int m_actType;
//    QGraphicsObject* m_jlItem;
//    QGraphicsObject* m_mainItem;
};



#endif // ITEMPART_H
