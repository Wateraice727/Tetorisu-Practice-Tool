#include "tetrominoqueue.hpp"
#include <algorithm>
#include <iterator>
#include <random>

TetrominoQueue::TetrominoQueue() {
    for (int p = 0; p < 14; ++p) nextPieces[p] = nullptr;
    queueLeft = 0;
    for (int i = 0; i < 2; ++i) shuffle7Bag(i * 7);
}

TetrominoQueue::~TetrominoQueue() {}

Tetromino* TetrominoQueue::getNextPiece() const { return nextPiece; }

Tetromino* TetrominoQueue::getNextInQueue(int position) const { return nextPieces[position]; }

Tetromino* TetrominoQueue::getPieceFromID(int id) {
    switch (id) {
        case 1:
            return new IPiece;
        case 2:
            return new JPiece;
        case 3:
            return new LPiece;
        case 4:
            return new OPiece;
        case 5:
            return new SPiece;
        case 6:
            return new ZPiece;
        default:
            return new TPiece;
    }
}

void TetrominoQueue::shuffle7Bag(int start) {
    int id[7] = {1, 2, 3, 4, 5, 6, 7};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(id, id + 7, gen);
    for (int i = 0; i < 7; ++i) nextPieces[i + start] = getPieceFromID(id[i]);
    queueLeft += 7;
}

Tetromino* TetrominoQueue::getAndUpdate() {
    nextPiece = nextPieces[0];
    --queueLeft;
    for (int i = 0; i < queueLeft; ++i) nextPieces[i] = nextPieces[i + 1];
    nextPieces[queueLeft] = nullptr;
    if (queueLeft <= 7) shuffle7Bag(7);
    return nextPiece;
}