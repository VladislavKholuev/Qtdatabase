#include "zerolevel.h"
#include <QDebug>
zeroLevel::zeroLevel()
{
}

QSqlQuery zeroLevel::getAllInfo(QString str){
    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    if(str == "Объекты")
        query->prepare("SELECT * FROM GetObject()");
    query->exec();
    qDebug()<<query->value(0)<<query->value(1);
    return *query;
}

QSqlQuery zeroLevel::getcityInfo(QString str){
    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
     query->prepare("SELECT * FROM GetcityObject(?)");
     qDebug()<<str;
     query->bindValue(0,str);
     query->exec();
     return *query;
}
