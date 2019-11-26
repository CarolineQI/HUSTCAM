#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QIcon>
#include<QPixmap>
#include<QMdiSubWindow>
#include<QAction>
#include<QToolBar>
#include<QToolButton>
#include<QButtonGroup>
#include<QStackedWidget>
#include<QMenu>
#include<QMenuBar>
#include<QMdiArea>

#include<QVBoxLayout>
#include<QGridLayout>

#include<QListWidgetItem>

#include"diagramscene.h"
#include"diagramitem.h"
#include"mdichildwindow.h"
#include"cmtwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
  //  void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;

private slots:

    void fileStackWidgetChange(int);
    void newFile();
    void returnButtonPressed();

//    void updateMenus();
//    void updateWindowMenus();



    void on_CamMechanismType_clicked();
    void on_menuTabWidget_tabBarClicked(int index);

    void getCamMechData(int camMechType);
    //data



    //data

private:
    Ui::MainWindow *ui;

    int  returnMainWindowButton;
    int  beginButton;
    int  newFileButton;
    int  openFileButton;
    QSize fileButtonSize=QSize(100,50);
    QStackedWidget* m_fileStackWidget;
    QButtonGroup* m_fileButtonGroup;

    void createMenus();

     QListWidgetItem*  creatFileWindowButton(const QString&text, const QString&image,int &buttonId);

     void creatFileWindow();
     MdiChildWindow* createMdiChild();

     // MdiChild* activeMdiChild();


    int lastTadIndex;
    void setCurrentIndex();

    QMenu* itemMenu;

    CMTWidget* CamMechanismTypeWidget;//凸轮机构类型窗口

   //********DATA***************
public:
        int m_camMechType;

   //********DATA***************
};
#endif // MAINWINDOW_H


