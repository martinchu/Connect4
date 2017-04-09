#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include "player.h"
#include "grid.h"
#include "node.h"

using namespace std;

void Human::checkHuman(){
  cout<<"I am HUMAN!!"<<endl;
}
void Human::makeMove(bool p1){
  int linenum;
  cout<<"Player, Please make move now."<<endl;
  cout<<"Please select the line you want to drop your token: ";
  bool checkInput = true;
	while(checkInput){
		cin>>linenum;
		if(linenum > 7 || linenum < 1){
			cout<<"Invalid Line. Please Choose Again";
		}
		else if(cin.fail()){
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter an Integer only." << endl;
		}
		else checkInput = false;
	}
  Player::g->dropChecker(linenum-1,p1);
}
Human::Human(Grid *grid){
  Player::g = grid;
}
AI::AI(Grid* grid){
  Player::g = grid;
}
void AI::checkHuman(){
	cout<<"I am not HUMAN!!"<<endl;

}
int AI::evalBoard(Node *n){
  
}
Node* AI::lookAhead(int steps){
  return 0;
}
int AI::heuristic(Node *node){
  return 1;
}
int AI::alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER, int depth){
  if(n->children.size()==0||depth==0){
    // if it is a terminal node
    if(n->children.size()==0){
      return n->num;
    }
    else{
      return heuristic(n);
    }
  }
  else{
    int v;
    // if it is a parent node
    if(MAXPLAYER==true){
      // Max Player's Turn
      v = INT_MIN;
      for(unsigned int i = 0; i< n->children.size();i++){
        v = max(v, alphabeta(n->children[i], alpha, beta, false,depth-1));
        alpha = max(alpha, v);
        if(beta<=alpha)break;
      }
    }
    else{
      // Min Player's Turn
      v = INT_MAX;
      for(unsigned int i = 0; i< n->children.size();i++){
        int temp = alphabeta(n->children[i], alpha, beta, true,depth-1);
        v = min(v, temp);
        beta = min(beta, v);
        if(beta<=alpha)break;
      }
      cout<<"v: "<<v<<endl;

    }

    return v;
  }
  return -1;
}

void AI::makeMove(bool p1){
  Node *futureStates = lookAhead(3);//look 3 steps ahead
  Player::g->dropChecker(alphabeta(futureStates,INT_MIN,INT_MAX,true,3),false);
}
