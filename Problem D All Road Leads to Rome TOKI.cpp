#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 510;

int arr[N][N];
int dis[N][2];
bool vis[N][N];
int a, b, n, l, t;

queue<pair<int, int> > que;
vector<pair<int, int> > vec[510];

void count(int start, int end) {
    que.push({start, end});
    vis[start][end] = true;

    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
    }

    if(cur.second=0){
        for (int i=0; i< vec[cur.first].size(); i++){
            pair<int, int> nex = vec[cur.first][i];
            if(dis[nex.first][nex.second] = -1){
                dis[nex.first][nex.second] = dis[cur.first][cur.second]+1;
                que.push(nex);
            }
        }
    }

    else if(cur.second=1) {
        for(int i=0; i< vec[cur.first].size(); i++){
            if(vec[cur.first][i].second==0){
                pair<int, int> nex;
                nex.first= vec[cur.first][i].first;
                nex.second = 1;
                if(dis[nex.first][nex.second] = -1){
                dis[nex.first][nex.second] = dis[cur.first][cur.second]+1;
                que.push(nex);
                }
            }
        }
    }

    int main(){
        memset(dis, -1, sizeof(dis));
        cin>> n >> l >> t>> start1>> akhir;
        for(int i=0; i<l; i++){
            cin>> a>> b;
            v[a].push_back(make_pair(b,0));
            v[b].push_back(make_pair(a,0));
        }
        for(int j=0; j<t; j++){
            cin>> a>> b;
            v[a].push_back(make_pair(b,1));
            v[b].push_back(make_pair(a,1));
        }

        count(start1, akhir);
        if(dis[akhir][0] ==-1){
            cout<<dis[akhir][1]<<endl;
            return;
        }
            if(dis[akhir][1] ==-1){
            cout<<dis[akhir][0]<<endl;
            return;
        }
    }
}
