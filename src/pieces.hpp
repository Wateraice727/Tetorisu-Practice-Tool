#include "tetromino.hpp"

class IPiece : public Tetromino {
public:
    IPiece();

    void drawPreview(int offsetX, int offsetY) override;
};

class JPiece : public Tetromino {
public:
    JPiece();

    void drawPreview(int offsetX, int offsetY) override;
};

class LPiece : public Tetromino {
public:
    LPiece();
    
    void drawPreview(int offsetX, int offsetY) override;
};

class OPiece : public Tetromino {
public:
    OPiece();

    void drawPreview(int offsetX, int offsetY) override;
};

class SPiece : public Tetromino {
public:
    SPiece();

    void drawPreview(int offsetX, int offsetY) override;
};

class ZPiece : public Tetromino {
public:
    ZPiece();

    void drawPreview(int offsetX, int offsetY) override;
};

class TPiece : public Tetromino {
public:
    TPiece();

    void drawPreview(int offsetX, int offsetY) override;
};