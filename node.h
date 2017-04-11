#ifndef __NODE_H_
#define __NODE_H_
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Grid;

class Node {
  Grid* state;
  int route;
  int num;
  vector<Node *> children;
  int heuristic();
  int evalBoard();
  int findPotentialWin();
  int potential4();

  string id;
public:
  Node(Grid *g);
  Node();
  Node(int n);
  Node(vector<Node *>c);
  void setID(string s);
  string getID() const;
  void updateRoute(int r);
  int getRoute() const;
  Grid* getState()const;
  int getValue() const;
  void setValue(int v);
  Node* getChildren(int i);
  void setChildren(vector<Node *>c);
  const int getChildrenSize();
  int alphabeta(int alpha, int beta, bool MAXPLAYER, int depth);
  int height;
  friend std::ostream &operator<<(std::ostream &out, const Node &n);
  ~Node();
};

#endif
