#include "adddata.h"
#include "ui_adddata.h"
#include <QDebug>
addData::addData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addData)
{
    ui->setupUi(this);
    QSqlQuery* query = new QSqlQuery();
    ui->comboBox->addItem("Добыча");
    ui->comboBox->addItem("Закачка воды");
    query->prepare("Select * FROM GetCDNG()");
    if(query->exec()){
        while(query->next()){
        const auto currRecord = query->record();
        for(int i=0;i<currRecord.count();++i)
            qDebug()<<currRecord.value(0).toString();
            ui->comboBox_2->addItem(currRecord.value(0).toString());
        }
    }
}

addData::~addData()
{
    delete ui;
}

void addData::on_pushButton_clicked()
{
    bool ok = true;
  QVector<QString> vecDate;
   QSqlQuery* log = new QSqlQuery();

  if(ui->comboBox->currentText() == "Добыча")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getOilProdDates(?)");
    getdata->bindValue(0,ui->comboBox_2->currentText());
    if(getdata->exec())
    {
        while(getdata->next())
        {
            const auto currRecord = getdata->record();
            for(int i=0;i<currRecord.count();++i){
                qDebug() <<currRecord.value(0).toString();
                QString str = currRecord.value(0).toString();
                str.remove("-");
                str.remove(6,2);
                qDebug()<<str;
                vecDate.append(str);
            }
       }
    }
  }
  if(ui->comboBox->currentText() == "Закачка воды")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getWaterInjectDates(?)");
    getdata->bindValue(0,ui->comboBox_2->currentText());
    if(getdata->exec())
    {
        while(getdata->next())
        {
            const auto currRecord = getdata->record();
            for(int i=0;i<currRecord.count();++i){
                qDebug() <<currRecord.value(0).toString();
                QString str = currRecord.value(0).toString();
                str.remove("-");
                str.remove(6,2);
                qDebug()<<str;
                vecDate.append(str);
            }
       }
    }
  }
    qDebug()<<vecDate;
    qDebug()<<ui->comboBox->currentText();
  if(vecDate.contains(ui->lineEdit_2->text().remove(5,2)))
  {
      QMessageBox *mes = new QMessageBox();
      mes->setText("В этом месяце уже была отчетность");
      mes->show();

  }else{

  bool ok1 = true;
  bool ok2 = true;
  bool ok3 =true;
  bool ok4 = true;
  ui->lineEdit_2->text().toInt(&ok1);
  ui->lineEdit_3->text().toInt(&ok2);
  ui->lineEdit_4->text().toInt(&ok3);
  ui->lineEdit_5->text().toInt(&ok4);
  qDebug()<<(ok1&&ok2&&ok3&&ok4);

  QSqlQuery* query = new QSqlQuery();
  if(ui->comboBox->currentText() == "Добыча" &&ok1&&ok2&&ok3&&ok4){
  query->prepare("{CALL addOilProd(?,?,?,?,?)}");
  query->bindValue(0, ui->comboBox_2->currentText());
  query->bindValue(1,ui->lineEdit_2->text());
  query->bindValue(2,abs(ui->lineEdit_3->text().toInt()));
  query->bindValue(3,abs(ui->lineEdit_4->text().toInt()));
  query->bindValue(4,abs(ui->lineEdit_5->text().toInt()));
  }
  if(ui->comboBox->currentText()=="Закачка воды"&&ok1&&ok2&&ok3&&ok4){
      query->prepare("{CALL addWaterInject(?,?,?,?,?)}");
      query->bindValue(0, ui->comboBox_2->currentText());
      query->bindValue(1,ui->lineEdit_2->text());
      query->bindValue(2,abs(ui->lineEdit_3->text().toInt()));
      query->bindValue(3,abs(ui->lineEdit_4->text().toInt()));
      query->bindValue(4,abs(ui->lineEdit_5->text().toInt()));
  }
  if(query->exec()){
      qDebug()<<"ok";
      QMessageBox *mes = new QMessageBox();
      mes->setText("запись добавлена");
      mes->show();
      log->prepare("{CALL addlog(?,?)}");
      log->bindValue(0,ui->lineEdit_2->text());
      log->bindValue(1,ui->comboBox->currentText()+" " + ui->comboBox_2->currentText() +" "+
                     ui->lineEdit_3->text()+" " + ui->lineEdit_4->text()+" " + ui->lineEdit_5->text());
      log->exec();
      this->close();
  }
  else{
      QString str;
      if(!ok1 && ui->lineEdit_2->text().size() != 8)
          str +="\n ошибка в дате проверьте запись (ггггммдд) \n или в этом месяце уже была отчетность";
      if(!ok2)
          str +="\n ошибка в строке норма ";
      if(!ok3)
          str +="\n ошибка в строке план ";
      if(!ok4)
          str +="\n ошибка в строке факт ";
      QMessageBox *mes = new QMessageBox();
      mes->setText("ошибка в добавлении"+str);
      mes->show();
  }
  }
}

