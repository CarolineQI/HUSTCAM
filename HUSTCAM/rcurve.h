#ifndef RCURVE_H
#define RCURVE_H


#include<QList>
#include<QPointF>
#include<QVector>
#include<math.h>


class RCurve
{
public:
    RCurve(QVector<double> T,QVector<int> F);
    ~RCurve()=default;

    double ar;
    double dr;
    double am;
    double dm;
    double vm;

    QList<QPointF> m_SCurve;//无量纲位移曲线离散点
    QList<QPointF> m_VCurve;//无量纲速度曲线离散点
    QList<QPointF> m_ACurve;//无量纲加速度曲线离散点
    QList<QPointF> m_JCurve;//无量纲跃度曲线离散点
   
    QVector<double> m_T;
    QVector<int> m_F;

    double rs(double t);//无量纲位移
    double rv(double t);//无量纲速度
    double ra(double t);//无量纲加速度
    double rj(double t);//无量纲跃度

private:
    
    double DF1(int type,double x);
    double F1(int type,double x);
    double SF1(int type,double x);
    double SSF1(int type,double x);
    
    double DF2(int type,double x);
    double F2(int type,double x);
    double SF2(int type,double x);
    double SSF2(int type,double x);
    
    double DH(int type,double x);
    double H(int type,double x);
    double SH(int type,double x);
    double SSH(int type,double x);

    double s1(double t);
    double s2(double t);
    double s3(double t);
    double s4(double t);
    double s5(double t);
    double s6(double t);
    double s7(double t);
    double s8(double t);
    double s9(double t);

    double v1(double x);
    double v2(double x);
    double v3(double x);
    double v4(double x);
    double v5(double x);
    double v6(double x);
    double v7(double x);
    double v8(double x);
    double v9(double x);

    double a1(double x);
    double a2(double x);
    double a3(double x);
    double a4(double x);
    double a5(double x);
    double a6(double x);
    double a7(double x);
    double a8(double x);
    double a9(double x);

    double j1(double x);
    double j2(double x);
    double j3(double x);
    double j4(double x);
    double j5(double x);
    double j6(double x);
    double j7(double x);
    double j8(double x);
    double j9(double x);
    
    void GetAm();
    void GetRCurve();//无量纲通用曲线


};

#endif // RCURVE_H
