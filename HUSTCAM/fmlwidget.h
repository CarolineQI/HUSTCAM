#ifndef FMLWIDGET_H
#define FMLWIDGET_H

#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include <QGridLayout>
#include <QWidget>
#include "math.h"
#include "followmotionlaw.h"

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class FMLWidget;
}

class FMLWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FMLWidget(QWidget *parent = nullptr);
    ~FMLWidget();

private slots:

    void on_YDGCReturnButton_clicked();

    void on_YDGCNextButton_clicked();

    void on_ProDeReButton_clicked();


    void on_MNextButton_clicked();

private:
    Ui::FMLWidget *ui;
    QList<QPointF> *m_SCurveSeries;
    QList<QPointF> *m_VCurveSeries;
    QList<QPointF> *m_ACurveSeries;
    QList<QPointF> *m_JCurveSeries;
    QGridLayout* createCurveWidget(QList<QPointF>* points,QString chartTitle,double min,double max);

    FollowMotionLaw* m_FMLPoints;
    void updateCurve();
};

#endif // FMLWIDGET_H
