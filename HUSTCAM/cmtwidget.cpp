#include "cmtwidget.h"
#include "ui_cmtwidget.h"
#include<QSqlRelationalDelegate> //为QSqlRelationalTableModel显示和编辑数据
#include<QSqlQuery>
#include <QColor>
#include <QFont>
#include<QSqlRecord>
#include<QDebug>
#include<QString>


TableModel::TableModel(QObject *parent, QSqlDatabase db)
    :QSqlRelationalTableModel(parent,db)
{

}

QVariant TableModel::data(const QModelIndex &item, int role) const
{
    QVariant value  = QSqlRelationalTableModel::data(item,role);
       if(Qt::TextAlignmentRole == role)//控制对齐方式
       {
           value   = int(Qt::AlignCenter | Qt::AlignHCenter);
           return value;
       }
//       if(Qt::ForegroundRole == role)//控制前景色
//       {
//           if(3 == item.column())
//               return QVariant(QColor(255,144,144));
//       }
//       if(Qt::FontRole == role)//控制字体
//       {
//           if(3 == item.column())
//           {
//               QFont font;
//               font.setBold(true);
//               return QVariant(font);
//           }
//       }
       return value;
}

CMTWidget::CMTWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMTWidget)
{
    ui->setupUi(this);
    ui->CMTMainStackedWidget->setCurrentWidget(ui->modePage);
    ui->planeCamStackedWidget->setCurrentWidget(ui->modePage);
    m_mode=Mode::none;//未设定设计模式
    m_camMechType=CamMechType::none;//未设定凸轮机构类型
    m_isCamMechCheck=false;
    m_isReturnClear=true;
    m_isCustomModeUsed=false;
    m_isSpaceTypeUsed=false;

    m_pChoiceTableModel=new  TableModel(this);
    m_pChoiceTableModel->setTable("PlaneCamMechanism");//指定数据库表
    m_pChoiceTableModel->setRelation(3,QSqlRelation("Cam","id","type"));
    m_pChoiceTableModel->setRelation(4,QSqlRelation("Follower","id","type"));
    m_pChoiceTableModel->select();  //查询  等价于select * from PlaneCamMechanism

    m_pChoiceTableModel->removeColumn(2);
    m_pChoiceTableModel->removeColumn(4);
    m_pChoiceTableModel->setSort(0,Qt::AscendingOrder);
    m_pChoiceTableModel->setHeaderData(0,Qt::Horizontal,tr("编号") );
    m_pChoiceTableModel->setHeaderData(1,Qt::Horizontal,tr("凸轮机构类型") );
    m_pChoiceTableModel->setHeaderData(2,Qt::Horizontal,tr("主动件类型") );
    m_pChoiceTableModel->setHeaderData(3,Qt::Horizontal,tr("从动件类型") );
    m_pChoiceTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//设置编辑策略(手动提交)

    ui->pChoiceTableView->setModel(m_pChoiceTableModel);
    ui->pChoiceTableView->horizontalHeader()->setVisible(true);
    ui->pChoiceTableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);        //表头信息显示居中
    ui->pChoiceTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格属性只读，不能编辑
    ui->pChoiceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设定表头列宽自动拉伸
//    ui->pChoiceTableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);  //设定0表头列宽不可变

    ui->pChoiceTableView->setShowGrid(true);//背景网格线设置
    ui->pChoiceTableView->setGridStyle(Qt::SolidLine);    //网格背景画笔
    ui->pChoiceTableView->setSortingEnabled(false); //排序功能
    ui->pChoiceTableView->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选中时整行选中

}

CMTWidget::~CMTWidget()
{
    delete ui;
}

//modepage

void CMTWidget::on_choiceModeButton_clicked()
{
    ui->customModeButton->setChecked(false);
    if(m_mode==Mode::choice){
        ui->choiceModeButton->setChecked(false);
        m_mode=Mode::none;
    }else if(m_mode==Mode::none){
        ui->choiceModeButton->setChecked(true);
        m_mode=Mode::choice;
    }
}

void CMTWidget::on_customModeButton_clicked()
{
    if(!m_isCustomModeUsed){
        ui->choiceModeButton->setChecked(false);
        ui->customModeButton->setChecked(false);
        m_mode=Mode::none;
        QMessageBox::information(ui->CMTMainWidget,
                                 "此功能尚未开发",
                                 "自定义功能尚未开发，请等待更新！",
                                 QMessageBox::Ok);
        return;
    }
    ui->choiceModeButton->setChecked(false);
    if(m_mode==Mode::custom){
        ui->customModeButton->setChecked(false);
        m_mode=Mode::none;
    }else if(m_mode==Mode::none){
        ui->customModeButton->setChecked(true);
        m_mode=Mode::custom;
    }
}

void CMTWidget::on_modeNextButton_clicked()
{
    switch (m_mode) {
    case Mode::none:{
        QMessageBox::information(ui->CMTMainWidget,
                                 "提示：请选择设计模式",
                                 "您未选择设计模式，请在上方按钮中选择您需要的设计模式！",
                                 QMessageBox::Ok);
        return;
    }
    case Mode::choice:{
        ui->planeCamStackedWidget->setCurrentWidget(ui->pChoiceModePage);
        break;
    }
    case Mode::custom:{
        ui->planeCamStackedWidget->setCurrentWidget(ui->pCustomModePage);
        break;
    }
    }
    ui->CMTMainStackedWidget->setCurrentWidget(ui->camModePage);
}

