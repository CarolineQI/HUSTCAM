#include "cmtwidget.h"
#include "ui_cmtwidget.h"

CMTWidget::CMTWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMTWidget)
{
    ui->setupUi(this);
    ui->CMTMainStackedWidget->setCurrentWidget(ui->modePage);
    ui->planeCamStackedWidget->setCurrentWidget(ui->modePage);
}

CMTWidget::~CMTWidget()
{
    delete ui;
}




void CMTWidget::on_modeNextButton_clicked()
{
    ui->CMTMainStackedWidget->setCurrentWidget(ui->camModePage);
}

void CMTWidget::on_camModeNextButton_clicked()
{
    ui->CMTMainStackedWidget->setCurrentWidget(ui->modePage);
}
