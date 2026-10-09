#include "gameplay.hpp"
#include <raylib.h>

Gameplay::Gameplay() {
    board = Board();
    pieceQueue = TetrominoQueue();
    gameOver = 0;
    currentPiece = pieceQueue.getAndUpdate();
    holdPiece = nullptr;
    holdable = 1;
    score = 0;
    latestUpdate = 0;
}

Gameplay::~Gameplay() {}

bool Gameplay::getGameOver() const { return gameOver; }

int Gameplay::getScore() const { return score; }

void Gameplay::draw() {
    board.draw();
    currentPiece->draw(11, 11, currentPiece->getColor());
    for (int i = 0; i < 5; ++i) 
        pieceQueue.getNextInQueue(i)->drawPreview(270, 70 + i * 90);

    if (holdPiece != nullptr) 
        holdPiece->drawPreview(-240, 70);
}

void Gameplay::input() {
    int keyPressed = GetKeyPressed();
    if (gameOver) reset();
    switch (keyPressed) {
        case KEY_UP:
        case KEY_X:
            rotatePieceCW();
            break;
        case KEY_Z:
            rotatePieceCCW();
            break;
        case KEY_A:
            rotatePiece180();
            break;
        case KEY_C:
            holdOrSwap();
            break;
        case KEY_R:
            reset();
            break;
        case KEY_SPACE:
            hardDrop();
            break;
    }
    if (IsKeyDown(KEY_LEFT) && eventTrigger(0.06, latestUpdate)) moveLeft();
    if (IsKeyDown(KEY_RIGHT) && eventTrigger(0.06, latestUpdate)) moveRight();
    if (IsKeyDown(KEY_DOWN) && eventTrigger(0.1, latestUpdate)) {
        softDrop();
        updateScore(0, 1);
    }
}

bool Gameplay::pieceFits() {
    for (const Position& p : currentPiece->getCellPositions())
        if (!board.isCellEmpty(p.row, p.column)) return 0;
    return 1;
}

void Gameplay::rotatePieceCW() {
    if (!gameOver) {
        currentPiece->rotateClockwise();
        if (isPieceOutside() || !pieceFits()) currentPiece->rotateCounterClockwise();
    }
}

void Gameplay::rotatePieceCCW() {
    if (!gameOver) {
        currentPiece->rotateCounterClockwise();
        if (isPieceOutside() || !pieceFits()) currentPiece->rotateClockwise();
    }
}

void Gameplay::rotatePiece180() {
    if (!gameOver) {
        currentPiece->rotate180();
        if (isPieceOutside() || !pieceFits()) currentPiece->rotate180();
    }
}

void Gameplay::moveLeft() {
    if (!gameOver) {
        currentPiece->move(0, -1);
        if (isPieceOutside() || !pieceFits()) currentPiece->move(0, 1);
    }
}

void Gameplay::moveRight() {
    if (!gameOver) {
        currentPiece->move(0, 1);
        if (isPieceOutside() || !pieceFits()) currentPiece->move(0, -1);
    }
}

void Gameplay::softDrop() {
    if (!gameOver) {
        currentPiece->move(1, 0);
        if (isPieceOutside() || !pieceFits()) {
            currentPiece->move(-1, 0);
            lockPiece();
        }
    }
}

int Gameplay::cellDropDistance(Position p) {
    int drop = 0;
    while (board.isCellInside(p.row + drop + 1, p.column) && board.isCellEmpty(p.row + drop + 1, p.column))
        ++drop;
    return drop;
}

int Gameplay::pieceDropDistance() {
    int drop = board.getNumRows();
    for (const Position& p : currentPiece->getCellPositions())
        drop = std::min(drop, cellDropDistance(p));
    updateScore(0, drop << 1);
    return drop;
}

void Gameplay::hardDrop() {
    currentPiece->move(pieceDropDistance(), 0);
    lockPiece();
}

bool Gameplay::isGameOver() { return !(board.isRowEmpty(0) && board.isRowEmpty(1) && board.isRowEmpty(2) && board.isRowEmpty(3)); }

bool Gameplay::isPieceOutside() {
    for (const Position& p : currentPiece->getCellPositions())
        if (!board.isCellInside(p.row, p.column)) return 1;
    return 0;
}

void Gameplay::lockPiece() {
    if (!gameOver) {
        for (const Position& p : currentPiece->getCellPositions())
            board.setGridPosition(p.row, p.column, currentPiece->getID());
        
        int cleared = board.clearFullRow();
        if (cleared > 0) updateScore(cleared, 0);

        if (isGameOver()) gameOver = 1;
        currentPiece = pieceQueue.getAndUpdate();
        holdable = 1;
    }
}

void Gameplay::holdOrSwap() {
    if (!gameOver && holdable) {
        if (holdPiece == nullptr) {
            holdPiece = pieceQueue.getPieceFromID(currentPiece->getID());
            currentPiece = pieceQueue.getAndUpdate();
        }
        else {
            Tetromino* temp = holdPiece;
            holdPiece = pieceQueue.getPieceFromID(currentPiece->getID());
            currentPiece = pieceQueue.getPieceFromID(temp->getID());
        }
        holdable = 0;
    }
}

void Gameplay::reset() {
    board = Board();
    pieceQueue = TetrominoQueue();
    currentPiece = pieceQueue.getAndUpdate();
    gameOver = 0;
    holdPiece = nullptr;
    holdable = 1;
    score = 0;
}

bool Gameplay::eventTrigger(double interval, double& latestUpdate) {
    double currentTime = GetTime();
    if (currentTime - latestUpdate >= interval) {
        latestUpdate = currentTime;
        return 1;
    }
    return 0;
}

void Gameplay::updateScore(int lineCleared, int dropPoints) {
    if (lineCleared == 1) score += 100;
    else if (lineCleared == 2) score += 300;
    else if (lineCleared == 3) score += 500;
    else if (lineCleared == 4) score += 800;
    score += dropPoints;
}