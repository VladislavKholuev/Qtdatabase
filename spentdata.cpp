#include "spentdata.h"
#include "ui_spentdata.h"
#include <QDebug>
spentdata::spentdata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::spentdata)
{
    ui->setupUi(this);
    QSqlQuery* query = new QSqlQuery();
    ui->comboBox->addItem("Электричество");
    ui->comboBox->addItem("Тепло");
    ui->comboBox->addItem("Газ");
    ui->comboBox->addItem("Вода");
    query->prepare("Select * FROM GetCities()");
    if(query->exec()){
        while(query->next()){
        const auto currRecord = query->record();
        for(int i=0;i<currRecord.count();++i)
            qDebug()<<currRecord.value(0).toString();
            ui->comboBox_2->addItem(currRecord.value(0).toString());
        }
    }
}

spentdata::~spentdata()
{
    delete ui;
}

void spentdata::on_pushButton_clicked()
{
  bool ok = true;
  QVector<QString> vecDate;
  QSqlQuery* log = new QSqlQuery();
  if(ui->comboBox->currentText() == "Электричество")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getElectroDates(?)");
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
  if(ui->comboBox->currentText() == "Тепло")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getHeatDates()");
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
  if(ui->comboBox->currentText() == "Газ")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getGasDates(?)");
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
  if(ui->comboBox->currentText() == "Вода")
  {
    QSqlQuery* getdata = new QSqlQuery();
    getdata->prepare("Select * FROM getWaterDates(?)");
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
  if(vecDate.contains(ui->lineEdit->text().remove(5,2)))
  {
      QMessageBox *mes = new QMessageBox();
      mes->setText("В этом месяце уже была отчетность");
      mes->show();

  }else{

  bool ok1 = true;
  bool ok2 = true;
  bool ok3 =true;

  ui->lineEdit->text().toInt(&ok1);
  ui->lineEdit_2->text().toInt(&ok2);
  ui->lineEdit_3->text().toInt(&ok3);
  qDebug()<<(ok1&&ok2&&ok3);

  QSqlQuery* query = new QSqlQuery();
  if(ui->comboBox->currentText() == "Электричество" &&ok1&&ok2&&ok3){
  query->prepare("{CALL addElectro(?,?,?,?)}");
  query->bindValue(0, ui->comboBox_2->currentText());
  query->bindValue(1,ui->lineEdit->text());
  query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
  query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));

  }
  if(ui->comboBox->currentText()=="Тепло"&&ok1&&ok2&&ok3){
      query->prepare("{CALL addHeat(?,?,?,?)}");
      query->bindValue(0, ui->comboBox_2->currentText());
      query->bindValue(1,ui->lineEdit->text());
      query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
      query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));

  }
  if(ui->comboBox->currentText()=="Газ"&&ok1&&ok2&&ok3){
      query->prepare("{CALL addGas(?,?,?,?)}");
      query->bindValue(0, ui->comboBox_2->currentText());
      query->bindValue(1,ui->lineEdit->text());
      query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
      query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));
  }
  if(ui->comboBox->currentText()=="Вода"&&ok1&&ok2&&ok3){
      query->prepare("{CALL addWater(?,?,?,?)}");
      query->bindValue(0, ui->comboBox_2->currentText());
      query->bindValue(1,ui->lineEdit->text());
      query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
      query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));
  }
  if(query->exec()){
      qDebug()<<"ok";
      QMessageBox *mes = new QMessageBox();
      mes->setText("запись добавлена");
      mes->show();
      log->prepare("{CALL addlog(?,?)}");
      log->bindValue(0,ui->lineEdit->text());
      log->bindValue(1,ui->comboBox->currentText()+" " + ui->comboBox_2->currentText() + " " +
                     ui->lineEdit->text() + " " + ui->lineEdit_2->text() + " " + ui->lineEdit_3->text());
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
      QMessageBox *mes = new QMessageBox();
      mes->setText("ошибка в добавлении"+str);
      mes->show();
  }
  }
}