//modepage


//cammodepage

void CMTWidget::on_planeCamButton_clicked()
{
    ui->spaceCamButton->setChecked(false);
    if(m_camMechType==CamMechType::plane){
        ui->planeCamButton->setChecked(false);
        m_camMechType=CamMechType::none;
    }else if(m_camMechType==CamMechType::none){
        ui->planeCamButton->setChecked(true);
        m_camMechType=CamMechType::plane;
    }
}


void CMTWidget::on_spaceCamButton_clicked()
{
    if(!m_isSpaceTypeUsed){
        ui->planeCamButton->setChecked(false);
        ui->spaceCamButton->setChecked(false);
        m_camMechType=CamMechType::none;
        QMessageBox::information(ui->CMTMainWidget,
                                 "此功能尚未开发",
                                 "空间凸轮部分功能尚未开发，请等待更新！",
                                 QMessageBox::Ok);
        return;
    }

    ui->planeCamButton->setChecked(false);
    if(m_camMechType==CamMechType::space){
        ui->spaceCamButton->setChecked(false);
        m_camMechType=CamMechType::none;
    }else if(m_mode==Mode::none){
        ui->spaceCamButton->setChecked(true);
        m_camMechType=CamMechType::space;
    }
}


void CMTWidget::on_camModeNextButton_clicked()
{
    switch (m_camMechType) {
    case CamMechType::none:{
        QMessageBox::information(ui->CMTMainWidget,
                                 "提示：请选择凸轮机构形态",
                                 "您未选择凸轮机构形态，请在上方按钮中选择您需要的凸轮机构形态！",
                                 QMessageBox::Ok);
        return;
    }
    case CamMechType::plane:{
        ui->CMTMainStackedWidget->setCurrentWidget(ui->planeCamPage);
        return;
    }
    case CamMechType::space:{
        ui->CMTMainStackedWidget->setCurrentWidget(ui->spaceCamPage);
        return;
    }
    }

}

void CMTWidget::on_camModeReturnButton_clicked()
{
    if(m_isReturnClear){
        ui->choiceModeButton->setChecked(false);
        ui->customModeButton->setChecked(false);
        m_mode=Mode::none;//未设定设计模式
    }

    ui->planeCamButton->setChecked(false);
    ui->spaceCamButton->setChecked(false);
    m_camMechType=CamMechType::none;//未设定凸轮机构类型

    ui->CMTMainStackedWidget->setCurrentWidget(ui->modePage);
}

    //pChoicepage
void CMTWidget::on_pChoiceReturnButton_clicked()
{
    if(m_isReturnClear){
        ui->planeCamButton->setChecked(false);
        ui->spaceCamButton->setChecked(false);
        m_camMechType=CamMechType::none;//未设定凸轮机构类型
    }
    ui->CMTMainStackedWidget->setCurrentWidget(ui->camModePage);
}

void CMTWidget::on_pChoiceSureButton_clicked()
{
    if(!m_isCamMechCheck){
        QMessageBox::information(ui->CMTMainWidget,
                                 "提示：请选择凸轮机构类型",
                                 "您未选择凸轮机构类型，请在上方表格中选择您需要的凸轮机构类型！",
                                 QMessageBox::Ok);
        return;
    }
    int curRow = ui->pChoiceTableView->currentIndex().row();
    QSqlRecord record = m_pChoiceTableModel->record(curRow);
    m_camMech=record.value("id").toInt();
    //test
    qDebug()<<"选择的凸轮机构的信息";
    qDebug()<<"编号"<<record.value(0).toString();
    qDebug()<<"类型"<<record.value(1).toString();
    qDebug()<<"主动件"<<record.value(2).toString();
    qDebug()<<"从动件"<<record.value(3).toString();
    //test

    QString camMechType=record.value(1).toString();
    QString camType=record.value(2).toString();
    QString folType=record.value(3).toString();
    QSqlQuery query;

//    主动运动
    query.exec(QString("select * from ActType where id = "
                       "(select actTypeId from Cam where type = \"%1\");").arg(camType));
    query.seek(0);
    QString camActType=query.value("name").toString();

    //test
    qDebug()<<"主动运动"<<camActType;
    //test
//    主动运动

//    从动运动
    query.exec(QString("select * from ActType where id = "
                       "(select actTypeId from Follower where type =\"%1\");").arg(folType));
    query.seek(0);
    QString folActType=query.value("name").toString();

    //test
    qDebug()<<"从动运动"<<folActType;
    //test
//    从动运动

    QString designResult=QString("您选择的凸轮机构类型为\"%1\"，其中凸轮为\"%2\"，"
                                 "从动件为\"%3\"，此凸轮机构将\"%4\"运动转化为\"%5\"运动。")
            .arg(camMechType).arg(camType).arg(folType).arg(camActType).arg(folActType);

    int ret=QMessageBox::question(ui->CMTMainWidget,"确认你的设计结果",
                                  designResult,QMessageBox::Yes,QMessageBox::No);
    if(ret==QMessageBox::Yes){//确认设计结果
        emit sendCamMechData(m_camMech);
        close();
    }
}
    //pChoicepage


//cammodepage


void CMTWidget::on_pChoiceTableView_clicked(const QModelIndex &index)
{
    m_isCamMechCheck=true;
    qDebug()<<QString("选中了编号为%1的凸轮机构").arg(index.row()+1);
}
