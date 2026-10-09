#include "tetromino.hpp"

Tetromino::Tetromino() {
    rotationState = 0;
    offset = {startOffset.row, startOffset.column};
}

int Tetromino::getID() const { return id; }

Color Tetromino::getColor() const { return color; }

void Tetromino::draw(int offsetX, int offsetY, Color nameColor) {
    int defaultOffsetX = 480;
    std::vector<Position> tiles = getCellPositions();
    for (const Position& p : tiles)
        DrawRectangle(defaultOffsetX + offsetX + p.column * 30, offsetY + (p.row - 2) * 30, 29, 29, nameColor);
}

std::vector<Position> Tetromino::getCellPositions() {
    std::vector<Position> movedCells;
    for (const Position& p : cells[rotationState])
        movedCells.push_back({p.row + offset.row, p.column + offset.column});
    return movedCells;
}

void Tetromino::rotateClockwise() { rotationState = (rotationState + 1) % (int)cells.size(); }

void Tetromino::rotateCounterClockwise() { rotationState = !rotationState ? (int)cells.size() - 1 : rotationState - 1; }

void Tetromino::rotate180() { rotationState < 2 ? rotationState += 2 : rotationState -= 2; }

void Tetromino::move(int row, int column) {
    offset.row += row;
    offset.column += column;
}