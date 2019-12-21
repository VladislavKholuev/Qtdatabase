#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QBrush br(QImage("C:/Qt/kursach/pic.jpg"));
    this->setWindowTitle("Булгарнефть");
    QImage background("C:/Qt/kursach/1.jpg");
    background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
    enum Color1 { red = -1, green, blue };
    qDebug()<< Color1(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString connectString = "Driver={SQL Server};";                     // Driver is now {SQL Server Native Client 11.0}
    connectString.append("Server=VLAD\\SQLEXPRESS;");   // Hostname,SQL-Server Instance
    connectString.append("Database=db_kursach;");  // Schema
    connectString.append("");           // User
    connectString.append("");           // Pass
    db.setDatabaseName(connectString);
    db.setDatabaseName(connectString);
    if(!db.open())
    {
    qDebug()<<"ERROR: "<<db.lastError();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ошибка авторизации");
    msgBox.setText("Подключения больше нет...");
    msgBox.exec();
    }
    else
    {

        QSqlQuery *query = new QSqlQuery();

        int canIgo=0;
        query->prepare("Select dbo.go_Into(?,?)");
        query->bindValue(0,ui->lineEdit->text());
        query->bindValue(1,ui->lineEdit_2->text());
        if(query->exec()){
        while(query->next()){
        const auto currRecord = query->record();
        for(int i=0;i<currRecord.count();++i)
        canIgo = currRecord.value(0).toInt();
        }
        }


        if(canIgo !=0){

            setId(canIgo);
            in_signal();
            this->close();
        }
        else{
            db.close();
            qApp->setStyleSheet("QMessageBox QPushButton { color: white; background-color: gray;} "
                                "QMessageBox {background-color: black} "
                                "QMessageBox QLabel{ padding-right:15px;border-radius:6px;font:Times New Roman ;font-size:15px;color: white;}");

            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка авторизации");
            msgBox.setText("Неверный логин или пароль");
            msgBox.exec();
        }

    }

}
