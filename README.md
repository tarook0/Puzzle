# Puzzle Game with OpenGL Modern

This is a puzzle game built using modern OpenGL (version 3.3+) and C++. The game features a variety of puzzle levels that the player must solve by manipulating blocks on a grid.

## Features

- Modern OpenGL graphics with support for shaders and textures
- Dynamic camera control and movement
- Customizable game board with adjustable grid size and block colors
- Smooth animation and visual effects
- Intuitive user interface with mouse and keyboard controls

## Getting Started

To run the game, you will need to have the following dependencies installed:

- C++ compiler (e.g., GCC, Clang, MSVC)
- [GLFW](https://www.glfw.org/) library for window management and input
- [GLAD](https://glad.dav1d.de/) library for OpenGL function loading
- [GLM](https://glm.g-truc.net/0.9.9/index.html) library for math operations

Once you have these dependencies installed, you can follow these steps to build and run the game:

1. Clone the repository:'git clone https://codeberg.org/TTareqHB/Puzzle.git'
## Controls

- **Mouse**: Use the mouse to interact with the game board and UI elements.
- **Keyboard**:
- `WASD` or `Arrow Keys`: Move the camera
- `Space`: Reset the game board
- `Escape`: Quit the game

## Customization

You can customize the game by modifying the following parameters in the `include/config.hpp` file:

- `GRID_SIZE`: The size of the game board (e.g., 5x5, 7x7)
- `BLOCK_SIZE`: The size of each block on the game board
- `BOARD_COLOR`: The color of the game board
- `BLOCK_COLOR`: The color of the blocks on the game board

## Contribute

Contributions to this project are welcome! If you find any issues or have ideas for improvements, please feel free to open an issue or submit a pull request.