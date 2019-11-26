#ifndef PLANECAMITEM_H
#define PLANECAMITEM_H
#include"planeitem.h"
#include<QPen>
#include<QPainter>

//! [0]

//! [0]

struct PlaneCAMData
{
    //normal planeCAM
    //********DATA**************
    enum upRule{uUniform,uAccelerate,uSinAcc,uCosAcc};//升程规律
    enum downRule{dUniform,dAccelerate,dSinAcc,dCosAcc};//回程规律

    double m_fBR;//base circle r
    double m_H;//xing cheng
    int m_nTCAng;//tui cheng ang
    int m_nYXZAng;//yuan xiu zhi ang
    int m_nHCAng;//hui cheng ang
    int m_nJXZAng;//jin xiu zhi ang

    QPointF m_JXZsP;
    QPointF m_TCsP;
    QPointF m_YXZsP;
    QPointF m_HCsP;

    QPointF* m_linePoints[361];
//    QPointF* m_arcPoints[361];

    QVector<QPointF> m_arcPoints;
    upRule m_upRule;
    downRule m_downRule;
    PlaneCAMData(double fBaseR,
                 double H,
                 int nTCAng,
                 int nYXZAng,
                 int nHCAng,
                 int nJXZAng,
                 upRule uR,
                 downRule dR)
    {
        m_fBR=fBaseR;
        m_H=H;
        m_nTCAng=nTCAng;
        m_nYXZAng=nYXZAng;
        m_nHCAng=nHCAng;
        m_nJXZAng=nJXZAng;
        m_upRule=uR;
        m_downRule=dR;

        int JXZsP=0;
        int TCsP=JXZsP+m_nJXZAng;
        int YXZsP=TCsP+m_nTCAng;
        int HCsP=YXZsP+m_nYXZAng;
        for(int i=0;i<=360;i++)
        {
            double x=((double)i/360.0-0.5)*i;
            double y;
            x=i;
            if(i<TCsP)
            {
                y=m_fBR;
            }else if (i<YXZsP){
                y=m_fBR+(i-TCsP)*m_H/float(m_nTCAng);
            }else if (i<HCsP) {
                y=m_fBR+m_H;
            }else{
                y=m_fBR+(1.0-(i-HCsP)/float(m_nHCAng))*m_H;
            }

        m_linePoints[i]=new QPointF(x,y);
        m_arcPoints.push_back(QPointF(cos(M_PI/180.0*i)*m_linePoints[i]->y(),sin(M_PI/180.0*i)*m_linePoints[i]->y()));
        }

        m_JXZsP=QPointF();
        m_TCsP=QPointF();
        m_YXZsP=QPointF();
        m_HCsP=QPointF();

    }
    PlaneCAMData():PlaneCAMData(100,100,90,20,90,160,
                        upRule::uUniform,downRule::dUniform){}


    //********DATA**************
};

class PlaneCamItem:public PlaneItem
{

public:
//    enum TLActType{Straight,Rotate};
    enum TLShapeType{PlaneCam,CylindricalCam,ConicalCam};

    PlaneCamItem(int actType,
            TLShapeType TLST,
            PlaneCAMData planeCAMData,
            QGraphicsItem* parent=nullptr);

    QRectF boundingRect()const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget=nullptr)Q_DECL_OVERRIDE;

//    void rotate();

    PlaneCAMData m_pCAMData;
private:
    QGraphicsItem* m_JLItem;
    TLShapeType m_TLShapeType;
    QRectF m_RectF;

    const QPen m_PenTCAct=QPen(QColor(Qt::blue),2,Qt::SolidLine);//tui cheng pen
    const QPen m_PenYXZAct=QPen(QColor(Qt::green),2,Qt::SolidLine);//yuan xiu zhi pen
    const QPen m_PenHCAct=QPen(QColor(Qt::red),2,Qt::SolidLine);//hui cheng pen
    const QPen m_PenJXZAct=QPen(QColor(Qt::yellow),2,Qt::SolidLine);//jinxiuzhi pen
    const QPen m_PenBase=QPen(QBrush(Qt::black),1,Qt::DashLine);//base circle pen


};
//! [0]


#endif // PLANECAMITEM_H
