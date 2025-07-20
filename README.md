# 🎮 My First 2D Game: So_Long

![Game Screenshot](https://i.imgur.com/QtqAYtO.png)

## 📝 Description

**So_Long** is a simple 2D maze game built in C using the **MiniLibX** graphical library.  
The goal? Navigate a character through a maze, **collect items**, avoid obstacles, and reach the **exit** to win.

This project was developed as part of the **42 school curriculum**, focusing on game loops, input handling, rendering, and basic graphics programming.

---

## 📚 Table of Contents

1. [Introduction](#1-introduction)
2. [Features](#2-features)
3. [Installation](#3-installation)
4. [Usage](#4-usage)
5. [Controls](#5-controls)
6. [Gameplay](#6-gameplay)
7. [Contributing](#7-contributing)

---

### 1. 📖 Introduction

**So_Long** introduces students to the fundamentals of:

- Game development in C
- Real-time 2D rendering
- Event-driven programming
- Resource and memory management

Built with the **MiniLibX** library, this game encourages clean structuring of game logic and rendering code.

---

### 2. ✨ Features

- 🔲 Simple 2D tile-based rendering
- 🧩 Maze-like map parsing from files
- 🚶 Character movement and wall collision detection
- 💎 Item collection and scoring
- 🎯 Exit zone to complete the level
- ❌ Game over on enemy collision (optional/bonus)

---

### 3. ⚙️ Installation

To build and run **So_Long**, follow these steps:

1. **Clone the repository**:
```bash
   git clone <repository-url>
```

```bash
git clone the repo
```
- Navigate to the project directory:

```bash
cd so_long
```
- Compile the project using the provided Makefile:

```bash
make
```
- Run the executable:

```bash
./so_long <any map file>
```
Replace <"any map file"> with the path to the map file you want to load.

### 4. Usage <a name="usage"></a>
The game loads the map specified as a command-line argument.
Navigate the character using the arrow keys to collect items and reach the goal.
Press ESC key to exit the game.

### 5. Controls <a name="controls"></a>
| Key     | Action          |
| ------- | --------------- |
| ← ↑ ↓ → | Move the player |
| ESC     | Exit the game   |

### 6. Gameplay <a name="gameplay"></a>
6. 🧠 Gameplay
Navigate the maze to collect items and reach the goal.
You must collect all collectibles (C) before you can use the exit (E).

The map is made up of simple ASCII-based tiles:

Symbol | Meaning
P      | Player start
E	   | Exit
C	   | Collectible
1	   | Wall/Obstacle
0	   | Empty space

### 7. Contributing <a name="contributing"></a>
Contributions to So_Long are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.
