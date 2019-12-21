#ifndef THIRDLEVEL_H
#define THIRDLEVEL_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlField>
#include <QSqlRecord>

class thirdlevel
{
public:
    thirdlevel();
    QSqlQuery getAllInfo(QString str);
    QSqlQuery getcityInfo(QString str, QString city);
};

#endif // THIRDLEVEL_H
