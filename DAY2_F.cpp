#include<bits/stdc++.h>
using namespace std;

int arr[15][15];
int jarak[15][15];

int dist(int x, int y){
  if(x==1 && y==1){
    return arr[1][1];
  }
  if(x==1){
    return jarak[x][y]= dist(x, y-1) + arr[x][y]; 
  }
  if(y==1){
    return jarak[x][y]= dist(x-1,y) + arr[x][y];
  }
  
  if (jarak[x][y]!=-1){
    return jarak[x][y];
  }
  jarak[x][y]= min(dist(x-1,y)+arr[x][y], dist(x,y-1)+ arr[x][y]);
  
  return jarak[x][y];
}

int main (){
  int x,y;
  cin>>x>>y;
  for(int i=1;i<=x;i++){
    for(int j=1;j<=y;j++){
      cin>>arr[i][j];
    }
  }
  memset(jarak,-1,sizeof(jarak));
  int min= dist(x,y);
  cout<<min;
}

