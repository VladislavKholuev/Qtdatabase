#ifndef ZEROLEVEL_H
#define ZEROLEVEL_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class zeroLevel
{
//private:
//    QSqlQuery *query;
public:
    zeroLevel();
    QSqlQuery getAllInfo(QString str);
    QSqlQuery getcityInfo(QString str);

};

#endif // ZEROLEVEL_H
