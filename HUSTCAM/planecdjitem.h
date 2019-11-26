#ifndef PLANECDJITEM_H
#define PLANECDJITEM_H
#include"planeitem.h"
#include <QPainter>

//! [2]

struct CDJData
{
    enum  OffsetDir{left,right};//pianjuDirection
    double m_fRollerR;//gun zi ban jing
    OffsetDir m_OffsetDir;
    double m_fOffsetDis;//pianju
    double m_fCenterDis;//zhong xin ju
    double m_fLength;//gan chang
    int m_nH;//xingcheng(straight)/baifu(rotate)

    CDJData(double fRollerR,
             OffsetDir offsetDir,
             double fOffsetDis,
             double fCenterDis,
             double fLength,
             int nH)
    {
        m_fRollerR=fRollerR;
        m_OffsetDir=offsetDir;
        m_fOffsetDis=fOffsetDis;
        m_fCenterDis=fCenterDis;
        m_fLength=fLength;
        m_nH=nH;
    }

    CDJData():CDJData(20,right,0,0,100,100){}
};

class PlaneCDJItem:public PlaneItem
{
public:

//    enum CDJActType{Straight,Rotate};
    enum CDJShapeType{Roller,Point,Plane};

    PlaneCDJItem(int actType,
            CDJShapeType CDJST,
            QPointF endPoint,
            QPointF startPoint=QPointF(0,0),
            CDJData data=CDJData(),
            QGraphicsItem* parent=nullptr);

    QRectF boundingRect()const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget=0)Q_DECL_OVERRIDE;

    CDJData m_CDJData;

private:
    CDJShapeType m_CDJShapeType;
    QPointF m_StartPoint;
    QPointF m_EndPoint;

    QGraphicsItem* myJLItem;

};
//! [2]


#endif // PLANECDJITEM_H
