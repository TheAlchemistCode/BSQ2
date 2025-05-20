# BSQ Project

## Overview
The BSQ (Biggest Square) project is designed to find the largest square of empty spaces in a given map represented by a grid of characters. The map can be provided through a file or standard input. The project utilizes dynamic programming to efficiently determine the largest square and outputs the modified map with the square marked.

## File Structure
```
BSQ
├── include
│   └── bsq.h          # Common header file with structure definitions and function prototypes
├── src
│   ├── main.c        # Entry point of the application
│   ├── map_parser.c  # Responsible for reading and validating the input map
│   ├── solver.c      # Implements the logic to find the largest square
│   ├── printer.c     # Modifies and prints the final map
│   └── utils.c       # Contains helper functions for string handling and memory management
├── Makefile           # Build script for compiling the project
└── README.md          # Documentation for the project
```

## Compilation
To compile the project, navigate to the project directory and run the following command:

```
make
```

This will generate the executable named `bsq`.

## Usage
To run the program, you can provide a map file as an argument or use standard input. The map should consist of characters representing empty spaces, obstacles, and filled squares. The characters used are defined in the `t_map` structure in `bsq.h`.

### Example
To run the program with a map file:
```
./bsq map.txt
```

To use standard input:
```
./bsq
```
Then, enter the map followed by an EOF (Ctrl+D on Unix/Linux or Ctrl+Z on Windows).

## Map Format
The map format consists of:
- The first line specifies the number of rows and columns, followed by the characters used for empty spaces, obstacles, and filled squares.
- Subsequent lines represent the map grid.

### Example Map
```
5.ox
.....
..o..
.....
..o..
.....
```

## License
This project is licensed under the MIT License. See the LICENSE file for more details.