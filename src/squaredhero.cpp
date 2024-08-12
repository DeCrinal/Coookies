#include "squaredhero.h"
#include<QObject>
#include<QCoreApplication>
#include"../gui/SquaredScene.h"
#include<QMessageBox>
#include<QThread>

bool coin_was_deleted = false;
bool finish_was_reached=false;

SquaredHero::SquaredHero(QObject*parent):QObject(parent),
    QGraphicsItem(){
    vector = "right";
    velocity =1.2;
    deltaX = 0;
    deltaY = 0;
    gameTimer = new QTimer(this);
    gameTimer->setSingleShot(false);
    connect(gameTimer,&QTimer::timeout,this,&SquaredHero::GameTimer);
    gameTimer->start(12);
    not_root=true;
}

SquaredHero::~SquaredHero(){
    delete gameTimer;
}

QRectF SquaredHero::boundingRect()const{
    return QRectF(-10,-10,20,20);
}

void SquaredHero::paint(QPainter*painter, const QStyleOptionGraphicsItem
                        *option, QWidget*widget){
    painter->setBrush(QColor(243,129,129));
    painter->drawRect(-10,-10,20,20);
}

void SquaredHero::GameTimer(){
   if(vector == QLatin1String("left")){
       this->setX(this->x()-velocity);
       deltaX -= velocity;
   }
   if(vector == QLatin1String("right")){
       this->setX(this->x() + velocity);
       deltaX += velocity;
   }
   if(vector == QLatin1String("top")){
       this->setY(this->y() - velocity);
       deltaY -= velocity;
   }
   if(vector == QLatin1String("bot")){
       this->setY(this->y() + velocity);
       deltaY += velocity;
   }
   if(scene()->collidingItems(this).isEmpty() == false && not_root){
            QList<QGraphicsItem*>collidingOnes = scene()->collidingItems(this);
            for(auto it = collidingOnes.begin(); it!=collidingOnes.end(); it++){
               emit collisionHere(*it);
            }
            if(!coin_was_deleted&&!finish_was_reached){
                this->setY(this->y() - deltaY);
                this->setX(this->x() - deltaX);
                //QThread::msleep(80);
                deltaX = 0;
                deltaY = 0;
                vector = QLatin1String("right");
            }
            if(finish_was_reached){
               int levelCompleted,levelAvailable;
               velocity = 0;
               std::ifstream in1,in2;
               in1.open("progress.txt");
               in2.open("variables.txt");
               in1>>levelAvailable;
               in2>>levelCompleted;
               in1.close();in2.close();
               if(levelCompleted>=levelAvailable){
                   std::ofstream of;
                   of.open("progress.txt");
                   of<<levelCompleted + 1;
               }
               QMessageBox::information(0,"Message","You Win!");
                       deltaY=0;
               finish_was_reached = false;
            }
   }
}

void SquaredHero::setVector(const QString &vector_from){
    vector = vector_from;
}

void SquaredHero::change_root()
{
   not_root=!not_root;
}

void SquaredEnemy::GameTimer(){
   if(vector == QLatin1String("left")){
       this->setX(this->x() - velocity);
       deltaX -= velocity;
   }
   if(vector == QLatin1String("right")){
       this->setX(this->x() + velocity);
       deltaX += velocity;
   }
   if(vector == QLatin1String("top")){
       this->setY(this->y() - velocity);
       deltaY-=velocity;
   }
   if(vector == QLatin1String("bot")){
       this->setY(this->y() + velocity);
       deltaY+=velocity;
   }
   if((abs(deltaY-finalY) <= 0.00001 && abs(deltaX-finalX) <= 0.00001) ||
           (abs(deltaY) <= 0.00001 && abs(deltaX) <= 0.00001)){
       if(vector == QLatin1String("left")){
           vector = QLatin1String("right");
       }
       else if(vector == QLatin1String("right")){
           vector = QLatin1String("left");
       }
       else if(vector == QLatin1String("top")){
           vector = QLatin1String("bot");
       }
       else{
           vector = QLatin1String("top");
       }
   }
}
void SquaredEnemy::setFinalXYChange(const double &x=100, const double &y=100){
   finalX = x;
   finalY = y;
}

void SquaredEnemy::setVelocity(const double &speed){
    velocity = speed;
}

void SquaredEnemy::paint(QPainter*painter, const QStyleOptionGraphicsItem
                        *option, QWidget*widget){
    painter->setBrush(QColor(169, 238, 230));
    painter->drawRect(-10, -10, 20, 20);
}
void CircleCoin::paint(QPainter*painter, const QStyleOptionGraphicsItem
                        *option, QWidget*widget){
    painter->setBrush(QColor(255, 215, 0));
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(-10, -10, 20, 20);
}

void FinishPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem
                        *option, QWidget *widget)
{
   painter->setBrush(QColor(49, 0, 98));
   painter->setPen(Qt::black);
   painter->drawRect(-10, -10, 20, 20);
}
