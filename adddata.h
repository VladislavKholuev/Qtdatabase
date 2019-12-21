#ifndef ADDDATA_H
#define ADDDATA_H

#include <QWidget>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QVector>

namespace Ui {
class addData;
}

class addData : public QWidget
{
    Q_OBJECT

public:
    explicit addData(QWidget *parent = nullptr);
    ~addData();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::addData *ui;
};

#endif // ADDDATA_H
