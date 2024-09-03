# 42_so_long

`so_long` is a small 2D game developed using the MiniLibX (mlx) library, which handles window management, rendering, and user input. It is part of the 42 curriculum. The game is inspired by classic arcade-style games and involves navigating a character through a map, collecting coins, and exiting through a door. The game map is defined by a simple text file that is parsed to generate the game environment.

This project provides valuable experience in the following areas:

- **2D Game Design**: Learn how to design and implement a simple 2D game with basic mechanics.
- **Event Handling**: managing user input and rendering game state changes in real-time.
- **File Parsing**:  parsing and interpreting custom file formats to generate dynamic game environments.
- **Graphics Programming**: hands-on experience with the MiniLibX library, rendering sprites and managing window events.
  
![ScreenRecording2024-09-03at5 00 10PM-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/f4398eba-5fc5-48c1-ae2f-cb33ee526122)

## Usage

To set up and run `so_long`, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/asemsey/42_so_long.git
    cd 42_so_long
    ```

3. Compile the project using the Makefile. the MinilibX library is installed automatically.

    ```bash
    make
    ```

4. Run the program with a map file as an argument:

    ```bash
    ./so_long path/to/map.ber
    ```

### Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **ESC**: Exit the game

## Map File Format

The map file is a plain text file with a `.ber` extension that defines the layout of the game. The map is represented as a grid of characters:
Some example map files are provided in the `maps` directory.

- **`1`**: Wall
- **`0`**: Empty space
- **`P`**: Player start position
- **`C`**: Coin
- **`E`**: Exit door