void spentdata::on_pushButton_2_clicked()
{
    bool ok = true;
    QVector<QString> vecDate;
    QSqlQuery* log = new QSqlQuery();
    if(ui->comboBox->currentText() == "Электричество")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getElectroDates(?)");
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
    if(ui->comboBox->currentText() == "Тепло")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getHeatDates()");
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
    if(ui->comboBox->currentText() == "Газ")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getGasDates(?)");
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
    if(ui->comboBox->currentText() == "Вода")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getWaterDates(?)");
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
      qDebug()<<ui->lineEdit->text().remove(6,2);
    if(vecDate.contains(ui->lineEdit->text().remove(6,2)))
    {
qDebug()<<"here";
    bool ok1 = true;
    bool ok2 = true;
    bool ok3 =true;

    ui->lineEdit->text().toInt(&ok1);
    ui->lineEdit_2->text().toInt(&ok2);
    ui->lineEdit_3->text().toInt(&ok3);
    qDebug()<<(ok1&&ok2&&ok3);

    QSqlQuery* query = new QSqlQuery();
    if(ui->comboBox->currentText() == "Электричество" &&ok1&&ok2&&ok3){
    query->prepare("{CALL updateElectro(?,?,?,?)}");
    query->bindValue(0, ui->comboBox_2->currentText());
    query->bindValue(1,ui->lineEdit->text());
    query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
    query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));

    }
    if(ui->comboBox->currentText()=="Тепло"&&ok1&&ok2&&ok3){
        query->prepare("{CALL updateHeat(?,?,?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit->text());
        query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
        query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));

    }
    if(ui->comboBox->currentText()=="Газ"&&ok1&&ok2&&ok3){
        query->prepare("{CALL updateGas(?,?,?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit->text());
        query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
        query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));

    }
    if(ui->comboBox->currentText()=="Вода"&&ok1&&ok2&&ok3){
        query->prepare("{CALL updateWater(?,?,?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit->text());
        query->bindValue(2,abs(ui->lineEdit_2->text().toInt()));
        query->bindValue(3,abs(ui->lineEdit_3->text().toInt()));

    }
    if(query->exec()){
        qDebug()<<"ok";
        QMessageBox *mes = new QMessageBox();
        mes->setText("запись обновлена");
        mes->show();
        log->prepare("{CALL addlog(?,?)}");
        log->bindValue(0,ui->lineEdit->text());
        log->bindValue(1,ui->comboBox->currentText()+" " + ui->comboBox_2->currentText() + " " +
                       ui->lineEdit->text() + " " + ui->lineEdit_2->text() + " " + ui->lineEdit_3->text());
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
        QMessageBox *mes = new QMessageBox();
        mes->setText("ошибка в добавлении"+str);
        mes->show();
    }
    }else{
    QMessageBox *mes = new QMessageBox();
    mes->setText("В этом месяце не было записи");
    mes->show();
    }
}

void spentdata::on_pushButton_3_clicked()
{
    bool ok = true;
    QVector<QString> vecDate;
    QSqlQuery* log = new QSqlQuery();
    if(ui->comboBox->currentText() == "Электричество")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getElectroDates(?)");
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
    if(ui->comboBox->currentText() == "Тепло")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getHeatDates()");
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
    if(ui->comboBox->currentText() == "Газ")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getGasDates(?)");
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
    if(ui->comboBox->currentText() == "Вода")
    {
      QSqlQuery* getdata = new QSqlQuery();
      getdata->prepare("Select * FROM getWaterDates(?)");
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
      qDebug()<<ui->lineEdit->text().remove(6,2);
    if(vecDate.contains(ui->lineEdit->text().remove(6,2)))
    {
qDebug()<<"here";
    bool ok1 = true;

    ui->lineEdit->text().toInt(&ok1);

    qDebug()<<(ok1);

    QSqlQuery* query = new QSqlQuery();
    if(ui->comboBox->currentText() == "Электричество" &&ok1){
    query->prepare("{CALL deleteElectro(?,?)}");
    query->bindValue(0, ui->comboBox_2->currentText());
    query->bindValue(1,ui->lineEdit->text());

    }
    if(ui->comboBox->currentText()=="Тепло"&&ok1){
        query->prepare("{CALL deleteHeat(?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit->text());

    }
    if(ui->comboBox->currentText()=="Газ"&&ok1){
        query->prepare("{CALL deleteGas(?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit->text());

    }
    if(ui->comboBox->currentText()=="Вода"&&ok1){
        query->prepare("{CALL deleteWater(?,?)}");
        query->bindValue(0, ui->comboBox_2->currentText());
        query->bindValue(1,ui->lineEdit->text());

    }
    if(query->exec()){
        qDebug()<<"ok";
        QMessageBox *mes = new QMessageBox();
        mes->setText("запись удалена");
        mes->show();
        log->prepare("{CALL addlog(?,?)}");
        log->bindValue(0,ui->lineEdit->text());
        log->bindValue(1,ui->comboBox->currentText()+" " + ui->comboBox_2->currentText() + " " +
                       ui->lineEdit->text() + " " + ui->lineEdit_2->text() + " " + ui->lineEdit_3->text());
        log->exec();
        this->close();
    }
    else{
        QString str;
        if(!ok1 || ui->lineEdit->text().size() != 8)
            str +="\n ошибка в дате проверьте запись (ггггммдд) \n или в этом месяце уже была отчетность";

        QMessageBox *mes = new QMessageBox();
        mes->setText("ошибка в добавлении"+str);
        mes->show();
    }
    }else{
    QMessageBox *mes = new QMessageBox();
    mes->setText("В этом месяце не было записи");
    mes->show();
    }
}
