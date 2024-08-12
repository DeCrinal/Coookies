#include "../gui/mainwindow.h"
#include<iostream>
#include<fstream>
#include <QApplication>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int availableLvl = 0;
    std::ifstream in;
    in.open("progress.txt");
    if(in.is_open()){
        in >> availableLvl;
    }
    else{
        qDebug() << QLatin1String("progress.txt wasn't open in main (1)");
    }
    in.close();
    if(availableLvl == 0){
       availableLvl++;
       std::ofstream out;
       out.open("progress.txt");
       if(out.is_open()){
           out<<availableLvl;
       }
       else{
           qDebug() << QLatin1String("progress.txt wasn't open in main (2)");
       }
    }
    MainWindow w;
    w.show();
    a.exec();
    return 0;
}
