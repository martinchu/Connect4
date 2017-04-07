#include "textdisplay.h"
#include <string>
#include <iostream>
using namespace std;
int ttest=0;
TextDisplay::TextDisplay(int r, int c):rowSize(r),colSize(c){
	// char**
	theDisplay= new char*[rowSize];
	for(int i=0;i<rowSize;i++){
		theDisplay[i]=new char[colSize];
	}
	for(int j=0;j<rowSize;j++){
		for(int k=0;k<colSize;k++){
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
	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			if(ttest>=1)cout<<theDisplay[i][j]<<endl;
			if(theDisplay[i][j]!=temp){
				return false;
			}
		}
	}
	return true;
}
TextDisplay::~TextDisplay(){
	for(int i=0;i<rowSize;i++){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
	// delete [] colourCount;
}
ostream &operator<<(ostream &out, const TextDisplay &td){
	if(ttest>=10){
		cout<<"in TextDisplay::<<"<<endl;
		cout<<"rowSize: "<<td.rowSize<<endl;
		cout<<"colSize: "<<td.colSize<<endl;
		cout<<"td: "<<&td<<endl;
		cout<<"td.theDisplay: "<<td.theDisplay<<endl;
	}

	for(int r=0;r<td.rowSize;r++){
		if(ttest>=10){
			cout<<"r: "<<r<<endl;
			// cout<<"gridSize: "<<td.gridSize<<endl;
		}
		for(int c=0;c<td.colSize;c++){
			if(ttest>=10){
				cout<<"c: "<<c<<endl;
			}
			out<<td.theDisplay[r][c];
		}
		out<<endl;
	}
	return out;
}
