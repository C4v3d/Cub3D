# Cub3D
Cub3D is a small **raycasting** engine written in C for the 42 school curriculum, inspired by early 3D games such as Wolfenstein 3D. It renders a 3D view from a 2D map using MiniLibX and allows the player to explore simple maze-like environments.
## Features
- Real-time 3D projection using raycasting on a 2D tile map.​
- Textured walls (up to a resolution of 512x512) with configurable north, south, east and west textures from a `.cub` configuration file.​ 
- Basic player movement (WASD/arrows) and camera rotation controls.
- Wall collision.​
## Building
From the repository root:
```bash
make
```
This will compile the `cub3D` executable and any required libraries (such as `libft` and MiniLibX).
## Usage
You can run the engine by providing a valid `.cub` map:
`./cub3D path/to/map.cub`
The `.cub` file must define:
- Texture paths for each wall orientation: `NO`, `SO`, `WE`, `EA`.  ​
- Floor (`F`) and ceiling (`C`) colors in RGB format.​
- A map composed only of `0`, `1`, `N`, `S`, `E`, `W` characters, fully enclosed by walls.
If the configuration is invalid (missing elements, open map, multiple player spawns, etc.), the program will stop and outputs the corresponding error.
## Controls
The engine handle basics control such as :
- `W` / `S` or Up / Down arrows: Move forward / backward.
- `A` / `D` or Left / Right arrows: Strafe.
- `Esc`: Close the window and exit the program.​
- `Right-Arrow` / `Left-Arrow`: Rotate the camera angle.
## Project Goals
Since this project was developed during the 42 common core, it was created under many constraints. Here are its main goals:
- Practice low-level graphics programming using MiniLibX and event hooks.​
- Learn how raycasting converts a 2D map into a 3D first-person view.​
- Improve skills in parsing custom configuration formats and handling robust error checking.
