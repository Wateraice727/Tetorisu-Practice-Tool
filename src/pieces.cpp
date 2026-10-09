#include "pieces.hpp"
#include <raylib.h>

IPiece::IPiece() : Tetromino() {
    id = 1;
    cells.push_back({ {1, 0}, {1, 1}, {1, 2}, {1, 3} }); // base
    cells.push_back({ {0, 2}, {1, 2}, {2, 2}, {3, 2} }); // CW
    cells.push_back({ {2, 0}, {2, 1}, {2, 2}, {2, 3} }); // 180
    cells.push_back({ {0, 1}, {1, 1}, {2, 1}, {3, 1} }); // CCW
    startOffset = {1, 3};
    offset = startOffset;
    color = SKYBLUE;
}

void IPiece::drawPreview(int offsetX, int offsetY) { draw(offsetX - 15, offsetY + 20, color); }

JPiece::JPiece() : Tetromino() {
    id = 2;
    cells.push_back({ {0, 0}, {1, 0}, {1, 1}, {1, 2} }); // base
    cells.push_back({ {0, 1}, {0, 2}, {1, 1}, {2, 1} }); // CW
    cells.push_back({ {1, 0}, {1, 1}, {1, 2}, {2, 2} }); // 180
    cells.push_back({ {0, 1}, {1, 1}, {2, 0}, {2, 1} }); // CCW
    startOffset = {2, 3};
    offset = startOffset;
    color = BLUE;
}

void JPiece::drawPreview(int offsetX, int offsetY) { draw(offsetX, offsetY, color); }

LPiece::LPiece() : Tetromino() {
    id = 3;
    cells.push_back({ {0, 2}, {1, 0}, {1, 1}, {1, 2} }); // base
    cells.push_back({ {0, 1}, {1, 1}, {2, 1}, {2, 2} }); // CW
    cells.push_back({ {1, 0}, {1, 1}, {1, 2}, {2, 0} }); // 180
    cells.push_back({ {0, 0}, {0, 1}, {1, 1}, {2, 1} }); // CCW
    startOffset = {2, 3};
    offset = startOffset;
    color = ORANGE;
}

void LPiece::drawPreview(int offsetX, int offsetY) { draw(offsetX, offsetY, color); }

OPiece::OPiece() : Tetromino() {
    id = 4;
    cells.push_back({ {0, 0}, {0, 1}, {1, 0}, {1, 1} });
    startOffset = {2, 4};
    offset = startOffset;
    color = YELLOW;
}

void OPiece::drawPreview(int offsetX, int offsetY) { draw(offsetX - 15, offsetY + 10, color); }

SPiece::SPiece() : Tetromino() {
    id = 5;
    cells.push_back({ {0, 1}, {0, 2}, {1, 0}, {1, 1} }); // base
    cells.push_back({ {0, 1}, {1, 1}, {1, 2}, {2, 2} }); // CW
    cells.push_back({ {1, 1}, {1, 2}, {2, 0}, {2, 1} }); // 180
    cells.push_back({ {0, 0}, {1, 0}, {1, 1}, {2, 1} }); // CCW
    startOffset = {2, 3};
    offset = startOffset;
    color = LIME;
}

void SPiece::drawPreview(int offsetX, int offsetY) { draw(offsetX, offsetY, color); }

ZPiece::ZPiece() : Tetromino() {
    id = 6;
    cells.push_back({ {0, 0}, {0, 1}, {1, 1}, {1, 2} }); // base
    cells.push_back({ {0, 2}, {1, 1}, {1, 2}, {2, 1} }); // CW
    cells.push_back({ {1, 0}, {1, 1}, {2, 1}, {2, 2} }); // 180
    cells.push_back({ {0, 1}, {1, 0}, {1, 1}, {2, 0} }); // CCW
    startOffset = {2, 3};
    offset = startOffset;
    color = RED;
}

void ZPiece::drawPreview(int offsetX, int offsetY) { draw(offsetX, offsetY, color); }

TPiece::TPiece() : Tetromino() {
    id = 7;
    color = PURPLE;
    cells.push_back({ {0, 1}, {1, 0}, {1, 1}, {1, 2} }); // base
    cells.push_back({ {0, 1}, {1, 1}, {1, 2}, {2, 1} }); // CW
    cells.push_back({ {1, 0}, {1, 1}, {1, 2}, {2, 1} }); // 180
    cells.push_back({ {0, 1}, {1, 0}, {1, 1}, {2, 1} }); // CCW
    startOffset = {2, 3};
    offset = startOffset;
    color = PURPLE;
}

void TPiece::drawPreview(int offsetX, int offsetY) { draw(offsetX, offsetY, color); }