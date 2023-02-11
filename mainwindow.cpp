#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sqWindow = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clickHandler(int lvl){
    std::ifstream in;
    std::ofstream out;
    int lvlAvailable;
    in.open("progress.txt");
    if(in.is_open()){
        in>>lvlAvailable;
    }
    in.close();
    out.open("variables.txt");
    if(out.is_open()){
        out<<lvl;
    }
    out.close();
    if(lvlAvailable < lvl){
        QMessageBox::information(0,"Message","This level is not available yet :(");
        return;
    }
    delete sqWindow;
    sqWindow = new SqWindow();
    connect(sqWindow,&SqWindow::firstWindow,this,&MainWindow::showClear);
    sqWindow->show();
    this->close();
}
void MainWindow::on_pushButton_1_clicked(){
    clickHandler(1);
}
void MainWindow::on_pushButton_2_clicked(){
    clickHandler(2);
}
void MainWindow::on_pushButton_3_clicked(){
    clickHandler(3);
}
void MainWindow::on_pushButton_4_clicked(){
    clickHandler(4);
}
void MainWindow::on_pushButton_5_clicked(){
    clickHandler(5);
}
void MainWindow::on_pushButton_6_clicked(){
    clickHandler(6);
}
void MainWindow::on_pushButton_7_clicked(){
    clickHandler(7);
}
void MainWindow::on_pushButton_8_clicked(){
    clickHandler(8);
}
void MainWindow::on_pushButton_9_clicked(){
    clickHandler(9);
}
void MainWindow::on_pushButton_10_clicked(){
    clickHandler(10);
}
void MainWindow::showClear(){
    this->show();
    delete sqWindow;
    sqWindow = nullptr;
}
