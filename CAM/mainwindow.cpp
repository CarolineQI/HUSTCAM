#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QImage>
#include<QLabel>
#include<QIcon>
#include<QListWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setWindowTitle("HUST CAD");
//    setWindowIcon(QIcon(":/cam/resource/HUST.png"));
    creatFileWindow();
    //menuWidget

    ui->stackedWidget->setCurrentIndex(1);
    ui->menuTabWidget->setCurrentWidget(ui->Begin);
    connect(ui->buildButton,&QPushButton::clicked,this,&MainWindow::newFile);
    CamMechanismTypeWidget=new CMTWidget;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileStackWidgetChange(int id)
{
   ui->fileStackedWidget->setCurrentIndex(id); 
//   ui->fileButtonListWidget->currentItem()->setBackgroundColor(QColor(226, 226, 226));

}
void MainWindow::newFile()
{


    MdiChildWindow *child = createMdiChild();
    child->resize(400,400);
    child->setWindowModality(Qt::WindowModal);
    child->newFile();
    child->show();
}

void MainWindow::returnButtonPressed()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->fileStackedWidget->setCurrentIndex(0);
    setCurrentIndex();
}


MdiChildWindow* MainWindow::createMdiChild()
{
    MdiChildWindow *child = new MdiChildWindow(itemMenu);
    ui->mdiArea->addSubWindow(child);
    return child;
}

QListWidgetItem* MainWindow::creatFileWindowButton
(const QString &text, const QString &image, int& buttonId)
{
    static int i=0;
    QListWidgetItem* item=new QListWidgetItem;
    item->setSizeHint(fileButtonSize);
    item->setIcon(QIcon(QPixmap(image)));
    item->setToolTip(text);
    ui->fileButtonListWidget->addItem(item);
    buttonId=i++;
    return item;
}

void MainWindow::creatFileWindow()
{

    //![0] main
//     ui->returnPushButton->setStyleSheet("QPushButton{background-color:rgb(230, 230,230);}");
//     ui->returnPushButton->setIconSize(QSize(100,100));
//     ui->returnPushButton->setIcon(QIcon(":/cam/resource/start(gray)/return.png"));
//     ui->returnPushButton->setCheckable(true);
//     ui->returnPushButton->setToolTip("Return To MainWindow");
      creatFileWindowButton(tr("Quick Operating"),":/cam/resource/file/start.png",beginButton);
      creatFileWindowButton(tr("Build New File"),":/cam/resource/file/newfile.png", newFileButton);
      creatFileWindowButton(tr("Open File"),":/cam/resource/file/openfile.png",openFileButton);
      connect(ui->returnPushButton,SIGNAL(pressed()),this,SLOT(returnButtonPressed()));
      connect(ui->fileButtonListWidget,SIGNAL(currentRowChanged(int)),this,SLOT(fileStackWidgetChange(int)));
      ui->fileButtonListWidget->setIconSize(fileButtonSize);
      ui->fileButtonListWidget->setStyleSheet(
                  "QListWidget::Item:hover{background:lightgray; }"
                  "QListWidget::item:selected{background-color:rgb(230, 230,230);}"
                  );
      //![0]

}

void MainWindow::createMenus()
{
    itemMenu=menuBar()->addMenu(tr("Item"));
   // itemMenu->addAction();
//    itemMenu->addSeparator();
}


void MainWindow::setCurrentIndex()
{
    ui->menuTabWidget->setCurrentIndex(lastTadIndex);
}


void MainWindow::on_CamMechanismType_clicked()
{
    CamMechanismTypeWidget->show();
}

void MainWindow::on_menuTabWidget_tabBarClicked(int index)
{
    lastTadIndex=ui->menuTabWidget->currentIndex();
    if(index==0)
    {
        ui->fileStackedWidget->setCurrentWidget(ui->beginFilePage);
        ui->stackedWidget->setCurrentWidget(ui->filePage);
    }
}
