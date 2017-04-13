#include "textdisplay.h"
#include <string>
#include <iostream>
using namespace std;
int ttest=0;
const char TextDisplay::getCord(int r, int c){
	return theDisplay[r][c];
}
TextDisplay::TextDisplay(const TextDisplay& oldtd):rowSize(oldtd.rowSize),colSize(oldtd.colSize){
	theDisplay= new char*[rowSize];
	for(int i=0;i<rowSize;i++){
		theDisplay[i]=new char[colSize];
	}
	for(int j=0;j<rowSize;j++){
		for(int k=0;k<colSize;k++){
			theDisplay[j][k]=oldtd.theDisplay[j][k];
			// cout<<theDisplay[j][k];
		}
		// cout<<endl;
	}
}
TextDisplay::TextDisplay(int r, int c):rowSize(r),colSize(c){
	// char**
	theDisplay= new char*[rowSize];
	for(int i=0;i<rowSize;i++){
		theDisplay[i]=new char[colSize];
	}
	for(int j=0;j<rowSize;j++){
		for(int k=0;k<colSize;k++){
			theDisplay[j][k]='0';
		}
	}
}
void TextDisplay::notify(int r, int c, char ch){
	if(ttest>=10){
		cout<<"ch: "<<ch<<endl;
	}
	theDisplay[r][c]=ch;
	// colourCount[ch-'1']++;
	// ^ this line is no longer useful. commented out at the moment
}
bool TextDisplay::isFilled(){
	for(int i=0;i<colSize;i++){
		if(theDisplay[0][i]=='0')return false;
	}
	return true;
}
char TextDisplay::getWinner(){
	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			if(theDisplay[i][j]!='0'){
				if(ttest>=1)cout<<theDisplay[i][j]<<endl;
				// Check for Horizontal
				if(j <= colSize-4){//Check the left
					if(theDisplay[i][j]==theDisplay[i][j+1]&&theDisplay[i][j]==theDisplay[i][j+2]&&theDisplay[i][j]==theDisplay[i][j+3]){
						return theDisplay[i][j];
					}
				}
				else if(j >= 3){//Check the Right
					if(theDisplay[i][j]==theDisplay[i][j-1]&&theDisplay[i][j]==theDisplay[i][j-2]&&theDisplay[i][j]==theDisplay[i][j-3]){
						return theDisplay[i][j];
					}
				}
				// Check for Vertical
				if(i <= rowSize-4){//Check the Up
					if(theDisplay[i][j]==theDisplay[i+1][j]&&theDisplay[i][j]==theDisplay[i+2][j]&&theDisplay[i][j]==theDisplay[i+3][j]){
						return theDisplay[i][j];
					}
				}
				else if(i >= 3){//Check the down
					if(theDisplay[i][j]==theDisplay[i-1][j]&&theDisplay[i][j]==theDisplay[i-2][j]&&theDisplay[i][j]==theDisplay[i-3][j]){
						return theDisplay[i][j];
					}
				}
				// Check for Diagonal
				if(j <= colSize-4 && i <= rowSize-4){
					if(theDisplay[i][j]==theDisplay[i+1][j+1]&&theDisplay[i][j]==theDisplay[i+2][j+2]&&theDisplay[i][j]==theDisplay[i+3][j+3]){
						return theDisplay[i][j];
					}
					/*
					X 0 0 0
					0 x 0 0
					0 0 x 0
					0 0 0 x
					*/
				}
				if(j <= colSize-4 && i >= 3){
					if(theDisplay[i][j]==theDisplay[i-1][j+1]&&theDisplay[i][j]==theDisplay[i-2][j+2]&&theDisplay[i][j]==theDisplay[i-3][j+3]){
						return theDisplay[i][j];
					}
				}

				if(j >= 3 && i <= rowSize-4){
					if(theDisplay[i][j]==theDisplay[i+1][j-1]&&theDisplay[i][j]==theDisplay[i+2][j-2]&&theDisplay[i][j]==theDisplay[i+3][j-3]){
						return theDisplay[i][j];
					}
				}
				if(j >= 3 && i >= 3){
					if(theDisplay[i][j]==theDisplay[i-1][j-1]&&theDisplay[i][j]==theDisplay[i-2][j-2]&&theDisplay[i][j]==theDisplay[i-3][j-3]){
						return theDisplay[i][j];
					}
				}
			}
		}
	}
	return 'F';
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
	cout<<"column: 1 2 3 4 5 6 7"<<endl<<endl;
	for(int r=0;r<td.rowSize;r++){
		out<<"        ";
		if(ttest>=10){
			cout<<"r: "<<r<<endl;
			// cout<<"gridSize: "<<td.gridSize<<endl;
		}
		for(int c=0;c<td.colSize;c++){
			if(ttest>=10){
				cout<<"c: "<<c<<endl;
			}
			out<<td.theDisplay[r][c]<<" ";
		}
		out<<endl<<endl;
	}
	return out;
}
