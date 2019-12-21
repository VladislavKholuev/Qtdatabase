//#include "mainwindow.h"
#include "work.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    Work work;
    a.setWindowIcon(QIcon("C:/Qt/kursach/1.jpg"));
 //   w.show();
    work.show();

    return a.exec();
}
