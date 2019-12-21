#include "thirdlevel.h"
#include <QDebug>
thirdlevel::thirdlevel()
{

}

QSqlQuery thirdlevel::getAllInfo(QString str){
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
    if(str == "Расходы ЖКХ")
        query->prepare("SELECT * FROM GetAllJKH()");
    if(str == "Тепло")
        query->prepare("SELECT * FROM GetJkhHeat()");
    if(str == "Газ")
        query->prepare("SELECT * FROM GetJkhGas()");
    if(str == "Вода")
        query->prepare("SELECT * FROM GetJkhWater()");
    if(str=="Логи")
        query->prepare("SELECT * FROM Getlogs()");
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


QSqlQuery thirdlevel::getcityInfo(QString str, QString city){

    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    if(str == "Объекты")
    {
        query->prepare("SELECT * FROM GetcityObject(?)");
        query->bindValue(0,city);
    }
    if(str=="Персонал"){
        query->prepare("SELECT * FROM GetcityMorePersonal(?)");
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
    if(str == "Расходы ЖКХ"){
        query->prepare("SELECT * FROM GetcityAllJKH(?)");
        query->bindValue(0,city);
    }
    if(str == "Тепло"){
        query->prepare("SELECT * FROM GetcityJkhHeat(?)");
        query->bindValue(0,city);
    }
    if(str == "Газ"){
        query->prepare("SELECT * FROM GetcityJkhGas(?)");
        query->bindValue(0,city);
    }
    if(str == "Вода"){
        query->prepare("SELECT * FROM GetcityJkhWater(?)");
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
