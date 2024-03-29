#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QDebug"
#include "QtSql/QSqlError"
#include <QtSql/QSqlQuery>
//#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QtSql/QSqlRecord>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setId(int idd){id = idd;}
    int getId(){return id;}

signals:
    void in_signal();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    int id;
//    Work *windowWork;
};
#endif // MAINWINDOW_H
