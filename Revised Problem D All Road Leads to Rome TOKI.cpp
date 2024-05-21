#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 510;
const int INF = 1e9;

int arr[N][N];
int dis[N][2];
int a, b, n, l, t, start1, akhir;

queue<pair<int, int> > que;
vector<pair<int, int> > vec[510];

void count(int start, int end) {
    que.push({start, 0});
    dis[start][0] = 0;

    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();

        for (int i=0; i< vec[cur.first].size(); i++){
            pair<int, int> nex = vec[cur.first][i]; 
            //cur.first = kota sekarang, i nya ninjau jalan ke i yang disimpen/di push back ke dalam vec
            int nxTotalHighway = cur.second + nex.second;
            //cur.second = apakah udah pernah pake jalan tol, nex.second = status jalan tol or not jalan next

            if(nxTotalHighway > 1)continue;

            if(dis[nex.first][nxTotalHighway] == INF){ //nxTotalHighway preserves pernah pake jalan tol ga
                dis[nex.first][nxTotalHighway] = dis[cur.first][cur.second]+1;
                que.push({nex.first, nxTotalHighway});
               }
        }

    }

}

int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            dis[i][j] = INF;
        }
    }

    cin>> n >> l >> t>> start1>> akhir;
    for(int i=0; i<l; i++){
        cin>> a>> b;
        vec[a].push_back(make_pair(b,0));
        vec[b].push_back(make_pair(a,0));
    }
    for(int j=0; j<t; j++){
        cin>> a>> b;
        vec[a].push_back(make_pair(b,1));
        vec[b].push_back(make_pair(a,1));
    }

    count(start1, akhir);
    
    int ans = min(dis[akhir][0], dis[akhir][1]);
    cout << ans << endl;
}
