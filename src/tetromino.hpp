#pragma once
#include <vector>
#include <raylib.h>

struct Position {
    int row;
    int column;
};

class Tetromino {
protected:
    std::vector<std::vector<Position>> cells;
    Position startOffset;
    Position offset;
    int id;
    Color color;

private:
    int rotationState;

public:
    
    Tetromino();
    virtual ~Tetromino() = default;

    int getID() const;

    Color getColor() const;
    
    void draw(int offsetX, int offsetY, Color nameColor);
    virtual void drawPreview(int offsetX, int offsetY) = 0;

    std::vector<Position> getCellPositions();

    void rotateClockwise();
    void rotateCounterClockwise();
    void rotate180();

    void move(int row, int column);

    void reset();
};