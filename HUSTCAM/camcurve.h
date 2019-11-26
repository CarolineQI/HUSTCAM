#ifndef CAMCURVE_H
#define CAMCURVE_H
#include<QString>
#include<QPointF>
class CamCurve
{
public:
    CamCurve();
    int m_id;
    QString m_name;
private:
    QPointF* m_baseCurve;
};

#endif // CAMCURVE_H
