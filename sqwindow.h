#ifndef SQWINDOW_H
#define SQWINDOW_H
#include<QWidget>
#include"SquaredScene.h"
#include<QMainWindow>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QDebug>
namespace Ui{
    class SqWindow;
}

class SqWindow: public QWidget{
    Q_OBJECT
public:
    explicit SqWindow(QWidget*parent = 0);
    ~SqWindow();
public slots:
    void checkObjectOfCollision(QGraphicsItem*);
signals:
    void firstWindow();
private:
    Ui::SqWindow*ui;
    SqScene *scene;
protected:
      void keyPressEvent(QKeyEvent*keyEve)override;
};

#endif // SQWINDOW_H
