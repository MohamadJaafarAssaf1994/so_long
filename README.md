*This project has been created as part of the 42 curriculum by mohassaf.*

# so_long

## Description

`so_long` is a small 2D game written in C using MiniLibX as part of the 42 curriculum.
The goal of the project is to build a simple graphical game while practicing file
parsing, map validation, event handling, memory management, and basic rendering.

In this project, the player moves through a map, collects every collectible, and then
reaches the exit to win. The map must respect a set of rules before the game starts:
it must be rectangular, surrounded by walls, contain valid characters only, include
exactly one player start, exactly one exit, at least one collectible, and have a valid
path.

This repository also includes map validation logic, animated player sprites, enemy
movement, and a move counter displayed in the game window.

## Instructions

### Requirements

- A C compiler such as `cc`
- `make`
- X11 development libraries
- MiniLibX for Linux

This repository already includes `libft`.
You should upload the minilbx_linux from https://github.com/42paris/minilibx-linux
### Compilation

Build the project with:

```bash
make
```

Clean object files with:

```bash
make clean
```

Remove object files and the executable with:

```bash
make fclean
```

Rebuild everything with:

```bash
make re
```

For bonus
```bash
make bonus
```

### Execution

Run the game with a valid map name:

```bash
./so_long maps/valid_path.ber
```
Or

```bash
./so_long_bonus maps/valid_path.ber
```

Example available maps:

- `valid_path.ber`
- `invalid_right_wall.ber`
- `missing_characters.ber`

### Controls

- `W` to move up
- `A` to move left
- `S` to move down
- `D` to move right
- `ESC` to quit the game

## Resources

### References

- 42 subject and project guidelines for `so_long`
- MiniLibX documentation: `minilibx-linux/README.md`
- All assets from https://itch.io/
- Images editing: https://www.online-image-editor.com/  https://imageconvert.org/png-to-xpm

### AI Usage

AI was used as a support tool during development, mainly for:

- helping draft documentation for this repository
- clarifying debugging steps such as Valgrind usage

All code choices, integration, testing, and final validation remained under my control.

## Project Structure

- `so_long.c`: program entry point
- `parse*.c` and `parsing_*`: map loading and validation
- `run_game_*.c`: gameplay loop and player/enemy behavior
- `game_design.c`: rendering and texture loading
- `textures/`: XPM assets
- `maps/`: test and example maps
- `libft/`: personal C library used by the project
- `minilibx-linux/`: graphics library used for rendering
