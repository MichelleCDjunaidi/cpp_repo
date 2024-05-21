#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int row, column;
int a, b;
int garden[55][55];
int smallest;

bool inRange(int k, int l){
    return k<row && l<column && k>=0 && l>=0;
}

int checkHoriHouse(int placeR, int placeC){
    int valid=0;
    int treeChopped=0;
    for (int m=placeR; m<placeR+a; m++){
        for(int n=placeC; n<placeC+b; n++){
            if (inRange(m, n)){
                treeChopped += garden[m][n];
                valid +=1;
            }
        }
    }
    if (valid == a*b){
        return treeChopped;
    }
    else {return INF;}
}

int checkVertiHouse(int placeR, int placeC){
    int valid=0;
    int treeChopped=0;
    for (int m=placeR; m<placeR+b; m++){
        for(int n=placeC; n<placeC+a; n++){
            if (inRange(m, n)){
                treeChopped += garden[m][n];
                valid +=1;
            }
        }
    }
    if (valid == a*b){
        return treeChopped;
    }
    else {return INF;}
}

int main(){
    cin>>row>>column;
    for (int x=0; x<row; x++){
        for(int y=0; y<column; y++){
            cin>>garden[x][y];
        }
    }
    cin>>a>>b;

    smallest = INF;

    for(int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            smallest = min(smallest, checkHoriHouse(i, j));
            smallest = min(smallest, checkVertiHouse(i, j));
        }
    }

    cout<< smallest;

}