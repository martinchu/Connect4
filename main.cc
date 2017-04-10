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
int moves=0;
int mtest=0;
int gsize=0;
int memtest = 100;

void setGrid(istream &in, Grid *g){
	if(mtest>=50)cout<<"in setGridColor"<<endl;
	int r,c, color;
	while(in>>r){
		if(mtest>=20)cout<<"about to get line"<<endl;
		in>>c;
		if(mtest>=20)cout<<"done(/skipped?) getline"<<endl;
		if(r==-1&&c==-1)break;
		in>>color;
		if(r<gsize&&c<gsize)g->init(r,c,color);
	}
	if(mtest>=10)cout<<"about to output grid"<<endl;
	cout<<(*g);
}


int main(){
	// bool gaming=false;
	Grid *g;
	string s;
	g= new Grid();
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
	int intelligence = 2;
	// determine how smart the AI will be.
	AI *ai = new AI(g,intelligence);
	Player * p1 = h1;
	Player * p2;
	if (mode ==1) {
		p2 = h2;
	}
	else{
		p2 = ai;
	}

	if(mtest>=10000){
		cout<<*g;
		cout<<"going into while loop"<<endl;
		cout<<"check Player 1: "<<endl;
		p1->checkHuman();
		cout<<"check Player 2: "<<endl;
		p2->checkHuman();
	}
	cout<<"Load Game?(Y/N)";
	cin>>s;
	if(s =="Y"||s=="y"){
		cout<<"please insert file name."<<endl;
		string inf;
		cin>>inf;
		ifstream infile(inf.c_str());
		setGrid(infile,g);
	}
	bool p1turn = true;
	while(true){
		if(mtest==1000)cout<<"g->getWinner(): "<<g->getWinner()<<endl;
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
	if(memtest>=100)cout<<"deleting grid"<<endl;
	delete h1;
	delete h2;
	delete ai;
}
