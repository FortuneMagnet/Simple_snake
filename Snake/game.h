#ifndef GAME_H
#define GAME_H

#include <QRandomGenerator>
#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QMessageBox>

class Game : public QWidget
{
public:
    Game();

protected:
    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    static const int DOT_WIDTH  = 20;
    static const int DOT_HEIGHT = 20;
    static const int FIELD_WITH   = 20;
    static const int FIELD_HEIGHT = 20;
    
    static const int DELAY = 150;

    void doDrawing();
    void localApple();
    void move();
    void check_field();
    void gameOver();
    void checkApple();

    int m_timerId;

    QPoint m_apple;
    
    enum Directions {
        left, right, up, down
    };

    Directions m_dir;

    bool m_inGame;
    QVector<QPoint> m_dots;
    
    
    void initGame();
};

#endif // GAME_H
