#Connect4 (Text Version)

##Description

##Installation

1. Clone or Download the reposity. If you clone the reposity via command line, please disregard step 2.
2. Extract the zip file
3. Open Terminal
4. type
```
cd Path/to/Connect4/Directory/
```
5. type
```
make
```
6. type
```
./c4
```
and start the game!

###Installation Troubleshoot
If the X11/Xlib.h is not found during step 5, type
```
sudo apt-get install libx11-dev
```
and the error should be resolved.


##Structure

C++ is chosen due to its well-rounded implementation of object-oriented programming.

The following objects are created:
- __TextDisplay__: Responsible for outputting the Board to the Command Line
- __Grid__: Contains 7x6 cells and helper functions & fields that helpe AI decide its decision-making process
- __Cell__: Each Cell will notify the display object (Grpahical or Text)
- __Node__: a Tree Structure that contains a Board for the AI to evaluate future states
- __Player__: a Pure Virtual Class that adds/drops checkers to the board, i.e. play the game
  -__AI__: Aritifical Intelligence that analyzes the current Board and drops the checker to the right columns
  -__Human__: Human Player for both mode
- __Window__: GUI (not implemented yet, pending further versions)

A

##Reference


Link to other projects or code you’re particularly proud of.
