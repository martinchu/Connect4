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
  int randDrop();
  const int IQ;
  Node * decisionTree;
public:
  void checkHuman();
  int makeMove(bool p1);
  AI(Grid *g,int iq);
  ~AI();
};

#endif
