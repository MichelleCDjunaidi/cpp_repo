#include <iostream>
using namespace std;
 
int T, N;
string enemy, ally;
int pawn;
 
void calc(){
    pawn = 0;
    for(int i=0; i<N; i++){
        if(ally[i] == '0')continue;
 
        for(int j = -1; j <= 1; j++){
            int nx = i + j;
            if(nx >= 0 && nx < N){
                if(nx != i && enemy[nx] == '1'){
                    enemy[nx] = '9';
                    pawn++;
                    break;
                }
                if(nx == i && enemy[nx] == '0'){
                    enemy[nx] = '9';
                    pawn++;
                    break;
                }
            }
        }
 
    }
    cout<< pawn <<endl;
}
 
/*
011
011
 
0 -> n - 1
i -> makan ke kiri, lurus, makan ke kanan 
*/
 
int main() {
  cin>>T;
  for(int i=0; i<T; i++){
    cin>> N;
    cin>> enemy;
    cin>> ally;
    calc();
  }
}
