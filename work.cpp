#include "work.h"
#include "ui_work.h"

Work::Work(QWidget *parent, int id) :
    QWidget(parent),
    ui(new Ui::Work)
{
    InWindow = new MainWindow();
    ui->setupUi(this);
    ui->allInfo->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);

    QObject::connect(InWindow, &MainWindow::in_signal, this, &Work::GoIn);

    QImage background("C:/Qt/kursach/3.jpg");
    background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
    QMenuBar  *menuBar = new QMenuBar(this);
    QMenu *Menu = menuBar->addMenu("Меню");
    menuBar->setFixedSize(60,20);
    QAction *exit = new QAction(tr("Выйти"), this);
    Menu->addAction(exit);
    connect(exit, SIGNAL(triggered()), this, SLOT(ex()));
    QAction *open = new QAction(tr("Авторизация"), this);
    Menu->addAction(open);
    connect(open, SIGNAL(triggered()), this, SLOT(opens()));
    InWindow->show();
}

Work::~Work()
{
    delete ui;
}

void Work::on_pushButton_clicked()
{

   if(priority>2)
   {
       spentdat =new spentdata();
       spentdat->show();
   }else{
       QMessageBox *mes = new QMessageBox();
       mes->setText("Доступ запрещен");
       mes->show();
   }
}

void Work::on_pushButton_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    if(priority>2)
    {
        data = new addData();
        data->show();
    }else{
        QMessageBox *mes = new QMessageBox();
        mes->setText("Доступ запрещен");
        mes->show();
    }
    QModelIndex myIndex;
    QVariant myData;
    myIndex = ui->tableView->model()->index(1,1,QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::DisplayRole);

    ui->tableView->setSortingEnabled(true);
    qDebug()<<myData.toString();

}

void Work::ex(){
    this->close();
}

