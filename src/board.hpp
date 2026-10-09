#pragma once
#include <vector>
#include <raylib.h>

class Board {
private:
    int numRows;
    int numColumns;
    std::vector<Color> colors = {
        BLACK,
        SKYBLUE,
        BLUE,
        ORANGE,
        YELLOW,
        LIME,
        RED,
        PURPLE,
        GRAY
    };
    std::vector<std::vector<int>> grid;
    
    bool isRowFull(int row);
    void clearRow(int row);
    
public:
    Board(int row = 24, int column = 10);

    int getNumRows() const;

    int getNumColumns() const;

    int getGridPosition(int row, int column) const;
    void setGridPosition(int row, int column, int value);

    void draw();

    bool isCellInside(int row, int column);

    bool isCellEmpty(int row, int column);
    
    bool isRowEmpty(int row);
    
    int clearFullRow();

    void moveRowDown(int row, int numRows);
};