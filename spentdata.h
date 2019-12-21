#ifndef SPENTDATA_H
#define SPENTDATA_H

#include <QWidget>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QVector>

namespace Ui {
class spentdata;
}

class spentdata : public QWidget
{
    Q_OBJECT

public:
    explicit spentdata(QWidget *parent = nullptr);
    ~spentdata();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::spentdata *ui;
};

#endif // SPENTDATA_H
