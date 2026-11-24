# Tic-Tac-Toe Game in C

![Build and test](https://github.com/YOUR-USERNAME/tic-tac-toe-c/actions/workflows/build.yml/badge.svg)

A two-player, console-based Tic-Tac-Toe game written in C.

## C concepts used
- 2D arrays (3x3 board)
- Functions (board setup, display, move input, win check, draw check)
- Conditional statements and loops

## Features
- Two players take turns (X and O) by entering a cell number 1-9
- Input validation (non-numbers, out-of-range, already-taken cells)
- Detects wins (rows, columns, diagonals) and draws
- Scoreboard and play-again option
- Automated tests run on every push (GitHub Actions)

## Board layout
```
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

## Compile and run
```bash
make
./tictactoe
```
Without make: `gcc tictactoe.c -o tictactoe`

## Run the tests
```bash
make test
```
