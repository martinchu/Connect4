#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include "player.h"
#include "grid.h"
#include "node.h"

using namespace std;

int main(){
  Grid *g;
	string s;
	g= new Grid();
	g->init();
	Grid * temp = new Grid(*g);
}
