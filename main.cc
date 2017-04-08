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
int mtest=100;
int gsize=0;

void setGrid(istream &in, Grid *g){
	string s;
	if(mtest>=50){
		cout<<"in setGridColor"<<endl;
	}
	int r,c, color;
	while(in>>r){
		// if(in.eof()){
		// 	break;
		// }
		if(mtest>=20){
			cout<<"about to get line"<<endl;
		}
		// getline(in,s);
		in>>c;
		if(mtest>=20){
			cout<<"done(/skipped?) getline"<<endl;
		}
		if(r==-1&&c==-1){
			break;
		}
		in>>color;
		if(r<gsize&&c<gsize){
			g->init(r,c,color);
		}
	}
	if(mtest>=10){
		cout<<"about to output grid"<<endl;
	}
	cout<<(*g);
}
// void switchColor(Grid *g,int color){
// 	g->change(color);
// 	moves--;
// 	cout<<*g;
// }
void addChecker(Grid *g, int col){

}
int main(){
	bool gaming=false;
	Grid *g;
	string s;
	g= new Grid();
	cout<<"Welcome to Connect4. Type 1 or 2 to choose your mode:"<<endl;
	cout<<"1: Play with another Player"<<endl;
	cout<<"2: Play with PC"<<endl;
	int mode;
	bool checkInput = true;
	g->init();
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
	Human h1,h2;
	AI ai;
	Player * p1 = &h1;
	Player * p2;
	if (mode ==1) {
		p2 = &h2;
	}
	else{
		p2 = &ai;
	}

	if(mtest>=100){
		cout<<*g;
		cout<<"going into while loop"<<endl;
		cout<<"check Player 1: "<<endl;
		p1->checkHuman();
		cout<<"check Player 2: "<<endl;
		p2->checkHuman();
	}
	while(1){
		if(gaming==true){
			if(g->isWon()==true){
				cout<<"Won"<<endl;
				break;
			}
			else if(moves==0 && g->isWon()==false){
				cout<<"Lost"<<endl;
				break;
			}
		}
		if(!g){
			if(mtest>=100){
				cout<<"checked if g is null"<<endl;
			}
			if(g->isWon()==true){
				if(mtest>=100){
					cout<<"checking winning condition"<<endl;
				}
				cout<<"Won"<<endl;
				break;
			}
		}
		cin>>s;
		if(cin.eof()){
			break;
		}
		else if(s=="include"){
			string inf;
			cin>>inf;
			ifstream infile(inf.c_str());
			setGrid(infile,g);
		}
		// else if(s=="init"){
		// 	if(mtest>=20){
		// 		cout<<"initialization..."<<endl;
		// 	}
		// 	setGridColor(cin,g);
		// }
		// else if(s=="game"){
		// 	if(mtest>=2){
		// 		cout<<"moves: "<<moves<<endl;
		// 	}
		// 	cin>>moves;
		// 	if(mtest>=2){
		// 		cout<<"moves: "<<moves<<endl;
		// 	}
		// 	gaming=true;
		// }
		else if(s=="switch"){
			int color;
			cin>>color;
			// switchColor(g,color);
		}
	}
	delete g;
}

/*void setNewGrid(){
if(GridInstance){
delete GridInstance;
}
GridInstance= new Grid()
}*/
