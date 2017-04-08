#include <algorithm>
#include "node.h"
#include "grid.h"
#include <climits>

using namespace std;

int heuristic(Node node){
  return 1;
}

int negamax(Node node,int depth,int color){
    if ( depth == 0 || node.state.isWon()){
      return color * heuristic(node);
    }

    int bestValue = INT_MIN;
    foreach child of node
        v := −negamax(child, depth − 1, −color)
        bestValue := max( bestValue, v )
    return bestValue
  }
