#ifndef REPORT_H
#define REPORT_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlField>
#include <QSqlRecord>

class report
{
public:
    report();
    QSqlQuery getAllInfo(QString str,QString year);
    QSqlQuery getreportAllInfo(QString str,QString year);
    QSqlQuery getcityInfo(QString str, QString city,QString year);
    QSqlQuery getreportcityInfo(QString str,QString city,QString year);
};

#endif // REPORT_H
