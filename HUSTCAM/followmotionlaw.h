#ifndef FOLLOWMOTIONLAW_H
#define FOLLOWMOTIONLAW_H

#include"rcurve.h"

class FollowMotionLaw
{
public:
    FollowMotionLaw();
    
    double m_h;//行程
    double m_r1T;//升程
    double m_r2T;//回程
    double m_d1T;//远休止
    double m_d2T;//近休止
    
    QList<QPointF> m_FMLpoints;

    QList<double> m_R1T;
    
    QList<int> m_R1FType;
    
    QList<double> m_R2T;
    
    QList<int> m_R2FType;
    
};

#endif // FOLLOWMOTIONLAW_H
