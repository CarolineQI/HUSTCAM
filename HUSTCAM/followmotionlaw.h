#ifndef FOLLOWMOTIONLAW_H
#define FOLLOWMOTIONLAW_H
#include<algorithm>
#include"rcurve.h"

using namespace std;
class FollowMotionLaw
{
public:

    FollowMotionLaw()
    {
        m_T=m_r1T+m_d1T+m_r2T+m_d2T;
        m_R1=new RCurve(m_R1T,m_R1FType);
        m_R2=new RCurve(m_R2T,m_R2FType);
        update();
    }
    FollowMotionLaw(double h,
                    double r1T,
                    double d1T,
                    double r2T,
                    double d2T,
                    QVector<int> R1FType,
                    QVector<int> R2FType,
                    QVector<double> R1T,
                    QVector<double> R2T);

    FollowMotionLaw(double h,
                    double r1T,
                    double d1T,
                    double r2T,
                    double d2T,
                    QList<QPointF> R1SPoints,
                    QList<QPointF> R1VPoints,
                    QList<QPointF> R1APoints,
                    QList<QPointF> R1JPoints,
                    QList<QPointF> R2SPoints,
                    QList<QPointF> R2VPoints,
                    QList<QPointF> R2APoints,
                    QList<QPointF> R2JPoints);

//input
    double m_h=1.0;//行程
    double m_T;//循环周期
    double m_r1T=0.25;//升程
    double m_d1T=0.25;//远休止
    double m_r2T=0.25;//回程
    double m_d2T=0.25;//近休止

    //ProDesign
    QVector<int> m_R1FType={1,1,1,1,1,1,1,1};
    QVector<int> m_R2FType={1,1,1,1,1,1,1,1};
    QVector<double> m_R1T={0,0.025,0.125,0.175,0.45,0.55,0.825,0.875,0.975};
    QVector<double> m_R2T={0,0.025,0.125,0.175,0.45,0.55,0.825,0.875,0.975};

    //ReDesign
    QList<QPointF> m_R1SPoints;
    QList<QPointF> m_R1VPoints;
    QList<QPointF> m_R1APoints;
    QList<QPointF> m_R1JPoints;

    QList<QPointF> m_R2SPoints;
    QList<QPointF> m_R2VPoints;
    QList<QPointF> m_R2APoints;
    QList<QPointF> m_R2JPoints;

    RCurve* m_R1;
    RCurve* m_R2;
    
//outpot
    QList<QPointF> m_SPoints;
    QList<QPointF> m_VPoints;
    QList<QPointF> m_APoints;
    QList<QPointF> m_JPoints;

    double m_VmMin=0;
    double m_VmMax=0;

    double m_AmMin=0;
    double m_AmMax=0;

    double m_JmMin=0;
    double m_JmMax=0;

    double m_Qm=0;

public slots:
    void update();
    
};

#endif // FOLLOWMOTIONLAW_H
