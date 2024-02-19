# Welcome to So_Long

![Game Screenshot](https://i.imgur.com/QtqAYtO.png)

## Description:
So_Long is a simple 2D game project implemented in C programming language using the MiniLibX graphical library.
The game presents a basic game loop where the player navigates a character through a maze-like environment,
collecting items while avoiding obstacles to reach the goal.

Table of Contents:
Introduction
Features
Installation
Usage
Controls
Gameplay
Contributing
License

### 1. Introduction <a name="introduction"></a>
So_Long is a project developed as part of the 42 school curriculum.
It aims to introduce students to the basics of game development and graphics programming using C and the MiniLibX library.

### 2. Features <a name="features"></a>
Simple 2D graphics rendering.
Maze-like environment generation.
Character movement and collision detection.
Item collection and goal-reaching mechanics.
3. Installation <a name="installation"></a>
To install and run So_Long on your system, follow these steps:

Clone the repository to your local machine:
bash
```bash
git clone [repository_url]
```
Navigate to the project directory:
```bash
cd so_long
```
Compile the project using the provided Makefile:
```bash
make
```
Run the executable:
```bash

./so_long [map_file]
```
Replace [map_file] with the path to the map file you want to load.

### 4. Usage <a name="usage"></a>
The game loads the map specified as a command-line argument.
Navigate the character using the arrow keys to collect items and reach the goal.
Press ESC key to exit the game.

### 5. Controls <a name="controls"></a>
Arrow Keys: Move the character up, down, left, or right.
ESC: Exit the game.

### 6. Gameplay <a name="gameplay"></a>
Navigate through the maze-like environment, collect items represented by specific symbols, and reach the goal indicated on the map. Avoid obstacles and enemies that hinder your progress. The game ends when the character reaches the goal or collides with an obstacle.

### 7. Contributing <a name="contributing"></a>
Contributions to So_Long are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.
