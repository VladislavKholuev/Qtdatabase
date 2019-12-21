#ifndef FOURTHLEVEL_H
#define FOURTHLEVEL_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlField>
#include <QSqlRecord>

class fourthlevel
{
public:
    fourthlevel();
    QSqlQuery getAllInfo(QString str);
    QSqlQuery getcityInfo(QString str, QString city);
};

#endif // FOURTHLEVEL_H
