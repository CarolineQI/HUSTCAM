#include "diagramitem.h"
#include<QPainter>
#include<QTimer>


DiagramItem:: DiagramItem(ActionType actionType,
                          int TLAT,
                          PlaneCamItem::TLShapeType TLST,
                          int CDJAT,
                          PlaneCDJItem::CDJShapeType CDJST,
                          QGraphicsItem* parent)
    :QGraphicsObject(parent)
{

    myActionType=actionType;
    myTLActType=TLAT;
    myTLShapeType=TLST;
    myCDJActType=CDJAT;
    myCDJShapeType=CDJST;

//    PlaneCAMData planeCAMData();
    myCamItem=new PlaneCamItem(myTLActType,
                          myTLShapeType,
                          PlaneCAMData(),
                          this);
    myCamJLItem=new JLItem(myTLActType,this);
    myCDJItem=new PlaneCDJItem(myCDJActType,
                          myCDJShapeType,
                          QPoint(0,150),
                          QPoint(0,0),
                          CDJData(),
                          this);
    myCDJJLItem=new JLItem(myCDJActType,this);

    myCamItem->setPos(0,0);
    myCamJLItem->setPos(0,0);
    myCDJItem->setPos(0,-260);
    myCDJJLItem->setPos(0,-260);
    myCamItem->setRotation(-(90+myCamItem->m_pCAMData.m_nJXZAng));


    QParallelAnimationGroup* animationGroup=new QParallelAnimationGroup(this);

    QPropertyAnimation *myCamAnimation=new QPropertyAnimation(myCamItem,"rotation");
    myCamAnimation->setStartValue(0);
    myCamAnimation->setEndValue(360);
    myCamAnimation->setEasingCurve(QEasingCurve::Linear);
    animationGroup->addAnimation(myCamAnimation);

    QPropertyAnimation* myCDJAnimation=new QPropertyAnimation(myCDJItem,"pos");
    myCDJAnimation->setStartValue(QPoint(0,-400));
    myCDJAnimation->setEndValue(QPoint(0,-200));
    myCDJAnimation->setEasingCurve(QEasingCurve::SineCurve);
    animationGroup->addAnimation(myCDJAnimation);


    for(int i=0;i<animationGroup->animationCount();++i)
    {
        QPropertyAnimation*anim
                =qobject_cast<QPropertyAnimation*>(animationGroup->animationAt(i));
        //anim->setEasingCurve(QEasingCurve::Linear);
        anim->setDuration(2000);
    }

    //***************setLoopCount*************************
    //By default this value is 1,
    //indicating that the animation should run once only, and then stop.
    //By changing it you can let the animation loop several times.
    //With a value of 0, the animation will not run at all,
    //and with a value of -1, the animation will loop forever until stopped.
    //****************************************************

//    animationGroup->setLoopCount(-1);
//    animationGroup->start();


}

QRectF DiagramItem::boundingRect()const
{
    return QRectF();
}
void DiagramItem::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void DiagramItem::advance(int step)
{
    if(!step)return;
    //static int timeInt=0;
    int ad=1;
    myCamItem->setRotation(myCamItem->rotation()+ad);

//    int x=myCDJItem->x();
//    int y=myCamItem->m_pCAMData.m_linePoints[myCamItem->rotation()];
//    myCDJItem->setPos(x,y);
}
