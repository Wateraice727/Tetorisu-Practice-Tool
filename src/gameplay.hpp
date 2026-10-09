#pragma once
#include "tetromino.hpp"
#include "board.hpp"
#include "tetrominoqueue.hpp"

class Gameplay {
private:
    Tetromino* currentPiece;
    Board board;
    TetrominoQueue pieceQueue;    
    Tetromino* holdPiece;
    bool holdable;
    double latestUpdate;
    bool gameOver;
    int score;

    bool pieceFits();

    int cellDropDistance(Position p);
    int pieceDropDistance();
    
public:
    Gameplay();
    ~Gameplay();

    bool getGameOver() const;

    int getScore() const;

   void draw();

   void input();

    void rotatePieceCW();
    void rotatePieceCCW();
    void rotatePiece180();

    void moveLeft();

    void moveRight();

    void softDrop();
    void hardDrop();

    bool isGameOver();
    bool isPieceOutside();

    void lockPiece();

    void holdOrSwap();

    void reset();

    bool eventTrigger(double interval, double& latestUpdate);

    void updateScore(int lineCleared, int softDropPoints);
};