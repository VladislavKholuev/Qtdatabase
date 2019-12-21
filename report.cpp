  #include "report.h"
#include <QDebug>
#include <QMessageBox>
report::report()
{

}

QSqlQuery report::getAllInfo(QString str, QString year){
    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    if(str=="Добыча"){//+
        query->prepare("SELECT * FROM GetrepDobycha(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str=="Закачка воды"){//+
        query->prepare("SELECT * FROM GetrepWater(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str=="Электроэнергия"){//+
        query->prepare("SELECT * FROM GetrepElectro(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Расходы ЖКХ"){//+
        query->prepare("SELECT * FROM GetrepJKH(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Тепло"){//+
        query->prepare("SELECT * FROM GetrepHeat(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Газ"){//+
        query->prepare("SELECT * FROM GetrepGas(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Вода"){//+
        query->prepare("SELECT * FROM GetrepjkhWater(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    query->exec();
    if(!query->exec()){
        QMessageBox *mes = new QMessageBox();
        mes->setText("такого отчета нет");
        mes->show();
    }
    return *query;
}


QSqlQuery report::getcityInfo(QString str, QString city,QString year){

    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    if(str=="Добыча"){//+
        query->prepare("SELECT * FROM GetrepcityDobycha(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str=="Закачка воды"){//+
        query->prepare("SELECT * FROM GetrepcityWater(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str=="Электроэнергия"){//+
        query->prepare("SELECT * FROM GetrepcityElectro(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Расходы ЖКХ"){//+
        query->prepare("SELECT * FROM GetrepcityAllJKH(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Тепло"){//+
        query->prepare("SELECT * FROM GetrepcityJkhHeat(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Газ"){//+
        query->prepare("SELECT * FROM GetrepcityJkhGas(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Вода"){//+
        query->prepare("SELECT * FROM GetrepcityJkhWater(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    query->exec();
    if(!query->exec()){
        QMessageBox *mes = new QMessageBox();
        mes->setText("такого отчета нет");
        mes->show();
    }

    return *query;

}

QSqlQuery report::getreportAllInfo(QString str, QString year){
    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    if(str=="Добыча"){//+
        query->prepare("SELECT * FROM reportDobycha(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str=="Закачка воды"){//+
        query->prepare("SELECT * FROM reportInjectWater(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str=="Электроэнергия"){//+
        query->prepare("SELECT * FROM reportElectro(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Расходы ЖКХ"){//+
        query->prepare("SELECT * FROM reportJKH(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Тепло"){//+
        query->prepare("SELECT * FROM reportHeat(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Газ"){//
        query->prepare("SELECT * FROM reportGas(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    if(str == "Вода"){//+
        query->prepare("SELECT * FROM reportjkhWater(?,?)");
        query->bindValue(0,year+"0101");
        query->bindValue(1,year+"1231");
    }
    query->exec();
    if(!query->exec()){
        QMessageBox *mes = new QMessageBox();
        mes->setText("такого отчета нет");
        mes->show();
    }
    return *query;
}


QSqlQuery report::getreportcityInfo(QString str, QString city, QString year){

    QSqlQueryModel model;// = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    if(str=="Добыча"){//+
        query->prepare("SELECT * FROM reportcityDobycha(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str=="Закачка воды"){//+
        query->prepare("SELECT * FROM reportcityWater(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str=="Электроэнергия"){//+
        query->prepare("SELECT * FROM reportcityElectro(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Расходы ЖКХ"){//+
        query->prepare("SELECT * FROM reportcityAllJKH(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Тепло"){//+
        query->prepare("SELECT * FROM reportcityJkhHeat(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Газ"){//+
        query->prepare("SELECT * FROM reportcityJkhGas(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    if(str == "Вода"){//
        query->prepare("SELECT * FROM reportcityJkhWater(?,?,?)");
        query->bindValue(0,city);
        query->bindValue(1,year+"0101");
        query->bindValue(2,year+"1231");
    }
    query->exec();
    if(!query->exec()){
        QMessageBox *mes = new QMessageBox();
        mes->setText("такого отчета нет");
        mes->show();
    }

    return *query;

}
