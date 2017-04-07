#include <iostream>
using namespace std;
int main(){
	char** theDisplay= new char*[5];
	for(int i=0;i<5;i++){
		theDisplay[i]=new char[5];
	}
	theDisplay[0][0]='n';
	theDisplay[0][1]='i';
	theDisplay[0][2]='g';
	theDisplay[0][3]='g';
	theDisplay[0][4]='a';

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<theDisplay[i][j];
		}
		cout<<endl;
	}
	/*int** ary = new int*[sizeX];
	for(int i = 0; i < sizeX; ++i)
    ary[i] = new int[sizeY];*/
}
