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
	bool checkInput = true;
	// Ask User to pick a mode
	while(checkInput){
		cin>>mode;
		if(mode > 2 || mode < 1){
			cout<<"Invalid Number. Please Choose Again";
		}
		else if(cin.fail()){
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter an Integer only." << endl;
		}
		else checkInput = false;
	}
	Human *h1 = new Human(g);
	Human *h2 = new Human(g);

	AI *ai = new AI(g);
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
	// bool p1turn = true;
	// while(true){
	// 	cout<<"g->getWinner(): "<<g->getWinner()<<endl;
	// 	if(g->getWinner()!='F'){
	// 		// Find Winner
	// 		cout<<"Player "<<g->getWinner()<<" wins!!!"<<endl;
	// 		break;
	// 	}
	// 	else if(g->isFilled()==true){
	// 		cout<<"This is a draw!"<<endl;
	// 		break;
	// 	}
	// 	else{
	// 		Player * p = (p1turn? p1: p2);
	// 		if(p1turn) cout<<"It is Player 1's turn."<<endl;
	// 		else cout<<"It is Player 2's turn."<<endl;
	// 		p->makeMove(p1turn);
	// 		cout<<*g;
	// 		p1turn = !p1turn;
	// 	}
	// }
	// g->printAddress();
	if(memtest>=100){
		cout<<"deleting grid"<<endl;
	}
	delete g;
	delete h1;
	delete h2;
	delete ai;
}
