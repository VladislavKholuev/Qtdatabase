#include "secondlevel.h"
#include <QDebug>
secondlevel::secondlevel()
{

}

QSqlQuery secondlevel::getAllInfo(QString str){
    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    if(str == "Объекты")
        query->prepare("SELECT * FROM GetObject()");
    if(str=="Персонал")
        query->prepare("SELECT * FROM GetMorePersonal()");
    if(str=="Добыча")
        query->prepare("SELECT * FROM GetZeroDobycha()");
    if(str=="Закачка воды")
        query->prepare("SELECT * FROM GetZeroWater()");
    if(str=="Электроэнергия")
        query->prepare("SELECT * FROM GetZeroElectro()");

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

QSqlQuery secondlevel::getcityInfo(QString str, QString city){
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
    if(str=="Электроэнергия"){
        query->prepare("SELECT * FROM GetcityZeroElectro(?)");
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
