#include"SquaredScene.h"
#include "../gui/sqwindow.h"
#include <QGraphicsItem>
#include <QtCore>
#include <ctime>
#include <QPainter>
#include <QStringLiteral>



SqScene::SqScene(QObject*parent):QGraphicsScene(parent){
    squaredHero = new SquaredHero;
    this->addItem(squaredHero);
    createBoards();
}
SqScene::~SqScene(){
    delete squaredHero;
}

void SqScene::get_level_data(int choosed_lvl)
{
    int N;

    QPen black_pen(Qt::black);
    const QBrush board_brush(QColor(98,87,114));

    std::ifstream input;
    switch(choosed_lvl){
    case(1):
    case(2):
    case(3):
    case(4):
    case(5):
        input.open("fifth.txt");
        break;
    case(6):
        input.open("six.txt");
        break;
    case(7):
    case(8):
    case(9):
    case(10):
    default:
        break;
    }
    if(!input.is_open()){
       qDebug() << QLatin1String("Error while opening");
       return;
    }
    input >> N;
    {
        int x_pos, y_pos;
        input >> x_pos >> y_pos;
        squaredHero->setPos(x_pos, y_pos);
        this->addItem(squaredHero);
    }
    input >> N;
    for(int i = 0; i < N; i++){
       int x, y;
       input >> x >> y;
       finish_points.push_back(new FinishPoint);
       finish_points[i]->setFinalXYChange(0, 0);
       finish_points[i]->setVector(QLatin1String("bot"));
       finish_points[i]->setVelocity(0);
       finish_points[i]->setPos(x,y);
       this->addItem(finish_points[i]);
    }
    input >> N;
    for(int i = 0; i < N; i++){
        vector<int>empty;
        boards.push_back(empty);
        for(int j = 0; j < 4; j++){
            int temp;
            input>>temp;
            boards[i].push_back(temp);
        }
        this->addRect(boards[i][0], boards[i][1], boards[i][2], boards[i][3], black_pen, board_brush);
    }
    input>>N;
    for(int i = 0; i < N; i++){
        int x_change, y_change;
        int x_pos, y_pos;
        double velocity;
        QString vector;
        input >> x_change >> y_change;
        std::string tempInput;
        input >> tempInput;
        vector = QString::fromStdString(tempInput);
        input >> velocity;
        input >> x_pos >> y_pos;
        enemies.push_back(new SquaredEnemy);
        enemies[i]->setFinalXYChange(x_change, y_change);
        enemies[i]->setVector(vector);
        enemies[i]->setVelocity(velocity);
        enemies[i]->setPos(x_pos, y_pos);
        this->addItem(enemies[i]);
    }
    input>>N;
    for(int i =0; i<N; i++){
        int x_pos, y_pos;
        coins.push_back(new CircleCoin);
        input >> x_pos >> y_pos;
        coins[i]->setPos(x_pos, y_pos);
        coins[i]->setFinalXYChange(0, 0);
        coins[i]->setVector(QLatin1String("bot"));
        coins[i]->setVelocity(0);
        this->addItem(coins[i]);
    }

    input.close();
}
void SqScene::createBoards(){
    int choosedLvl=1;
    std::ifstream in;
    in.open("variables.txt");
    if(in.is_open()){
        qDebug() << QLatin1String("Variables opened");
    }else{
        qDebug() << QLatin1String("Variables wasn't open");
    }
    in >> choosedLvl;
    in.close();
    if(choosedLvl == 1){
        const int N = 6;
        const float boards[N][4] = {{0,0,10,510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10},
                                    {10,70,630,10}, {630,80,10,430}};
        squaredHero->setPos(25, 25);
        for(int i = 0; i < N; i++){
        QBrush blackBrush(QColor(98, 87, 114));
        QPen blackPen(Qt::black);
        blackPen.setWidth(1);
        QGraphicsRectItem * graphItem = addRect(boards[i][0], boards[i][1], boards[i][2],
                boards[i][3], blackPen, blackBrush);
        }
        FinishPoint* finish1 = new FinishPoint;
        finish1->setFinalXYChange(0,0);
        finish1->setVector(QStringLiteral("bot"));
        finish1->setVelocity(0);
        this->addItem(finish1);
        finish1->setPos(680, 480);
        finish_points.push_back(finish1);
    }
    if(choosedLvl == 2){
        const int N = 40;
        const float boards[N][4] = {{0,0,10,510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10},
                                    {10,40,630,10}, {70,80,630,10}, {80,130,10,30}, {10,160,570,10},
                                    {180,90,10,30}, {280,130,10,30}, {380,90,10,30}, {480,130,10,30},
                                    {620,90,10,50}, {570,170,10,30}, {580,190,80,10}, {380,260,320,10},
                                    {380,220,140,10}, {380,230,10,30}, {510,230,10,30}, {290,170,10,130},
                                    {60,240,140,10}, {60,250,10,170}, {120,300,10,200}, {200,240,10,200},
                                    {210,340,220,10}, {260,400,10,100}, {320,350,10,90}, {390,400,10,100},
                                    {430,340,10,100}, {500,330,10,180}, {510,360,90,10}, {560,270,10,50},
                                    {420,270,10,70}, {510,360,90,10}, {560,370,10,130}, {600,330,10,50},
                                    {610,440,10,60}, {660,270,10,100}, {660,370,50,10}, {680,440,30,10}
                            };
        squaredHero->setPos(22, 25);

        for(int i = 0; i < N; i++){
            QBrush blackBrush(QColor(98, 87, 114));
            QPen blackPen(Qt::black);
            blackPen.setWidth(1);
            QGraphicsRectItem * graphItem = addRect(boards[i][0],boards[i][1],boards[i][2],
                    boards[i][3],blackPen,blackBrush);
        }
        FinishPoint*finish1 = new FinishPoint;
        finish1->setFinalXYChange(0, 0);
        finish1->setVector("bot");
        finish1->setVelocity(0);
        this->addItem(finish1);
        finish1->setPos(680, 480);
        finish_points.push_back(finish1);
    }
    if(choosedLvl == 4){
        const int N = 100;
        float boards[N][4]={{0,0,10,510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10},
                            {100,10,10,90}, {160,100,160,10}, {10,160,390,10}, {160,147,10,23},
                            {220,110,10,23}, {280,137,10,23}, {390,60,10,100}, {390,170,10,30},
                            {400,60,140,10}, {440,10,80,10}, {440,70,10,30}, {400,190,140,10},
                            {580,60,40,10}, {643,60,57,10}, {610,70,10,330}, {643,70,10,330},
                            {580,70,10,150}, {580,220,30,10}, {450,140,130,10}, {500,180,20,10},
                            {600,440,100,10}, {600,480,10,20}, {560,390,50,10}, {550,390,10,50},
                            {500,430,50,10}, {500,490,60,10}, {560,430,17,10}, {470,200,10,30},
                            {450,230,30,10}, {450,240,10,30}, {430,270,30,10}, {430,280,10,30},
                            {400,310,40,10}, {520,240,10,120}, {510,270,10,10}, {500,280,20,10},
                            {490,290,30,10}, {480,310,40,10}, {280,360,250,10}, {350,280,10,80},
                            {360,270,30,10}, {380,240,10,30}, {380,230,30,10}, {570,260,10,100},
                            {355,275,5,5}, {480,370,10,30}, {420,390,90,10}, {500,400,10,30},
                            {40,170,10,70}, {10,240,30,10}, {10,280,30,10}, {10,340,150,10},
                            {90,210,10,90}, {100,210,120,10}, {220,220,10,20}, {230,240,10,110},
                            {240,240,20,10}, {310,170,10,150}, {280,170,10,30}, {280,290,30,10},
                            {230,350,50,10}, {150,260,10,80}, {160,260,30,10}, {180,270,10,230},
                            {190,410,70,10}, {320,370,10,80}};

        squaredHero->setPos(30, 30);

        SquaredEnemy*movingSq1 = new SquaredEnemy;
        movingSq1->setFinalXYChange(0, 10);
        movingSq1->setVector(QLatin1String("bot"));
        movingSq1->setVelocity(0.1);
        this->addItem(movingSq1);
        movingSq1->setPos(220, 22);

        SquaredEnemy*movingSq2 = new SquaredEnemy;
        movingSq2->setFinalXYChange(0, -10);
        movingSq2->setVector(QLatin1String("top"));
        movingSq2->setVelocity(0.1);
        this->addItem(movingSq2);
        movingSq2->setPos(220, 88);

        SquaredEnemy*movingSq3 = new SquaredEnemy;
        movingSq3->setFinalXYChange(0, -19);
        movingSq3->setVector(QLatin1String("top"));
        movingSq3->setVelocity(0.1);
        this->addItem(movingSq3);
        movingSq3->setPos(280, 41);

        SquaredEnemy*movingSq4 = new SquaredEnemy;
        movingSq4->setFinalXYChange(0, 19);
        movingSq4->setVector(QLatin1String("bot"));
        movingSq4->setVelocity(0.1);
        this->addItem(movingSq4);
        movingSq4->setPos(280, 69);

        SquaredEnemy*movingSq5 = new SquaredEnemy;
        movingSq5->setFinalXYChange(50, 0);
        movingSq5->setVector(QLatin1String("right"));
        movingSq5->setVelocity(0.5);
        this->addItem(movingSq5);
        movingSq5->setPos(607, 43);

        SquaredEnemy*movingSq6 = new SquaredEnemy;
        movingSq6->setFinalXYChange(0, 60);
        movingSq6->setVector(QLatin1String("bot"));
        movingSq6->setVelocity(0.5);
        this->addItem(movingSq6);
        movingSq6->setPos(485, 420);

        SquaredEnemy*movingSq7 = new SquaredEnemy;
        movingSq7->setFinalXYChange(0, -60);
        movingSq7->setVector(QLatin1String("top"));
        movingSq7->setVelocity(0.5);
        this->addItem(movingSq7);
        movingSq7->setPos(420,475);

        SquaredEnemy*movingSq8 = new SquaredEnemy;
        movingSq8->setFinalXYChange(60,0);
        movingSq8->setVector(QLatin1String("right"));
        movingSq8->setVelocity(0.5);
        this->addItem(movingSq8);
        movingSq8->setPos(600, 415);

        CircleCoin*coin1 = new CircleCoin;
        coin1->setFinalXYChange(0, 0);
        coin1->setVector(QLatin1String("bot"));
        coin1->setVelocity(0);
        this->addItem(coin1);
        coin1->setPos(420, 100);
        coins.push_back(coin1);

        FinishPoint*finish1 = new FinishPoint;
        finish1->setFinalXYChange(0, 0);
        finish1->setVector(QLatin1String("bot"));
        finish1->setVelocity(0);
        this->addItem(finish1);
        finish1->setPos(680, 480);
        finish_points.push_back(finish1);

        for(int i = 0; i < N; i++){
        QBrush blackBrush(QColor(98, 87, 114));
        QPen blackPen(Qt::black);
        blackPen.setWidth(1);
        QGraphicsRectItem *graphItem = addRect(boards[i][0], boards[i][1], boards[i][2],
                boards[i][3], blackPen, blackBrush);
        }

    }
    if(choosedLvl == 5){
        const int N = 4;
        float boards[N][4]={};
        std::ifstream input;
        input.open("four.txt");
        if(input.is_open()){
            qDebug()<<"Input works";
            for(int i = 0; i<N&&!input.eof();i++){
                for(int j = 0; j < 4 && !input.eof();j++)
                    input>>boards[i][j];
            }
        }else{
            qDebug()<<"Input doesn't work";
        }
        input.close();
        squaredHero->setPos(30, 30);
        for(int i = 0; i < N; i++){
        QBrush blackBrush(Qt::black);
        QPen blackPen(Qt::black);
        blackPen.setWidth(1);
        QGraphicsRectItem *graphItem = addRect(boards[i][0], boards[i][1], boards[i][2],
                boards[i][3], blackPen, blackBrush);
    }
    }
    if(choosedLvl == 6){
        get_level_data(6);
    }
    if(choosedLvl == 3){
        const int N = 71;
        const float boards[N][4] = {{0, 0, 10, 510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10}, {150,0,10,250},
                                    {0,200,30,10}, {50,250,110,10}, {50,250,10,100}, {70,350,10,50}, {50,350,20,10},
                                    {0,450,40,10}, {80,390,10,70}, {80,450,30,10}, {150,300,10,200}, {80,350,30,10},
                                    {110,300,20,20}, {150,300,40,10}, {190,0,10,250}, {240,250,10,150}, {190,240,60,10},
                                    {220,340,30,10}, {150,380,40,10}, {150,450,80,10}, {280,310,10,200}, {320,0,10,460},
                                    {320,460,50,10}, {400,350,10,150}, {250,50,20,20}, {250,90,20,20}, {250,130,20,20},
                                    {250,170,20,20}, {280,210,10,80}, {350,220,10,180}, {390,340,30,10}, {350,300,30,10},
                                    {400,360,10,70}, {420,260,10,90}, {400,250,60,10}, {450,150,10,100}, {370,150,80,10},
                                    {370,50,10,130}, {600,450,10,50}, {600,450,20,10}, {650,450,50,10}, {370,50,220,10},
                                    {620,50,80,10}, {600,100,10,300}, {600,100,75,10}, {675,140,20,20}, {615,140,20,20},
                                    {675,180,20,20}, {615,180,20,20}, {675,220,20,20}, {615,220,20,20}, {610,270,65,10},
                                    {635,305,65,10}, {610,340,65,10}, {635,375,65,10}, {450,100,150,10}, {380,100,40,10},
                                    {450,180,60,10}, {490,130,110,10}, {540,130,10,100}, {420,290,100,10}, {540,230,40,10},
                                    {580,230,10,70}, {470,340,130,10}, {470,340,10,50}, {450,390,30,10}, {450,390,10,70},
                                    {450,460,90,10}};
        squaredHero->setPos(30, 30);
        for(int i = 0; i < N; i++){
            QBrush blackBrush(QColor(98, 87, 114));
            QPen blackPen(Qt::black);
            blackPen.setWidth(1);
            QGraphicsRectItem *graphItem = addRect(boards[i][0], boards[i][1], boards[i][2],
                    boards[i][3], blackPen, blackBrush);
        }
        FinishPoint*finish1 = new FinishPoint;
        finish1->setFinalXYChange(0, 0);
        finish1->setVector("bot");
        finish1->setVelocity(0);
        this->addItem(finish1);
        finish1->setPos(680, 480);
        finish_points.push_back(finish1);
    }
    if(choosedLvl == 7){
        const int N = 4;
        const float boards[N][4] = {{0,0,10,510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10}};
        squaredHero->setPos(30, 30);
        for(int i = 0; i<N;i++){
            QBrush blackBrush(Qt::black);
            QPen blackPen(Qt::black);
            blackPen.setWidth(1);
            QGraphicsRectItem *graphItem = addRect(boards[i][0],boards[i][1],boards[i][2],
                    boards[i][3],blackPen,blackBrush);
        }
    }
    if(choosedLvl == 8){
        const int N = 4;
        const float boards[N][4] = {{0,0,10,510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10}};
        squaredHero->setPos(30, 30);
        for(int i = 0; i<N;i++){
        QBrush blackBrush(Qt::black);
        QPen blackPen(Qt::black);
        blackPen.setWidth(1);
        QGraphicsRectItem *graphItem = addRect(boards[i][0],boards[i][1],boards[i][2],
                boards[i][3],blackPen,blackBrush);
    }
    }
    if(choosedLvl == 9){
        const int N = 4;
        const float boards[N][4] = {{0,0,10,510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10}};
        squaredHero->setPos(30, 30);
        for(int i = 0; i<N;i++){
            QBrush blackBrush(Qt::black);
            QPen blackPen(Qt::black);
            blackPen.setWidth(1);
            QGraphicsRectItem *graphItem = addRect(boards[i][0], boards[i][1], boards[i][2],
                    boards[i][3], blackPen, blackBrush);
        }
    }
    if(choosedLvl == 10){
        const int N = 4;
        const float boards[N][4] = {{0,0,10,510}, {10,0,700,10}, {700,0,10,500}, {10,500,700,10}};
        squaredHero->setPos(30, 30);
        for(int i = 0; i < N; i++){
            QBrush blackBrush(Qt::black);
            QPen blackPen(Qt::black);
            blackPen.setWidth(1);
            QGraphicsRectItem *graphItem = addRect(boards[i][0], boards[i][1], boards[i][2],
                    boards[i][3], blackPen, blackBrush);
        }
    }
}

void SqScene::is_collision(QGraphicsItem * item)
{
   for(auto it = coins.begin(); it!=coins.end(); it++){
      if(item == *it)
         removeItem(item);
   }
}
void SqScene::setVector(const QString& vector_from){
    if(vector_from != QLatin1String("root")){
        squaredHero->setVector(vector_from);
    }
    else{
        squaredHero->change_root();
    }
}
