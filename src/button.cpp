#include "button.hpp"

Button::Button(const char* imagePath, Vector2 position, float scale) {
    Image image = LoadImage(imagePath);
    int scaledWidth = image.width * scale;
    int scaledHeight = image.height * scale;
    ImageResize(&image, scaledWidth, scaledHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    this->position = position;
}

Button::~Button() { UnloadTexture(texture); }

void Button::draw() { DrawTextureV(texture, position, WHITE); }

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {
    Rectangle rect = { 
        position.x, 
        position.y, 
        (float)texture.width, 
        (float)texture.height 
    };
    return CheckCollisionPointRec(mousePos, rect) && mousePressed;
}