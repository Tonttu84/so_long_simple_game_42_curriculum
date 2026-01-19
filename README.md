# so_long_simple_game_42_curriculum

so_long_simple_game_42_curriculum

A small 2D game written in C as part of the 42 curriculum. You control a tiny hero who must collect all coins, avoid zombies, and reach the exit. The project uses MiniLibX (a minimal graphics library) and demonstrates event handling, rendering, memory management, and basic game logic.

Originally the project was not inside a Docker but as I later learned to use Dockers I added Docker in order to make it more pleasant to use. The limitation of this approach that the same map is always launched unless you edit the launch line. 

Gameplay Preview

(GIF or video placeholder — add your media here)
[media/so_long_demo.gif]

Gameplay

Move with W A S D or arrows

Collect all coins

Avoid or kill the zombies

Reach the exit once all coins are collected

Maps are simple .ber files located in the maps/ directory

Running the Game (Docker — recommended)

This repository includes a Docker setup so the game runs on Linux, macOS, and Windows (WSL2) without installing MLX or system dependencies.

Clone the repository:
git clone https://github.com/Tonttu84/so_long_simple_game_42_curriculum so_long
cd so_long

Run the game:
make

The Makefile automatically (untested on Windows and MacOS):

Detects your OS

Builds the Docker image

Launches the game window

Stop the game:
make stop

Clean everything:
make clean

License

This project is part of the 42 school curriculum and is provided for educational purposes.