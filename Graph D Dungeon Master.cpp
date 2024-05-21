#include <bits/stdc++.h>
using namespace std;

char dungeon[35][35][35];
int startL, startR, startC;
int L, R, C;
int dist[35][35][35];
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

struct node {
    int x, y, z;
};

bool inRange(int x, int y, int z){
    return x >= 0 && y >= 0 && z >= 0 && x < L && y < R && z < C;
}

int findShortestPath(int x, int y, int z){
    queue<node> q;
    q.push({x, y, z});

    dist[x][y][z]=0;
    
    while(!q.empty()){
        node cur = q.front(); q.pop();

        int curx = cur.x;
        int cury = cur.y;
        int curz = cur.z;

        if (dungeon[curx][cury][curz]=='E'){
            return dist[curx][cury][curz];
        }

        for (int i=0; i<6; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            int nz = curz + dz[i];
            if (inRange(nx, ny, nz) && dungeon[nx][ny][nz]!= '#' && dist[nx][ny][nz] == -1){
                dist[nx][ny][nz]=dist[curx][cury][curz]+1;
                q.push({nx, ny, nz});
            }
        }

    }

    return -1;
}

int main(){
    while(cin >> L>> R>> C){
        if (L == 0 && R == 0 && C==0){break;}
        
        memset(dist, -1, sizeof dist);

        for (int i=0; i<L; i++){
            for (int j=0; j<R; j++){
                for (int k=0; k<C; k++){
                    cin>>dungeon[i][j][k];
                    if (dungeon[i][j][k]=='S'){
                        startL=i;
                        startR=j;
                        startC=k;
                    }
                }
            }
        }

        int ans = findShortestPath(startL, startR, startC);
        if (ans==-1){
            cout<< "Trapped!" << endl;
        }else{
            cout<< "Escaped in "<< ans << " minute(s)." << endl;
        }
    }
}