#include"sqwindow.h"
#include"ui_sqwindow.h"
SqWindow::SqWindow(QWidget*parent):
    QWidget(parent),
    ui(new Ui::SqWindow)
{
    ui->setupUi(this);
    scene = new SqScene;
    //scene->setSceneRect(-400,-400,800,600);
    ui->graphicsView->setScene(scene);
    this->setWindowTitle("Level");
    connect(scene->squaredHero,&SquaredHero::collisionHere,this,&SqWindow::checkObjectOfCollision);
}
SqWindow::~SqWindow(){
    delete scene;
    delete ui;
}

void SqWindow::checkObjectOfCollision(QGraphicsItem *item)
{
    qDebug()<<"Checking words";
    for(auto it = this->scene->coins.begin();it!=scene->coins.end();it++){
        if(item==*it)
        {
            this->scene->removeItem(item);
            coin_was_deleted=true;
            qDebug()<<"Coin was deleted";
            return;
        }
    }
    coin_was_deleted=false;
    for(auto it = this->scene->finish_points.begin();it!=scene->finish_points.end();it++){
        if(item==*it){
            this->scene->removeItem(item);
            finish_was_reached=true;
            qDebug()<<"Finish was reached";
        }
    }
    return;
}

void SqWindow::keyPressEvent(QKeyEvent *keyEve)
{
   if(keyEve->key() == Qt::Key_A)
       scene->setVector("left");
   if(keyEve->key() == Qt::Key_S)
       scene->setVector("bot");
   if(keyEve->key() == Qt::Key_W)
       scene->setVector("top");
   if(keyEve->key() == Qt::Key_D)
       scene->setVector("right");
   if(keyEve->key() == Qt::Key_Escape){
       this->close();
       emit firstWindow();
   }
   if(keyEve->key()==Qt::Key_O)
       scene->setVector("root");
}
