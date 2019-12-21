#ifndef WORK_H
#define WORK_H

#include <QWidget>
#include <mainwindow.h>
#include <ui_mainwindow.h>
#include "QtSql/QSqlDatabase"
#include "QDebug"
#include "QtSql/QSqlError"
#include <QtSql/QSqlQuery>
//#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QSortFilterProxyModel>
#include <QMenuBar>
#include <QAction>
#include <QtSql/QSqlRecord>
#include <QMessageBox>
#include <QSqlField>
#include <zerolevel.h>
#include <firstlevel.h>
#include <secondlevel.h>
#include <thirdlevel.h>
#include <fourthlevel.h>
#include <adddata.h>
#include <ui_adddata.h>
#include <spentdata.h>
#include <ui_spentdata.h>
#include <qsortfiltersqlquerymodel.h>
#include <report.h>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>

namespace Ui {
class Work;
}

class Work : public QWidget
{
    Q_OBJECT

public:
    explicit Work(QWidget *parent = nullptr,int id = 0);
    ~Work();
    void setName(QString Sname){name = Sname;}
    void setSurame(QString Surname){surname = Surname;}
    void setPriority(int Priority){ priority= Priority;}
    void setId(int Id){id = Id;}
    void setCity(QString c){city = c;}

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void ex();
    void GoIn();
    void on_allInfo_clicked();
    void opens();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



private:
    QString city;
    int id;
    QString name;
    QString surname;
    int priority;
    Ui::Work *ui;
    spentdata *spentdat;
    addData *data;
    QSqlQueryModel *model;
    MainWindow *InWindow;
    QString Report;
};

#endif // WORK_H
