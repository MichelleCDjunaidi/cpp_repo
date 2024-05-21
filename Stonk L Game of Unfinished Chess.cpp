#include <bits/stdc++.h>
using namespace std;

int position[8][8];
bool isOccupied[8][8];
string notation0, notation1, notation2, notation3;

int dx[4] = { 0, 1, -1};
int dy[4] = { 1, 0, -1};

bool inRange(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void check(string pos){
  int total =0;
  int actualtile=0;
  for (int k = 0; k < 3; k++) {
    for (int m = 0; m < 3; m++) {
      int nx = pos[0]-'a' + dx[k];
      int ny = pos[1]-'1' + dy[m];
      if (inRange(nx, ny) && (position[nx][ny]!=-1)){
        total +=1;
      }
      if (inRange(nx, ny)){
        actualtile +=1;
      }
    }
  }
  
  if (total == actualtile){
    cout<<"CHECKMATE"<<endl;
  }
  else cout<<" OTHER"<<endl;
}

void checkRookSurroundings(string pos){
  int row = pos[0] - 'a';
  int col = pos[1] - '1';
  // Loop ke atas
  for(int i = row - 1; i >= 0; --i){
    position[i][col] = 1;
    if(isOccupied[i][col])break;
  }
  // Loop ke bawah
  for(int i = row + 1; i < 8; ++i){
    position[i][col] = 1;
    if(isOccupied[i][col])break;
  }
  // Loop ke kiri
  for(int i = col - 1; i >= 0; --i){
    position[row][i] = 1;
    if(isOccupied[row][i])break;
  }
  // Loop ke kanan
  for(int i = col + 1; i < 8; ++i){
    position[row][i] = 1;
    if(isOccupied[row][i])break;
  }
}

void checkKingSurroundings(string pos) {
  int row = pos[0] - 'a';
  int col = pos[1] - '1';
  position[row][col]=2;

  for (int k = 0; k < 3; k++) {
    for (int x = 0; x < 3; x++){
      int nx = row + dx[k];
      int ny = col + dy[x];
      if (inRange(nx, ny)){
        position[nx][ny]=2;
      }
    }
  }
}

void placePiece(string pos){
  int row = pos[0] - 'a';
  int col = pos[1] - '1';
  isOccupied[row][col] = true;
}

int main(){

  memset(position, -1, sizeof(position));

  cin>>notation0>>notation1>>notation2>>notation3;
  
  placePiece(notation0);
  placePiece(notation1);
  placePiece(notation2);

  checkRookSurroundings(notation0);
  checkRookSurroundings(notation1);

  checkKingSurroundings(notation2);

  check(notation3);

  /*for (int a = 0; a<8; a++){
    for (int b=0; b<8; b++){
      cout<<position[a][b] << " ";
    }
    cout << endl;
  }*/

/*3 2 2 2 1 1 1 1 
1 2 b3 2 1 1 1 1 
1 1 -1 -1 -1 -1 -1 -1 
1 1 -1 -1 -1 -1 -1 -1 
1 1 -1 -1 -1 -1 -1 -1 
1 1 -1 -1 -1 -1 -1 -1 
1 1 -1 -1 -1 -1 -1 -1 
1 1 -1 -1 -1 -1 -1 -1*/ 
}