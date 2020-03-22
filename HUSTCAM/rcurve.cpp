#include "rcurve.h"

#include<iostream>
using namespace std;
RCurve::RCurve(QVector<double> T, QVector<int> F)
{
    m_T=T;
    m_F=F;
    GetAm();
    GetRCurve();
}

RCurve::RCurve(QList<QPointF> Spoints, QList<QPointF> Vpoints, QList<QPointF> Apoints, QList<QPointF> Jpoints)
{

}


double RCurve::rs(double t)
{
    if(t<m_T[0])
    {
        return 0.0;
    }else if(t>=m_T[0]&&t<m_T[1])
    {
        return s1(t);
    }else if (t>=m_T[1]&&t<m_T[2]) {
        return s2(t);
    }else if (t>=m_T[2]&&t<m_T[3]) {
        return s3(t);
    }else if (t>=m_T[3]&&t<m_T[4]) {
        return s4(t);
    }else if (t>=m_T[4]&&t<m_T[5]) {
        return s5(t);
    }else if (t>=m_T[5]&&t<m_T[6]) {
        return s6(t);
    }else if (t>=m_T[6]&&t<m_T[7]) {
        return s7(t);
    }else if (t>=m_T[7]&&t<m_T[8]) {
        return s8(t);
    }else if (t>=m_T[8]&&t<=1.0) {
        return s9(t);
    }else {
        return 1.0;
    }

}

double RCurve::rv(double t)
{
    if(t<m_T[0])
    {
        return 0.0;
    }else if(t>=m_T[0]&&t<m_T[1])
    {
        return v1(t);
    }else if (t>=m_T[1]&&t<m_T[2]) {
        return v2(t);
    }else if (t>=m_T[2]&&t<m_T[3]) {
        return v3(t);
    }else if (t>=m_T[3]&&t<m_T[4]) {
        return v4(t);
    }else if (t>=m_T[4]&&t<m_T[5]) {
        return v5(t);
    }else if (t>=m_T[5]&&t<m_T[6]) {
        return v6(t);
    }else if (t>=m_T[6]&&t<m_T[7]) {
        return v7(t);
    }else if (t>=m_T[7]&&t<m_T[8]) {
        return v8(t);
    }else if (t>=m_T[8]&&t<=1.0) {
        return v9(t);
    }else {
        return 0.0;
    }

}

double RCurve::ra(double t)
{
    if(t<m_T[0])
    {
        return 0.0;
    }else if(t>=m_T[0]&&t<m_T[1])
    {
        return a1(t);
    }else if (t>=m_T[1]&&t<m_T[2]) {
        return a2(t);
    }else if (t>=m_T[2]&&t<m_T[3]) {
        return a3(t);
    }else if (t>=m_T[3]&&t<m_T[4]) {
        return a4(t);
    }else if (t>=m_T[4]&&t<m_T[5]) {
        return a5(t);
    }else if (t>=m_T[5]&&t<m_T[6]) {
        return a6(t);
    }else if (t>=m_T[6]&&t<m_T[7]) {
        return a7(t);
    }else if (t>=m_T[7]&&t<m_T[8]) {
        return a8(t);
    }else if (t>=m_T[8]&&t<=1.0) {
        return a9(t);
    }else {
        return 0.0;
    }

}

double RCurve::rj(double t)
{
    if(t<m_T[0])
    {
        return 0.0;
    }else if(t>=m_T[0]&&t<m_T[1])
    {
        return j1(t);
    }else if (t>=m_T[1]&&t<m_T[2]) {
        return j2(t);
    }else if (t>=m_T[2]&&t<m_T[3]) {
        return j3(t);
    }else if (t>=m_T[3]&&t<m_T[4]) {
        return j4(t);
    }else if (t>=m_T[4]&&t<m_T[5]) {
        return j5(t);
    }else if (t>=m_T[5]&&t<m_T[6]) {
        return j6(t);
    }else if (t>=m_T[6]&&t<m_T[7]) {
        return j7(t);
    }else if (t>=m_T[7]&&t<m_T[8]) {
        return j8(t);
    }else if (t>=m_T[8]&&t<=1.0) {
        return j9(t);
    }else {
        return 0.0;
    }

}


