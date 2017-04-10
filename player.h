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
  virtual int makeMove(bool p1) = 0;
  virtual ~Player();
};
class Human: public Player{
public:
  void checkHuman();
  int makeMove(bool p1);
  Human(Grid *grid);
  ~Human();
};
class AI: public Player{
  Node* lookAhead(Node* n, int steps,bool humanMove);
  int alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER, int depth);
  int heuristic(Node* n);
  int evalBoard(Node* n);
  int findPotentialWin(Node *n);
  int potential4(Node *n);
  int randDrop();
  const int IQ;
public:
  void checkHuman();
  int makeMove(bool p1);
  AI(Grid *g,int iq);
  ~AI();
};

#endif