void Work::GoIn(){
    this->show();
    int id = InWindow->getId();
    ui->allInfo->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT * FROM GetStartInfo(?)");
    query->bindValue(0,id);
    query->exec();
    qDebug()<<query->last();
    ui->label->setText(query->value(0).toString()+": "+query->value(1).toString()+" "+query->value(2).toString()+" "+query->value(3).toString()+" ");
    this->setPriority(query->value(4).toInt());
    this->setCity(query->value(5).toString());
    qDebug()<<this->city;
    qDebug()<<priority;
    QString s; s.setNum(priority);
    ui->label_2->setText("Ваш уровень доступа: " + s);

    qDebug()<<priority;
    qDebug()<<query->value(4).toString();
    ui->comboBox->addItem("Объекты");

    if(priority>0){

        ui->comboBox->addItem("Персонал");
    }
    if(priority>1){
        ui->comboBox->addItem("Добыча");
        ui->comboBox->addItem("Закачка воды");
        ui->comboBox->addItem("Электроэнергия");
    }
    if(priority>2)
    {
        ui->comboBox->addItem("Расходы ЖКХ");
        ui->comboBox->addItem("Тепло");
        ui->comboBox->addItem("Газ");
        ui->comboBox->addItem("Вода");
        ui->comboBox->addItem("Логи");
    }
    ui->comboBox->addItem("");
    query->clear();
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

void Work::on_allInfo_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    if(priority == 0){
        zeroLevel *z = new zeroLevel();
        query = z->getcityInfo(ui->comboBox_2->currentText());
    }
    if(priority ==1){
        firstLevel *z = new firstLevel();
        query = z->getcityInfo(ui->comboBox->currentText(),ui->comboBox_2->currentText());
    }
    if(priority == 2){
        secondlevel *z = new secondlevel();
        query = z->getcityInfo(ui->comboBox->currentText(),ui->comboBox_2->currentText());
    }
    if(priority == 3){
        thirdlevel *z = new thirdlevel();
        query = z->getcityInfo(ui->comboBox->currentText(),ui->comboBox_2->currentText());
    }
    if(priority == 4){
        fourthlevel *z = new fourthlevel();
        query = z->getcityInfo(ui->comboBox->currentText(),ui->comboBox_2->currentText());
    }

    model->setQuery(query);

    QSortFilterProxyModel * sort = new QSortFilterProxyModel();
    sort->setFilterKeyColumn(3);
    sort->setSourceModel(model);
    ui->tableView->setModel(sort);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionsClickable(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}


void Work::opens(){
    if(InWindow->close()){
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        InWindow->show();
    }
}

void Work::on_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    if(priority == 0){
        zeroLevel *z = new zeroLevel();
        query = z->getAllInfo(ui->comboBox->currentText());
    }
    if(priority ==1){
        firstLevel *z = new firstLevel();
        query = z->getAllInfo(ui->comboBox->currentText() );
    }
    if(priority == 2){
        secondlevel *z = new secondlevel();
        query = z->getAllInfo(ui->comboBox->currentText() );
    }
    if(priority == 3){
        thirdlevel *z = new thirdlevel();
        query = z->getAllInfo(ui->comboBox->currentText() );
    }
    if(priority == 4){
        fourthlevel *z = new fourthlevel();
        query = z->getAllInfo(ui->comboBox->currentText() );
    }
    model->setQuery(query);

    QSortFilterProxyModel * sort = new QSortFilterProxyModel();
    sort->setFilterKeyColumn(3);
    sort->setSourceModel(model);
    ui->tableView->setModel(sort);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionsClickable(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void Work::on_pushButton_3_clicked()
{//компания
    bool ok =true;
    ui->lineEdit->text().toInt(&ok);
    if(priority >2 && ok && ui->lineEdit->text().size() ==4){
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        report *rep = new report();
        query = rep->getAllInfo(ui->comboBox->currentText(),ui->lineEdit->text());
        model->setQuery(query);

        QSortFilterProxyModel * sort = new QSortFilterProxyModel();
        sort->setFilterKeyColumn(3);
        sort->setSourceModel(model);
        ui->tableView->setModel(sort);
        ui->tableView->setSortingEnabled(true);
        ui->tableView->horizontalHeader()->setSectionsClickable(true);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);

        QSqlQueryModel *model1 = new QSqlQueryModel();
        QSqlQuery query1;
        query1 = rep->getreportAllInfo(ui->comboBox->currentText(),ui->lineEdit->text());
        model1->setQuery(query1);

        ui->tableView_2->setModel(model1);
        ui->tableView_2->setSortingEnabled(true);
        ui->tableView_2->horizontalHeader()->setSectionsClickable(true);
        ui->tableView_2->horizontalHeader()->setStretchLastSection(true);

    }else{
        QMessageBox *mes = new QMessageBox();
        mes->setText("Доступ запрещен \n уровень доступа должен быть >2\n и проверьте год");
        mes->show();
    }
}

void Work::on_pushButton_4_clicked()
{
    bool ok =true;
    ui->lineEdit->text().toInt(&ok);
    if(priority >2 && ok && ui->lineEdit->text().size() ==4){
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        report *rep = new report();
        query = rep->getcityInfo(ui->comboBox->currentText(),ui->comboBox_2->currentText(),ui->lineEdit->text());
        model->setQuery(query);

        QSortFilterProxyModel * sort = new QSortFilterProxyModel();
        sort->setFilterKeyColumn(3);
        sort->setSourceModel(model);
        ui->tableView->setModel(sort);
        ui->tableView->setSortingEnabled(true);
        ui->tableView->horizontalHeader()->setSectionsClickable(true);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
        QSqlQueryModel *model1 = new QSqlQueryModel();
        QSqlQuery query1;
        query1 = rep->getreportcityInfo(ui->comboBox->currentText(),ui->comboBox_2->currentText(),ui->lineEdit->text());
        model1->setQuery(query1);

        ui->tableView_2->setModel(model1);
        ui->tableView_2->setSortingEnabled(true);
        ui->tableView_2->horizontalHeader()->setSectionsClickable(true);
        ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    }else{
        QMessageBox *mes = new QMessageBox();
        mes->setText("Доступ запрещен\n уровень доступа должен быть >2\n и проверьте год");
        mes->show();
    }
}

void Work::on_pushButton_5_clicked()
{

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPrinter::A4);

    QString path = QFileDialog::getSaveFileName(nullptr,"Сохранить в pdf","отчет","PDF (*.pdf)");
    if(path.isEmpty())
        return;
    printer.setOutputFileName(path);
    QTextDocument doc;
    doc.setHtml(Report);
    doc.print(&printer);
    Report="";
}

