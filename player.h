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
  virtual void makeMove(bool p1) = 0;
  virtual ~Player();
};
class Human: public Player{
public:
  void checkHuman();
  void makeMove(bool p1);
  Human(Grid *grid);
  ~Human();
};
class AI: public Player{
  Node* lookAhead(int steps);
  int alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER, int depth);
  int heuristic(Node* n);
  int evalBoard(Node* n);
public:
  void checkHuman();
  void makeMove(bool p1);
  AI(Grid *g);
  ~AI();
};

#endif
