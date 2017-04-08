#ifndef __PLAYER_H__
#define __PLAYER_H__
// #include "grid.h"
class Grid;
class Node;
class Player{
protected:
  Grid *g;
public:
  virtual void checkHuman() = 0; //Testing Purpose;
  virtual void makeMove() = 0;
};
class Human: public Player{
public:
  void checkHuman();
  void makeMove();
};
class AI: public Player{
  Node* lookAhead(Grid *g);
  int alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER, int depth);
  int heuristic(Node* n);
public:
  void checkHuman();
  void makeMove();

};

#endif