void Work::on_pushButton_6_clicked()
{
    if(ui->tableView->model() != nullptr && ui->checkBox->isChecked())
{
        QString str;

    str.append("<html><head></head><p style ='font-size:15px;'><body><center>"+QString(ui->comboBox->currentText()));
    str.append("<br>" "</br>");

    str.append("<table border = 6><tr>");
    for(int i =0 ;i<ui->tableView->model()->columnCount();++i){
        QAbstractItemModel* model = ui->tableView->model();

        QVariant v = model->headerData(i,
                                      Qt::Horizontal,
                                      Qt::DisplayRole);
        QString text = v.toString();
        qDebug()<<text;
        str.append("<td>"+text+"</td>");
    }
    str.append("</tr>");

    for(int i =0 ;i<ui->tableView->model()->rowCount();++i){
        str.append("<tr><td>");
        for(int j = 0; j<ui->tableView->model()->columnCount();++j){

            QModelIndex myIndex;
        QVariant myData;
        myIndex = ui->tableView->model()->index(i,j,QModelIndex());
        myData = ui->tableView->model()->data(myIndex, Qt::DisplayRole);
        str.append(myData.toString());
        if(j != ui->tableView->model()->columnCount()-1)
             str.append("</td><td>");
        }
        str.append("</td></tr>");
    }

    str.append("<br>" "</br>");
    str.append("</table></center></body></p></html>");

    qDebug()<<str;
    Report += str;
    QMessageBox *mes = new QMessageBox();
    mes->setText(" таблица сверху сохранена");
    mes->show();
    }else{
        if(ui->checkBox->isChecked()){
        QMessageBox *mes = new QMessageBox();
        mes->setText("Не получилось добавить в отчет таблицу сверху");
        mes->show();
        }
    }

    if(ui->tableView_2->model() != nullptr && ui->checkBox_2->isChecked())
{
        QString str;

    str.append("<html><head></head><p style ='font-size:15px;'><body><center>"+QString(ui->comboBox->currentText()));
    str.append("<table border = 5><tr>");
    for(int i =0 ;i<ui->tableView_2->model()->columnCount();++i){
        QAbstractItemModel* model = ui->tableView_2->model();

        QVariant v = model->headerData(i,
                                      Qt::Horizontal,
                                      Qt::DisplayRole);
        QString text = v.toString();
        qDebug()<<text;
        str.append("<td>"+text+"</td>");
    }
    str.append("</tr>");

    for(int i =0 ;i<ui->tableView_2->model()->rowCount();++i){
        str.append("<tr><td>");
        for(int j = 0; j<ui->tableView_2->model()->columnCount();++j){

            QModelIndex myIndex;
        QVariant myData;
        myIndex = ui->tableView_2->model()->index(i,j,QModelIndex());
        myData = ui->tableView_2->model()->data(myIndex, Qt::DisplayRole);
        str.append(myData.toString());
        if(j != ui->tableView_2->model()->columnCount()-1)
             str.append("</td><td>");
        }
        str.append("</td></tr>");
    }


    str.append("</table></center></body></p></html>");

    qDebug()<<str;
    Report += str;
    QMessageBox *mes = new QMessageBox();
    mes->setText("таблица снизу сохранена");
    mes->show();
    }else{
        if(ui->checkBox_2->isChecked()){
    QMessageBox *mes = new QMessageBox();
    mes->setText("Не получилось добавить в отчет таблицу снизу");
    mes->show();
        }
    }    
}
