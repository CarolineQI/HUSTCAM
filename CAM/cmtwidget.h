#ifndef CMTWIDGET_H
#define CMTWIDGET_H

#include <QWidget>

namespace Ui {
class CMTWidget;
}



class CMTWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CMTWidget(QWidget *parent = nullptr);
    ~CMTWidget();

private slots:


    void on_modeNextButton_clicked();

    void on_camModeNextButton_clicked();

    void on_pChoiceTableWidget_cellActivated(int row, int column);

private:
    Ui::CMTWidget *ui;
    
    

};

#endif // CMTWIDGET_H
