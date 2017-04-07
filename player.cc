#include <string>
#include <iostream>
#include "player.h"

using namespace std;

void Human::checkHuman(){
  cout<<"I am HUMAN!!"<<endl;
}
void Human::makeMove(){
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

}
void AI::checkHuman(){

}
void AI::makeMove(){

}
