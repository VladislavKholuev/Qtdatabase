#ifndef SECONDLEVEL_H
#define SECONDLEVEL_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlField>
#include <QSqlRecord>

class secondlevel
{
public:
    secondlevel();
    QSqlQuery getAllInfo(QString str);
    QSqlQuery getcityInfo(QString str, QString city);
};

#endif // SECONDLEVEL_H