void addData::on_pushButton_2_clicked()
{
    bool ok = true;
  QVector<QString> vecDate;
  QSqlQuery* log = new QSqlQuery();

  if(ui->comboBox->currentText() == "Добыча")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getOilProdDates(?)");
    getdata->bindValue(0,ui->comboBox_2->currentText());
    if(getdata->exec())
    {
        while(getdata->next())
        {
            const auto currRecord = getdata->record();
            for(int i=0;i<currRecord.count();++i){
                qDebug() <<currRecord.value(0).toString();
                QString str = currRecord.value(0).toString();
                str.remove("-");
                str.remove(6,2);
                qDebug()<<str;
                vecDate.append(str);
            }
       }
    }
  }
  if(ui->comboBox->currentText() == "Закачка воды")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getWaterInjectDates(?)");
    getdata->bindValue(0,ui->comboBox_2->currentText());
    if(getdata->exec())
    {
        while(getdata->next())
        {
            const auto currRecord = getdata->record();
            for(int i=0;i<currRecord.count();++i){
                qDebug() <<currRecord.value(0).toString();
                QString str = currRecord.value(0).toString();
                str.remove("-");
                str.remove(6,2);
                qDebug()<<str;
                vecDate.append(str);
            }
       }
    }
  }
    qDebug()<<vecDate;
    qDebug()<<ui->comboBox->currentText();
    if(vecDate.contains(ui->lineEdit_2->text().remove(5,2)))
    {
        bool ok1 = true;
        bool ok2 = true;
        bool ok3 =true;
        bool ok4 = true;
        ui->lineEdit_2->text().toInt(&ok1);
        ui->lineEdit_3->text().toInt(&ok2);
        ui->lineEdit_4->text().toInt(&ok3);
        ui->lineEdit_5->text().toInt(&ok4);
        qDebug()<<(ok1&&ok2&&ok3&&ok4);

        QSqlQuery* query = new QSqlQuery();
        if(ui->comboBox->currentText() == "Добыча" &&ok1&&ok2&&ok3&&ok4){
        query->prepare("{CALL updateOilProd(?,?,?,?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit_2->text());
        query->bindValue(2,abs(ui->lineEdit_3->text().toInt()));
        query->bindValue(3,abs(ui->lineEdit_4->text().toInt()));
        query->bindValue(4,abs(ui->lineEdit_5->text().toInt()));
        }
        if(ui->comboBox->currentText()=="Закачка воды"&&ok1&&ok2&&ok3&&ok4){
            query->prepare("{CALL updateWaterInject(?,?,?,?,?)}");
            query->bindValue(0, ui->comboBox_2->currentText());
            query->bindValue(1,ui->lineEdit_2->text());
            query->bindValue(2,abs(ui->lineEdit_3->text().toInt()));
            query->bindValue(3,abs(ui->lineEdit_4->text().toInt()));
            query->bindValue(4,abs(ui->lineEdit_5->text().toInt()));
        }
        if(query->exec()){
            qDebug()<<"ok";
            QMessageBox *mes = new QMessageBox();
            mes->setText("запись добавлена");
            mes->show();
            log->prepare("{CALL addlog(?,?)}");
            log->bindValue(0,ui->lineEdit_2->text());
            log->bindValue(1,ui->comboBox->currentText()+" " + ui->comboBox_2->currentText() +" "+
                           ui->lineEdit_3->text()+" " + ui->lineEdit_4->text()+" " + ui->lineEdit_5->text());
            log->exec();
            this->close();
        }
        else{
            QString str;
            if(!ok1 && ui->lineEdit_2->text().size() != 8)
                str +="\n ошибка в дате проверьте запись (ггггммдд) \n или в этом месяце уже была отчетность";
            if(!ok2)
                str +="\n ошибка в строке норма ";
            if(!ok3)
                str +="\n ошибка в строке план ";
            if(!ok4)
                str +="\n ошибка в строке факт ";
            QMessageBox *mes = new QMessageBox();
            mes->setText("ошибка в добавлении"+str);
            mes->show();
        }
    }else{
        QMessageBox *mes = new QMessageBox();
        mes->setText("В этом месяце не было отчетности");
        mes->show();
    }
}

