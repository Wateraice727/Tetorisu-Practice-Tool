# Tetorisu Practice Tool (infdev version)

![Language](https://img.shields.io/badge/language-C%2B%2B-brightgreen)
![Raylib](https://img.shields.io/badge/raylib-6.0-00d4aa)
![Platform](https://img.shields.io/badge/platform-Windows%2010%20%7C%2011-blue)
![Editor](https://img.shields.io/badge/editor-VS%20Code-007ACC)
![License](https://img.shields.io/badge/license-MIT-orange)

(This project is based on the Object-Oriented Programming Major Assignment and is currently under development).
A non-AI Tetris game (it is actually hard to be honest). The inner gameplay includes Board, 7 Tetrominoes, rotations, collision detection, next blocks preview, etc.. This code is object-oriented based and well-structured, making it simple to read.

---

## History

22-30/9/2026: Started UML Building
31/9-8/10/2026: Focused on Implementation
9/10/2026: First commit on GitHub!!!

---

## Contributor (temporary)

| Name | Student-ID | Role |
|---|---|---|
| **Lê Văn Minh** | 31251028146 | **Leader**, UML Constructor, Complete Coding-Logic |
| **Trần Hoàng Đức** || Board/Grid class Implementation |
| **Nguyễn Anh Phú** || Tetrominoes classes Implementation |
| **Vương Nguyễn Minh Nhật** || Gameplay class Implementation |
| **Đặng Quốc Duy** || TetrominoQueue class Implementation |

---

## Detailed Features

| | Topic | Details |
|---|---|---|
| 🪟 | **Game loop & Window setup** | Create the game window, configure the frame rate, and structure the update/draw loop |
| 🟦 | **Board class** | Represent the (4 + 20)×10 board as a 2D array and 4 hidden rows, draw cells with colour-coded values |
| 🧩 | **Inheritance & Polymorphism** | Model all 7 tetrominoes using a bounding-grid approach across 4 rotation states. Use a Virtual-Based `Tetromino` class with 7 Derived classes (`OPiece`, `IPiece`, `TPiece`, etc.) |
| ➡️ | **Movement** | Move pieces left, right, down, and hard drop |
| 🔄 | **Rotation** | Rotate clockwise, counter clockwise, 180-degrees with state cycling and undo on invalid moves |
| 💥 | **Collision detection** | Boundary checking and cell-occupancy checks to prevent overlapping or out-of-bounds moves |
| 🔒 | **Block locking** | Lock a piece into the grid when it can no longer move down and spawn the next piece |
| 🧹 | **Row clearing** | Detect full rows, clear them, and shift all rows above downward |
| 🏆 | **Scoring** | Award 100 / 300 / 500 / 800 points for 1 / 2 / 3 / 4 line clears, plus 1 point per manual soft drop and 2 * 'Valid Empty Row' points per hard drop |
| 🖥️ | **UI** | Score display, next pieces and hold piece preview panels, Pause Button and a Game Over, Paused message |
| 🔁 | **Game reset** | Restart the game by pressing 'R' after Game Over |

---

## In the Future

Building another gamemode like Sprint (How fast can you clear 40L), Ultra (highest score in 2 min) and Grandmaster.
Creating an AI-Agent which can play PvP against player.

