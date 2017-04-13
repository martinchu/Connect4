if(i>= 1 && i <= rowSize-3 && td->getCord(i-1,j)==td->getCord(i+1,j)&&td->getCord(i+1,j)==td->getCord(i+2,j)){
  if(td->getCord(i-1,j)=='1'){
    if(potentialLcheckV>=10)cout<<"V2: Found a potential WL!!!"<<i<<j<<endl<<*td<<endl;
    num = -100;
    return num;
  }
  else if(td->getCord(i-1,j)=='2') {
    if(potentialLcheckV>=10)cout<<"V2: Found a potential WL!!!"<<i<<j<<endl<<*td<<endl;
    num = 100;
    return num;
  } //inARow[1]+=i;
}
if(i>= 2 && i <= rowSize-2 && td->getCord(i-2,j)==td->getCord(i-1,j)&&td->getCord(i-1,j)==td->getCord(i+1,j)){
  if(td->getCord(i-2,j)=='1'){
    if(potentialLcheckV>=10)cout<<"V3: Found a potential WL!!!"<<i<<j<<endl<<*td<<endl;
    num = -100;
    return num;
  }
  else if(td->getCord(i-2,j)=='2'){
    if(potentialLcheckV>=10)cout<<"V3: Found a potential WL!!!"<<i<<j<<endl<<*td<<endl;
    num = 100;
    return num;
  } //inARow[1]+=i;
}
if(i>= 3 && i <= rowSize-1 && td->getCord(i-3,j)==td->getCord(i-2,j)&&td->getCord(i-2,j)==td->getCord(i-1,j)){
  if(td->getCord(i-3,j)=='1'){
    if(potentialLcheckV>=10)cout<<"V4: Found a potential WL!!!"<<i<<j<<endl<<*td<<endl;
    num = -100;
    return num;
  }
  else if(td->getCord(i-3,j)=='2') {
    if(potentialLcheckV>=10)cout<<"V4: Found a potential WL!!!"<<i<<j<<endl<<*td<<endl;
    num = 100;
    return num;
  } //inARow[1]+=i;
}
