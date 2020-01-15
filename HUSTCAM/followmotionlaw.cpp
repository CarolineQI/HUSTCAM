#include "followmotionlaw.h"



FollowMotionLaw::FollowMotionLaw(double h,
                                 double r1T,
                                 double d1T,
                                 double r2T,
                                 double d2T,
                                 QVector<int> R1FType,
                                 QVector<int> R2FType,
                                 QVector<double> R1T,
                                 QVector<double> R2T)
{
    m_h=h;
    m_r1T=r1T;
    m_d1T=d1T;
    m_r2T=r2T;
    m_d2T=d2T;

    m_R1FType=R1FType;
    m_R2FType=R2FType;
    m_R1T=R1T;
    m_R2T=R2T;

    m_T=m_r1T+m_d1T+m_r2T+m_d2T;
    m_R1=new RCurve(m_R1T,m_R1FType);
    m_R2=new RCurve(m_R2T,m_R2FType);

    update();

}

FollowMotionLaw::FollowMotionLaw(double h,
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
                                 QList<QPointF> R2JPoints)
{
    m_h=h;
    m_r1T=r1T;
    m_d1T=d1T;
    m_r2T=r2T;
    m_d2T=d2T;

    m_R1SPoints=R1SPoints;
    m_R1VPoints=R1VPoints;
    m_R1APoints=R1APoints;
    m_R1JPoints=R1JPoints;
    m_R2SPoints=R2SPoints;
    m_R2VPoints=R2VPoints;
    m_R2APoints=R2APoints;
    m_R2JPoints=R2JPoints;

    m_T=m_r1T+m_d1T+m_r2T+m_d2T;
    m_R1=new RCurve(m_R1SPoints,m_R1VPoints,m_R1APoints,m_R1JPoints);
    m_R2=new RCurve(m_R2SPoints,m_R2VPoints,m_R2APoints,m_R2JPoints);

    update();

}

void FollowMotionLaw::update()
{
    double T1=m_r1T;
    double T2=T1+m_d1T;
    double T3=T2+m_r2T;
    for(double t=0;t<m_T;t+=0.0001)
    {
        double s,v,a,j;
        if(t<T1){
            s=m_R1->rs(t/m_r1T)*m_h;
            v=m_R1->rv(t/m_r1T)*m_h/m_r2T;
            a=m_R1->ra(t/m_r1T)*m_h/pow(m_r2T,2);
            j=m_R1->rj(t/m_r1T)*m_h/pow(m_r2T,3);
        }else if(t<T2){
            s=m_h;
            v=0;
            a=0;
            j=0;
        }else if(t<T3){
            s=m_R2->rs(1.0-(t-T2)/m_r2T)*m_h;
            v=m_R2->rv(1.0-(t-T2)/m_r2T)*m_h/m_r2T*-1.0;
            a=m_R2->ra(1.0-(t-T2)/m_r2T)*m_h/pow(m_r2T,2);
            j=m_R2->rj(1.0-(t-T2)/m_r2T)*m_h/pow(m_r2T,3);
        }else{
            s=0;
            v=0;
            a=0;
            j=0;
        }
        m_SPoints<<QPointF(t,s);
        m_VPoints<<QPointF(t,v);
        m_APoints<<QPointF(t,a);
        m_JPoints<<QPointF(t,j);

        m_VmMin=min(m_VmMin,v);
        m_VmMax=max(m_VmMax,v);

        m_AmMin=min(m_AmMin,a);
        m_AmMax=max(m_AmMax,a);

        m_JmMin=min(m_JmMin,j);
        m_JmMax=max(m_JmMax,j);

        m_Qm=max(m_Qm,abs(a*v));
    }


}
