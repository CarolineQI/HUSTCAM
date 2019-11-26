#ifndef CMTWIDGET_H
#define CMTWIDGET_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlRelationalTableModel>
#include<QErrorMessage>
#include<QMessageBox>
#include<QSqlRecord>
namespace Ui {
class CMTWidget;
}

class TableModel:public QSqlRelationalTableModel{
public:
    explicit TableModel(QObject* parent = nullptr,QSqlDatabase db=QSqlDatabase());
    ~TableModel() override = default;
    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;
};


class CMTWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CMTWidget(QWidget *parent = nullptr);
    ~CMTWidget();

    inline int getCamMechType(){
        return m_camMech;
    }
private slots:

//modepage
    void on_choiceModeButton_clicked();

    void on_customModeButton_clicked();

    void on_modeNextButton_clicked();
//modepage

//cammodepage
    void on_planeCamButton_clicked();

    void on_spaceCamButton_clicked();

    void on_camModeNextButton_clicked();

    void on_camModeReturnButton_clicked();

    //pChoicepage
    void on_pChoiceReturnButton_clicked();

    void on_pChoiceSureButton_clicked();
    //pChoicepage

//cammodepage

    void on_pChoiceTableView_clicked(const QModelIndex &index);

private:
    Ui::CMTWidget *ui;
    enum class Mode{choice, custom, none};
    enum class CamMechType{plane,space,none};

    Mode m_mode;
    CamMechType m_camMechType;

    QSqlRelationalTableModel* m_pChoiceTableModel;
    bool m_isReturnClear;//返回上一步的处理模式，保留原记录或者清空原纪录
    bool m_isCustomModeUsed;
    bool m_isSpaceTypeUsed;

    int m_camMech;
    bool m_isCamMechCheck;

signals:
    void  sendCamMechData(int);
    
};

#endif // CMTWIDGET_H
