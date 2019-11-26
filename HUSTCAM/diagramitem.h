#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H
#include<QGraphicsItem>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QGraphicsSceneMouseEvent>
#include<QPen>
#include<QtMath>
#include"planeitem.h"
#include"jlitem.h"
#include"planecamitem.h"
#include"planecdjitem.h"

class DiagramItem: public QGraphicsObject
{
public:
    enum ActionType{Active,Passive};

    DiagramItem(ActionType actionType,
                int TLAT,
                PlaneCamItem::TLShapeType TLST,
                int CDJAT,
                PlaneCDJItem::CDJShapeType CDJST,
                QGraphicsItem* parent=nullptr);

     QRectF boundingRect()const Q_DECL_OVERRIDE;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget=nullptr)Q_DECL_OVERRIDE;

private:
     ActionType myActionType;
     int myTLActType;
     PlaneCamItem::TLShapeType myTLShapeType;
     int myCDJActType;
     PlaneCDJItem::CDJShapeType myCDJShapeType;

     PlaneCamItem* myCamItem;
     JLItem* myCamJLItem;
     PlaneCDJItem* myCDJItem;
     JLItem* myCDJJLItem;

protected:
    void advance(int step) Q_DECL_OVERRIDE;
};

#endif // DIAGRAMITEM_H
