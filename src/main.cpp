#include <raylib.h>
#include <iostream>
#include "gameplay.hpp"
#include "button.hpp"

double latestUpdate = 0;

int main() 
{
    const Color _1f1e33 = {31, 30, 51, 255};

    InitWindow(1280, 720, "Tetorisu2067");
    SetTargetFPS(60);
    
    Font font = LoadFontEx("src/font/monogram.ttf", 64, 0, 0);
    Button pauseButton = {
        "src/bg/pause.png",
        {10, 10},
        0.2
    };
    
    bool paused = 0;
    Gameplay game = Gameplay();
    
    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition();
        bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if (IsKeyPressed(KEY_TAB) || pauseButton.isPressed(mousePosition, isMousePressed)) 
            paused = !paused;

        if (!paused && !game.getGameOver()) {
            game.input();
            if (game.eventTrigger(1, latestUpdate)) 
                game.softDrop();
        }

        BeginDrawing();
            ClearBackground(_1f1e33);
            pauseButton.draw();
            
            DrawTextEx(font, "NEXT", {825, 25}, 38, 2, WHITE);
            DrawTextEx(font, "HOLD", {315, 25}, 38, 2, WHITE);
            DrawTextEx(font, "SCORE", {825, 580}, 38, 2, WHITE);
            if (paused)
                DrawTextEx(font, "PAUSED", {300, 450}, 38, 2, WHITE);
            else if (game.getGameOver()) {
                DrawTextEx(font, "GAME OVER", {300, 450}, 38, 2, WHITE);
                if (IsKeyPressed(KEY_R)) game.reset();
            }

            char scoreText[10];
            sprintf(scoreText, "%d", game.getScore());
            Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
            DrawTextEx(font, scoreText, {825 + (130 - textSize.x) / 2, 630}, 38, 2, WHITE);

            game.draw();
        EndDrawing();
    }
    
    CloseWindow();
}