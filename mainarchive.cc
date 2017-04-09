/*void setNewGrid(){
if(GridInstance){
delete GridInstance;
}
GridInstance= new Grid()
}*/


	// while(1){
	// 	if(gaming==true){
	// 		if(g->isWon()==true){
	// 			cout<<"Won"<<endl;
	// 			break;
	// 		}
	// 		else if(moves==0 && g->isWon()==false){
	// 			cout<<"Lost"<<endl;
	// 			break;
	// 		}
	// 	}
	// 	if(!g){
	// 		if(mtest>=100){
	// 			cout<<"checked if g is null"<<endl;
	// 		}
	// 		if(g->isWon()==true){
	// 			if(mtest>=100){
	// 				cout<<"checking winning condition"<<endl;
	// 			}
	// 			cout<<"Won"<<endl;
	// 			break;
	// 		}
	// 	}
	// 	cin>>s;
	// 	if(cin.eof()){
	// 		break;
	// 	}
	// 	else if(s=="include"){
	// 		string inf;
	// 		cin>>inf;
	// 		ifstream infile(inf.c_str());
	// 		setGrid(infile,g);
	// 	}
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
		// else if(s=="switch"){
		// 	int color;
		// 	cin>>color;
		// 	// switchColor(g,color);
		// }
	// }

  void setGrid(istream &in, Grid *g){
  	string s;
  	if(mtest>=50)cout<<"in setGridColor"<<endl;
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