double RCurve::DF1(int type,double x)
{

    switch (type) {
    case 1:
    {
        return M_PI/2.0*sin(M_PI*x/2.0);
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}
double RCurve::F1(int type,double x)
{

    switch (type) {
    case 1:
    {
        return 1-cos(M_PI*x/2.0);
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}

double RCurve::SF1(int type,double x)
{

    switch (type) {
    case 1:
    {
        return x-2.0/M_PI*sin(M_PI*x/2.0);
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}
double RCurve::SSF1(int type,double x)
{

    switch (type) {
    case 1:
    {
        return pow(x,2.0)/2.0-4.0/pow(M_PI,2.0)*(1-cos(M_PI*x/2.0));
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}

double RCurve::DF2(int type,double x)
{

    switch (type) {
    case 1:
    {
        return M_PI/2*cos(M_PI*x/2.0);
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}
double RCurve::F2(int type,double x)
{

    switch (type) {
    case 1:
    {
        return sin(M_PI*x/2.0);

    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}

double RCurve::SF2(int type,double x)
{

    switch (type) {
    case 1:
    {
        return 2.0/M_PI*(1.0-cos(M_PI*x/2.0));
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}
double RCurve::SSF2(int type,double x)
{

    switch (type) {
    case 1:
    {
        return 2.0/M_PI*x-4.0/pow(M_PI,2.0)*(sin(M_PI*x/2.0));
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}



double RCurve::DH(int type,double x)
{

    switch (type) {
    case 1:
    {
        return M_PI/2.0*sin(M_PI*x);
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}
double RCurve::H(int type,double x)
{

    switch (type) {
    case 1:
    {
        return (1.0-cos(M_PI*x))/2.0;

    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}

double RCurve::SH(int type,double x)
{

    switch (type) {
    case 1:
    {
        return (x-sin(M_PI*x)/M_PI)/2.0;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

   return 0.0;
}
double RCurve::SSH(int type,double x)
{

    switch (type) {
    case 1:
    {
        return (pow(x,2.0)-2.0/pow(M_PI,2.0)*(1-cos(M_PI*x)))/4.0;
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

    return 0.0;
}

double RCurve::s1(double t)
{
    return m_Aar*pow(m_T[1],2.0)*SSF1(m_F[1],t/m_T[1]);
}

double RCurve::s2( double t)
{
    return s1(m_T[1])+v1(m_T[1])*(t-m_T[1])+m_Aar*pow(t-m_T[1],2.0)/2.0
            +(m_Aam-m_Aar)*pow(m_T[2]-m_T[1],2)*SSF2(m_F[2],(t-m_T[1])/(m_T[2]-m_T[1]));
}

double RCurve::s3( double t)
{
    return s2(m_T[2])+v2(m_T[2])*(t-m_T[2])+m_Aam*pow(t-m_T[2],2.0)/2.0;
}


double RCurve::s4( double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return s3(m_T[3])+v3(m_T[3])*(t-m_T[3])+m_Aam*(m_T[4]-m_T[3])
                *((t-m_T[3])*SF2(m_F[3],1.0)+(m_T[4]-m_T[3])*
                (SSF2(m_F[3],(m_T[4]-t)/(m_T[4]-m_T[3]))-(SSF2(m_F[3],1.0))));
    }else{
        return s3(m_T[3])+v3(m_T[3])*(t-m_T[3])+m_Aam*pow(t-m_T[3],2.0)/2.0
                -m_Aam*pow(m_T[4]-m_T[3],2)*SSH(m_F[7],(t-m_T[3])/(m_T[4]-m_T[3]));
    }
}

double RCurve::s5(double t)
{

    return s4(m_T[4])+v4(m_T[4])*(t-m_T[4]);
}

double RCurve::s6(double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return s5(m_T[5])+v5(m_T[5])*(t-m_T[5])+m_Adm*pow((t-m_T[5]),2.0)/2.0-
                m_Adm*(m_T[6]-m_T[5])*(t-m_T[5])*(SF1(m_F[4],1)*(t-m_T[5])+(m_T[6]-m_T[5])
                *(SSF1(m_F[4],(m_T[6]-t)/(m_T[6]-m_T[5]))-SSF1(m_F[4],1)));
    }else{
        return s5(m_T[5])+v5(m_T[5])*(t-m_T[5])+m_Adm*pow(m_T[6]-m_T[5],2)/2.0
                *SSH(m_F[7],(t-m_T[5])/(m_T[6]-m_T[5]));
    }
}

double RCurve::s7(double t)
{
   return s6(m_T[6])+v6(m_T[6])*(t-m_T[6])+m_Adm*pow(t-m_T[6],2)/2.0;
}

double RCurve::s8(double t)
{
   return s7(m_T[7])+v7(m_T[7])*(t-m_T[7])+m_Adr*pow(t-m_T[7],2.0)/2.0
           +(m_Adm-m_Adr)*(m_T[8]-m_T[7])*(SF2(m_F[4],1)*(t-m_T[7])+(m_T[8]-m_T[7])*
           (SSF2(m_F[4],(m_T[8]-t)/(m_T[8]-m_T[7]))-SSF2(m_F[4],1.0)));
}

double RCurve::s9(double t)
{
   return s8(m_T[8])+v8(m_T[8])*(t-m_T[8])+m_Adr*pow(1.0-m_T[8],2)*
           (SSF1(m_F[5],1.0)-SSF1(m_F[5],(1.0-t)/(1.0-m_T[8])));
}

double RCurve::v1(double t)
{
    return m_Aar*m_T[1]*SF1(m_F[0],t/m_T[1]);
}

double RCurve::v2( double t)
{
    return v1(m_T[1])+m_Aar*(t-m_T[1])+(m_Aam-m_Aar)*(m_T[2]-m_T[1])
            *SF2(m_F[1],(t-m_T[1])/(m_T[2]-m_T[1]));
}

double RCurve::v3( double t)
{
    return v2(m_T[2])+m_Aam*(t-m_T[2]);
}

double RCurve::v4( double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return v3(m_T[3])+m_Aam*(m_T[4]-m_T[3])*(SF2(m_F[2],1)
                -SF2(m_F[2],(m_T[4]-t)/(m_T[4]-m_T[3])));
    }else{
        return v3(m_T[3])+m_Aam*((t-m_T[3])-(m_T[4]-m_T[3])*
                SH(m_F[6],(t-m_T[3])/(m_T[4]-m_T[3])));
    }
}

double RCurve::v5(double t)
{
    Q_UNUSED(t)
    return v4(m_T[4]);
}

double RCurve::v6(double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return v5(m_T[5])+m_Adm*(t-m_T[5])-
                m_Adm*(m_T[6]-m_T[5])*(SF1(m_F[3],1)-SF1(m_F[3],(m_T[6]-t)/(m_T[6]-m_T[5])));
    }else{
        return v5(m_T[5])+m_Adm*(m_T[6]-m_T[5])*SH(m_F[7],(t-m_T[5])/(m_T[6]-m_T[5]));
    }
}

double RCurve::v7(double t)
{
   return v6(m_T[6])+m_Adm*(t-m_T[6]);
}

double RCurve::v8(double t)
{
   return v7(m_T[7])+m_Adr*(t-m_T[7])+(m_Adm-m_Adr)*(m_T[8]-m_T[7])*(SF2(m_F[4],1)-SF2(m_F[4],(m_T[8]-t)/(m_T[8]-m_T[7])));
}

double RCurve::v9(double t)
{
   return v8(m_T[8])+m_Adr*(1-m_T[8])*(SF1(m_F[5],1)-SF1(m_F[5],(1-t)/(1-m_T[8])));
}


double RCurve::a1(double t)
{
    return m_Aar*F1(m_F[0],t/m_T[1]);
}

double RCurve::a2( double t)
{
    return m_Aar+(m_Aam-m_Aar)*F2(m_F[1],(t-m_T[1])/(m_T[2]-m_T[1]));
}

double RCurve::a3( double t)
{
    Q_UNUSED(t)
    return m_Aam;
}

double RCurve::a4( double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return m_Aam*(F2(m_F[2],(m_T[4]-t)/(m_T[4]-m_T[3])));
    }else{
        return m_Aam*(1-H(m_F[6],(t-m_T[3])/(m_T[4]-m_T[3])));
    }
}

double RCurve::a5(double t)
{
    Q_UNUSED(t)
    return 0.0;
}

double RCurve::a6(double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return m_Adm-m_Adm*(F1(m_F[3],(m_T[6]-t)/(m_T[6]-m_T[5])));
    }else{
        return m_Adm*H(m_F[7],(t-m_T[5])/(m_T[6]-m_T[5]));
    }
}

double RCurve::a7(double t)
{
   Q_UNUSED(t)
   return m_Adm;
}

double RCurve::a8(double t)
{
   return m_Adr+(m_Adm-m_Adr)*F2(m_F[6],(m_T[8]-t)/(m_T[8]-m_T[7]));
}

double RCurve::a9(double t)
{
   return m_Adr*F1(m_F[7],(1.0-t)/(1.0-m_T[8]));
}


double RCurve::j1(double t)
{
    return m_Aar/m_T[1]*DF1(m_F[0],t/m_T[1]);
}

double RCurve::j2( double t)
{
    return (m_Aam-m_Aar)/(m_T[2]-m_T[1])*DF2(m_F[1],(t-m_T[1])/(m_T[2]-m_T[1]));
}

double RCurve::j3( double t)
{
    Q_UNUSED(t)
    return 0.0;
}

double RCurve::j4( double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return -m_Aam/(m_T[4]-m_T[3])*DF2(m_F[2],(m_T[4]-t)/(m_T[4]-m_T[3]));
    }else{
        return -m_Aam/(m_T[4]-m_T[3])*DH(m_F[6],(t-m_T[3])/(m_T[4]-m_T[3]));
    }
}

double RCurve::j5(double t)
{
    Q_UNUSED(t)
    return 0.0;
}

double RCurve::j6(double t)
{
    if(m_T[5]-m_T[4]<0.0001){
        return m_Adm/(m_T[6]-m_T[5])*DF1(m_F[3],(m_T[6]-t)/(m_T[6]-m_T[5]));
    }else{
        return m_Adm/(m_T[6]-m_T[5])*DH(m_F[7],(t-m_T[5])/(m_T[6]-m_T[5]));
    }
}

double RCurve::j7(double t)
{
   Q_UNUSED(t)
   return 0.0;
}

double RCurve::j8(double t)
{
   return -(m_Adm-m_Adr)/(m_T[8]-m_T[7])*DF2(m_F[6],(m_T[8]-t)/(m_T[8]-m_T[7]));
}

double RCurve::j9(double t)
{
   return -m_Adr/(1.0-m_T[8])*DF1(m_F[7],(1.0-t)/(1.0-m_T[8]));
}


void RCurve::GetAm()
{
    static bool isfirst=true;

    double aar=m_T[1]*DF2(m_F[1],0)/((m_T[2]-m_T[1])*DF1(m_F[0],1.0)+m_T[1]*DF2(m_F[1],0));//ar=am*aar
    double ddr=(1.0-m_T[8])*DF2(m_F[4],0)/((m_T[8]-m_T[7])*DF1(m_F[5],1)+(1-m_T[8])*DF2(m_F[4],0));//dr=dm*ddr
    double ad;//dm=am*ad
    ad=-(m_T[6]-m_T[5])*DF2(m_F[3],0)/((m_T[4]-m_T[3])*DF1(m_F[3],1));
    if(isfirst){
        m_Aam=abs(double(rand()%10));
    }
    if(m_T[5]-m_T[4]>0.0001){
        m_Adm=m_Aam*ad;
        m_Aar=aar*m_Aam;
        m_Adr=ddr*m_Adm;
        double addad=-1.0;
        double RV=rv(1.0);
        cout<<"RV="<<RV<<::endl;
        while (abs(RV)>0.0001){
            if(RV<-0.0001){
                ad-=addad;
                addad/=10.0;
            }
            ad+=addad;
            m_Adm=m_Aam*ad;
            m_Aar=aar*m_Aam;
            m_Adr=ddr*m_Adm;
            RV=rv(1.0);
            cout<<"RV="<<RV<<::endl;

        }
    }
    double addAm=1.0;
    double rss=rs(1.0);
    while (abs(rss-1.0)>0.0001){
        isfirst=false;
        if(rss>1.0){
            m_Aam-=addAm;
            addAm/=10.0;
        }
        m_Aam+=addAm;
        m_Adm=ad*m_Aam;
        m_Aar=aar*m_Aam;
        m_Adr=ddr*m_Adm;
        rss=rs(1.0);
        cout<<"rss="<<rss<<::endl;
    }

    if(abs(rv(1.0))>0.0001){
        GetAm();
    }
    m_Vm=v4(m_T[4]);
    cout<<"vm="<<m_Vm<<::endl;
}


void RCurve::GetRCurve()
{
    for(double t=0;t<=1.0;t+=0.0001)
    {
        double s=rs(t);
        double v=rv(t);
        double a=ra(t);
        double j=rj(t);

        m_SCurve<<QPointF(t,s);
        m_VCurve<<QPointF(t,v);
        m_ACurve<<QPointF(t,a);
        m_JCurve<<QPointF(t,j);

        m_Vm=max(m_Vm,v);

        m_JmMin=min(m_JmMin,j);
        m_JmMax=max(m_JmMax,j);

        m_Qm=max(m_Qm,abs(a*v));

    }
}


