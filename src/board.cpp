#include "board.hpp"

Board::Board(int row, int column) {
    numRows = row;
    numColumns = column;
    grid.assign(row, std::vector<int>(column, 0));
}

int Board::getNumRows() const { return numRows; }

int Board::getNumColumns() const { return numColumns; }

int Board::getGridPosition(int row, int column) const { return grid[row][column]; }

void Board::setGridPosition(int row, int column, int value) { grid[row][column] = value; }

void Board::draw() {
    int offsetX = 480;
    for (int r = 4; r < numRows; ++r)
        for (int c = 0; c < numColumns; ++c)
            DrawRectangle(offsetX + c * 30 + 11, (r - 2) * 30 + 11, 29, 29, colors[grid[r][c]]);
    DrawRectangle(820, 60, 130, 450, colors[0]);
    DrawRectangle(310, 60, 130, 90, colors[0]);
}

bool Board::isCellInside(int row, int column) { return row >= 0 && row < numRows && column >= 0 && column < numColumns; }

bool Board::isCellEmpty(int row, int column) { return grid[row][column] == 0; }

bool Board::isRowEmpty(int row) {
    for (int c = 0; c < numColumns; ++c) 
        if (grid[row][c]) 
            return 0;
    return 1;
}

bool Board::isRowFull(int row) {
    for (int c = 0; c < numColumns; ++c) 
        if (!grid[row][c]) 
            return 0;
    return 1;
}

void Board::clearRow(int row) {
    for (int c = 0; c < numColumns; ++c) 
        grid[row][c] = 0;
}

int Board::clearFullRow() {
    int cleared = 0;
    for (int r = numRows - 1; r >= 0; --r) {
        if (isRowFull(r)) {
            clearRow(r);
            ++cleared;
        }
        else if (cleared) moveRowDown(r, cleared);
    }
    return cleared;
}

void Board::moveRowDown(int row, int numRows) {
    for (int c = 0; c < numColumns; ++c) {
        grid[row + numRows][c] = grid[row][c];
        grid[row][c] = 0;
    }
}