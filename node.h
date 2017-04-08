#ifndef __NODE_H_
#define __NODE_H_
#include <vector>
#include <iostream>
using namespace std;

class Grid;

class Node {
public:
    Grid* state;
    int num;
    int height;
    vector<Node *> children;
    Node(int num);
    Node(vector<Node *>c);
    friend std::ostream &operator<<(std::ostream &out, const Node &n);
    ~Node();
};

#endif