void addData::on_pushButton_3_clicked()
{
    bool ok = true;
  QVector<QString> vecDate;
  QSqlQuery* log = new QSqlQuery();

  if(ui->comboBox->currentText() == "Добыча")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getOilProdDates(?)");
    getdata->bindValue(0,ui->comboBox_2->currentText());
    if(getdata->exec())
    {
        while(getdata->next())
        {
            const auto currRecord = getdata->record();
            for(int i=0;i<currRecord.count();++i){
                qDebug() <<currRecord.value(0).toString();
                QString str = currRecord.value(0).toString();
                str.remove("-");
                str.remove(6,2);
                qDebug()<<str;
                vecDate.append(str);
            }
       }
    }
  }
  if(ui->comboBox->currentText() == "Закачка воды")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getWaterInjectDates(?)");
    getdata->bindValue(0,ui->comboBox_2->currentText());
    if(getdata->exec())
    {
        while(getdata->next())
        {
            const auto currRecord = getdata->record();
            for(int i=0;i<currRecord.count();++i){
                qDebug() <<currRecord.value(0).toString();
                QString str = currRecord.value(0).toString();
                str.remove("-");
                str.remove(6,2);
                qDebug()<<str;
                vecDate.append(str);
            }
       }
    }
  }
    qDebug()<<vecDate;
    qDebug()<<ui->comboBox->currentText();
    if(vecDate.contains(ui->lineEdit_2->text().remove(5,2)))
    {
        bool ok1 = true;

        ui->lineEdit_2->text().toInt(&ok1);

        qDebug()<<(ok1);

        QSqlQuery* query = new QSqlQuery();
        if(ui->comboBox->currentText() == "Добыча" &&ok1){
        query->prepare("{CALL deleteOilProd(?,?,?,?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit_2->text());

        }
        if(ui->comboBox->currentText()=="Закачка воды"&&ok1){
            query->prepare("{CALL deleteWaterInject(?,?,?,?,?)}");
            query->bindValue(0, ui->comboBox_2->currentText());
            query->bindValue(1,ui->lineEdit_2->text());

        }
        if(query->exec()){
            qDebug()<<"ok";
            QMessageBox *mes = new QMessageBox();
            mes->setText("запись удалена");
            mes->show();
            log->prepare("{CALL addlog(?,?)}");
            log->bindValue(0,ui->lineEdit_2->text());
            log->bindValue(1,ui->comboBox->currentText()+" " + ui->comboBox_2->currentText() +" "+
                           ui->lineEdit_3->text()+" " + ui->lineEdit_4->text()+" " + ui->lineEdit_5->text());
            log->exec();
            this->close();
        }
        else{
            QString str;
            if(!ok1 && ui->lineEdit_2->text().size() != 8)
                str +="\n ошибка в дате проверьте запись (ггггммдд) \n или в этом месяце уже была отчетность";

            QMessageBox *mes = new QMessageBox();
            mes->setText("ошибка в добавлении"+str);
            mes->show();
        }
    }else{
        QMessageBox *mes = new QMessageBox();
        mes->setText("В этом месяце не было отчетности");
        mes->show();
    }
}
