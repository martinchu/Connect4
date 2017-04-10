# Connect4 (Text Version)

## Description
This program is modelled after Connect 4, a two-player connection game in which the players first choose a color and then take turns dropping colored discs from the top into a seven-column, six-row vertically suspended grid.

- The pieces fall straight down, occupying the next available space within the column.

- The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one’s own discs.

The Target of the Aritifical Intelligence is win at least 60%. The Aritifical Intelligence is applying the [minimax algorithm](https://en.wikipedia.org/wiki/Minimax) and alpha-beta pruning in order to stop the potential losses and exploit potential victories.

The AI has to simulate the future states by creating a tree of all possible scenarios. The height of the tree will depend on how many steps AI will be looking ahead. If the AI is going to 2 steps ahead (provided the opponent will not win in the next move regardless), it is going to generate 7^2 = 49 future states.

To tak computational cost and time complexity into account, the default IQ parameter for the AI is 3. i.e. AI will be looking 3 steps ahead when it decides to make a move.

## Installation

1. Clone or Download the reposity. If you clone the reposity via command line, please disregard step 2.

2. Extract the zip file

3. Open Terminal

4. type
```
   cd Path/to/Connect4/Directory/
```

5. Type
```
   make
```

6. Type
```
   ./c4
```
   and start the game!

### Installation Troubleshoot
If the X11/Xlib.h is not found during step 5, type
```
sudo apt-get install libx11-dev
```
and the error should be resolved.


## Structure

C++ is chosen due to its well-rounded implementation of object-oriented programming.

The following objects are created:
- __TextDisplay__: Responsible for outputting the Board to the Command Line
- __Grid__: Contains 7x6 cells and helper functions & fields that helpe AI decide its decision-making process. It will also check if one of the players won the game
- __Cell__: Each Cell will notify the display object (Grpahical or Text)
- __Node__: a Tree Structure that contains a Board for the AI to evaluate future states
- __Player__: a Pure Virtual Class that adds/drops checkers to the board, i.e. play the game
  -__AI__: Aritifical Intelligence that analyzes the current Board and drops the checker to the right columns
  -__Human__: Human Player for both mode
- __Window__: GUI (not implemented yet, pending further versions)

A

## Reference
- __minimax algorithm__: [https://en.wikipedia.org/wiki/Minimax](https://en.wikipedia.org/wiki/Minimax)

-__Inspirations regarding minimax algorithm__: [http://roadtolarissa.com/connect-4-ai-how-it-works/](http://roadtolarissa.com/connect-4-ai-how-it-works/)

- Also,__MyPersonalWebsite__: [martinchu.xyz](martinchu.xyz)




Link to other projects or code you’re particularly proud of.
