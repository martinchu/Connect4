#ifndef __NODE_H_
#define __NODE_H_

class Grid;
class Node {
public:
    Grid state;
    Vector<Node> children;
};

#endif
