#include "fmlwidget.h"
#include "ui_fmlwidget.h"

FMLWidget::FMLWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FMLWidget)
{
    ui->setupUi(this);
    QList<QPointF> listpoints;
    for (int i=0;i<=10;i++) {
        listpoints<<QPointF(i,10.0*sin(double(i)*0.2*M_PI));
    }

    ui->DRDView->setLayout(createCurveWidget(&listpoints,"DRD曲线"));
    ui->RDRView->setLayout(createCurveWidget(&listpoints,"RDR曲线"));
    ui->RRDView->setLayout(createCurveWidget(&listpoints,"RRD曲线"));
    ui->RRRView->setLayout(createCurveWidget(&listpoints,"RRR曲线"));

    m_SCurveSeries=&listpoints;
    m_VCurveSeries=&listpoints;
    m_ACurveSeries=&listpoints;
    m_JCurveSeries=&listpoints;
    updateCurve();


}

FMLWidget::~FMLWidget()
{
    delete ui;
}

QGridLayout* FMLWidget::createCurveWidget(QList<QPointF>* points,QString chartTitle)
{
    //![1]
    QSplineSeries *series = new QSplineSeries();
    series->setName("spline");
    //![1]

    //![2]
    series->append(*points);
    //![2]


    //![3]
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle(chartTitle);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(-10.05, 10.05);
    //![3]

    //![4]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //![4]

    //! [5]
    QGridLayout* layout=new QGridLayout;
    layout->addWidget(chartView);
    layout->setSpacing(0);
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(0);
    //! [5]

    return  layout;
}

void FMLWidget::updateCurve()
{
    ui->SCurveView->setLayout(createCurveWidget(m_SCurveSeries,"位移曲线"));
    ui->VCurveView->setLayout(createCurveWidget(m_VCurveSeries,"速度曲线"));
    ui->ACurveView->setLayout(createCurveWidget(m_ACurveSeries,"加速度曲线"));
    ui->JCurveView->setLayout(createCurveWidget(m_JCurveSeries,"跃度曲线"));
}


void FMLWidget::on_YDGCReturnButton_clicked()
{
    ui->DesignWidegt->setCurrentWidget(ui->ModePage);
}

void FMLWidget::on_YDGCNextButton_clicked()
{
    ui->DesignWidegt->setCurrentWidget(ui->ProDesign);
}



void FMLWidget::on_ProDeReButton_clicked()
{
    ui->DesignWidegt->setCurrentWidget(ui->YDGC);
}

void FMLWidget::on_MNextButton_clicked()
{
    ui->DesignWidegt->setCurrentWidget(ui->YDGC);
}
