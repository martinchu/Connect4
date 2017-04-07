#include "textdisplay.h"
#include <string>
#include <iostream>
using namespace std;
int ttest=0;
TextDisplay::TextDisplay(int n):gridSize(n){
	// char**
	theDisplay= new char*[gridSize];
	for(int i=0;i<gridSize;i++){
		theDisplay[i]=new char[gridSize];
	}
	for(int j=0;j<gridSize;j++){
		for(int k=0;k<gridSize;k++){
			theDisplay[j][k]='0';
			// cout<<theDisplay[j][k];
		}
		// cout<<endl;
	}
	/*for(int a=0;a<gridSize;a++){
		for(int b=0;b<gridSize;b++){
			cout<<theDisplay[a][b];
		}
		cout<<endl;
	}
	if(this->theDisplay==0){
		cout<<"theDisplay is not null after the loop"<<endl;
	}*/
	// cout<<(*this);
}
void TextDisplay::notify(int r, int c, char ch){
	if(ttest>=10){
		cout<<"ch: "<<ch<<endl;
	}
	theDisplay[r][c]=ch;
	colourCount[ch-'0']++;
}
bool TextDisplay::isFilled(){
	char temp= theDisplay[0][0];
	for(int i=0;i<gridSize;i++){
		for(int j=0;j<gridSize;j++){
			if(ttest>=1)cout<<theDisplay[i][j]<<endl;
			if(theDisplay[i][j]!=temp){
				return false;
			}
		}
	}
	return true;
}
TextDisplay::~TextDisplay(){
	for(int i=0;i<gridSize;i++){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
	// delete [] colourCount;
}
ostream &operator<<(ostream &out, const TextDisplay &td){
	if(ttest>=10){
		cout<<"in TextDisplay::<<"<<endl;
		cout<<"gridSize: "<<td.gridSize<<endl;
		cout<<"td: "<<&td<<endl;
		cout<<"td.theDisplay: "<<td.theDisplay<<endl;
	}

	for(int r=0;r<td.gridSize;r++){
		if(ttest>=10){
			cout<<"r: "<<r<<endl;
			// cout<<"gridSize: "<<td.gridSize<<endl;
		}
		for(int c=0;c<td.gridSize;c++){
			if(ttest>=10){
				cout<<"c: "<<c<<endl;
			}
			out<<td.theDisplay[r][c];
		}
		out<<endl;
	}
	return out;
}
