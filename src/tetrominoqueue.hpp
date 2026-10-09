#pragma once
#include "tetromino.hpp"
#include "pieces.hpp"
#include <vector>

class TetrominoQueue {
private:
    std::vector<Tetromino*> pieces = {
        new IPiece(),
        new JPiece(),
        new LPiece(),
        new OPiece(),
        new SPiece(),
        new ZPiece(),
        new TPiece()
    };
    Tetromino* nextPiece;
    int queueLeft;
    Tetromino* nextPieces[14];
    
public:
    TetrominoQueue();
    ~TetrominoQueue();

    Tetromino* getNextPiece() const;

    Tetromino* getNextInQueue(int position) const;

    Tetromino* getAndUpdate();

    Tetromino* getPieceFromID(int id);

    void shuffle7Bag(int start);
};