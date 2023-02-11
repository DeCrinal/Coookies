#ifndef SQUAREDSCENE_H
#define SQUAREDSCENE_H
#include<QGraphicsScene>
#include"squaredhero.h"
#include<QTimer>
#include<iostream>
#include <fstream>
#include<vector>
using std::vector;
class SqScene:public QGraphicsScene{
    Q_OBJECT
private:
    void createBoards();
public slots:
    void is_collision(QGraphicsItem*);
public:
    vector<CircleCoin*>coins;
    vector<SquaredEnemy*>enemies;
    vector<FinishPoint*>finish_points;
    vector<vector<int>>boards;
    SquaredHero*squaredHero;
    SqScene(QObject*parent=nullptr);
    void setVector(std::string vector_from);
    ~SqScene();
    void get_level_data(int choosed_lvl);
};

#endif // SQUAREDSCENE_H
