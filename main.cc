#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "textdisplay.h"
#include "cell.h"
#include "grid.h"
#include "player.h"
#include "node.h"

using namespace std;
int gsize=0;

void setGrid(istream &in, Grid *g){
	int r,c, color;
	while(in>>r){
		in>>c;
		if(r==-1&&c==-1)break;
		in>>color;
		if(r<gsize&&c<gsize)g->init(r,c,color);
	}
	cout<<(*g);
}


int main(){
	// bool gaming=false;
	Grid *g;
	string s;
	int row = 6;
	int col = 7;
	g= new Grid(row, col);
	g->init();
	cout<<"Welcome to Connect4. Type 1 or 2 to choose your mode:"<<endl;
	cout<<"1: Play with another Player"<<endl;
	cout<<"2: Play with PC"<<endl;
	int mode;
	// bool checkInput = true;
	// Ask User to pick a mode
	while(true){
		if(cin>>mode){
			if(mode > 2 || mode < 1){
				cout<<"Invalid Number. Please Choose Again";
			}
			else break;
		}
		else {
			if(cin.eof())return -1;
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter an Integer only." << endl;
		}
	}
	Human *h1 = new Human(g);
	Human *h2 = new Human(g);
	int intelligence = 6;
	// determine how smart the AI will be.
	bool aiMoveFirst = false;
	// determine if AI will move first

	AI *ai = new AI(g,intelligence,aiMoveFirst);
	Player * p1 = h1;
	Player * p2;
	if (mode ==1) {
		p2 = h2;
	}
	else{
		p2 = ai;
	}
	// cout<<"Load Game?(Y/N)";
	// cin>>s;
	// if--track-origins=yes (s =="Y"||s=="y"){
	// 	return -1;
	// 	// cout<<"please insert file name."<<endl;
	// 	// string inf;
	// 	// cin>>inf;
	// 	// ifstream infile(inf.c_str());
	// 	// setGrid(infile,g);
	// }
	cout<<(*g);
	bool p1turn = true;
	while(true){
		if(g->getWinner()!='F'){
			// Find Winner
			cout<<"Player "<<g->getWinner()<<" wins!!!"<<endl;
			break;
		}
		else if(g->isFilled()==true){
			cout<<"This is a draw!"<<endl;
			break;
		}
		else{
			Player * p = (p1turn? p1: p2);
			if(p1turn) cout<<"It is Player 1's turn."<<endl;
			else cout<<"It is Player 2's turn."<<endl;
			int eof = p->makeMove(p1turn);
			if(eof ==-1 )break;
			cout<<*g;
			p1turn = !p1turn;
		}
	}
	delete g;
	delete h1;
	delete h2;
	delete ai;
}
