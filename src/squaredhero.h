#ifndef SQUAREDHERO_H
#define SQUAREDHERO_H
#include<QGraphicsItem>
#include<QObject>
#include<QWidget>
#include<QPainter>
#include<string>
#include<QKeyEvent>
#include<fstream>
#include<limits>
#include<cmath>

extern bool coin_was_deleted;
extern bool finish_was_reached;

class SquaredHero: public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    SquaredHero(QObject*parent = nullptr);
    ~SquaredHero();
    void setVector(const QString &vector_from);
    void change_root();
protected slots:
    virtual void GameTimer();
signals:
    void collisionHere(QGraphicsItem*item);
protected:
    QString vector;
    double velocity;
    double deltaX, deltaY;
    QTimer*gameTimer;
    QRectF boundingRect() const;
    virtual void paint(QPainter*painter, const QStyleOptionGraphicsItem*option,
               QWidget*widget);
private:
    bool not_root;

};

class SquaredEnemy: public SquaredHero{
    Q_OBJECT
private:
    double finalX, finalY;
protected:
    virtual void paint(QPainter*painter, const QStyleOptionGraphicsItem*option,
               QWidget*widget);
protected slots:
    virtual void GameTimer();
public:
    void setFinalXYChange(const double&x, const double&y);
    void setVelocity(const double&speed);
};

class CircleCoin: public SquaredEnemy{
    Q_OBJECT
protected:
    virtual void paint(QPainter*painter, const QStyleOptionGraphicsItem*option,
                       QWidget*widget);
};
class FinishPoint: public SquaredEnemy{
    Q_OBJECT
private:
    virtual void paint(QPainter*painter, const QStyleOptionGraphicsItem*option,
                       QWidget*widget);
};

#endif // SQUAREDHERO_H
