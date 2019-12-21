#include "firstlevel.h"
#include <QDebug>

firstLevel::firstLevel()
{

}

QSqlQuery firstLevel::getAllInfo(QString str){
    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    if(str == "Объекты")
        query->prepare("SELECT * FROM GetObject()");
    if(str=="Персонал")
        query->prepare("SELECT * FROM GetZeroPersonal()");
    if(str=="Добыча")
        query->prepare("SELECT * FROM GetZeroDobycha()");
    if(str=="Закачка воды")
        query->prepare("SELECT * FROM GetZeroWater()");
    query->exec();
    if(query->exec()){
    while(query->next()){
    const auto currRecord = query->record();
    for(int i=0;i<currRecord.count();++i)
    qDebug() << currRecord.field(i) << ": " << currRecord.value(0).toString();
    }
    }
    return *query;
}

QSqlQuery firstLevel::getcityInfo(QString str, QString city){
    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    if(str == "Объекты")
    {
        query->prepare("SELECT * FROM GetcityObject(?)");
        query->bindValue(0,city);
    }
    if(str=="Персонал"){
        query->prepare("SELECT * FROM GetcityZeroPersonal(?)");
        query->bindValue(0,city);
    }
    if(str=="Добыча"){
        query->prepare("SELECT * FROM GetcityZeroDobycha(?)");
        query->bindValue(0,city);
    }
    if(str=="Закачка воды"){
        query->prepare("SELECT * FROM GetcityZeroWater(?)");
        query->bindValue(0,city);
    }
    query->exec();
    if(query->exec()){
    while(query->next()){
    const auto currRecord = query->record();
    for(int i=0;i<currRecord.count();++i)
    qDebug() << currRecord.field(i) << ": " << currRecord.value(0).toString();
    }
    }
    return *query;
}
