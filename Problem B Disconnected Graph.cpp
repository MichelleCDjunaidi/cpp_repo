#include <bits/stdc++.h>
using namespace std;


const int Z = 50010;
const int EDGE = 200010;

int special[Z];
int visited[Z];
int a[EDGE];
int b[EDGE];

long long N, Q, R, T, E;

queue<int> que;
vector<int> vec[50010];

int countSpecialInCluster(int start) {
    int res = 0;
    que.push(start);
    visited[start] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        if (special[cur] == 1){
            res += 1;
        }

        for (int i=0; i< vec[cur].size(); i++){
            int nex = vec[cur][i];
            // cur = node yang kita tinjau sekarang
            // nex= node ke i yang terhubung dengan cur (?)
            // simpen status special/ga special node tersebut di special[A]
            if (!visited[nex]){
                visited[nex]=1;
                que.push(nex);
            }
        }

    }
    
    return res;
}

int main (){
    cin>>T;
    for (int i=0; i<T; i++){
        memset(visited, 0, sizeof visited);
        memset(special, 0, sizeof special);
        for(int i = 0; i <= N; i++){
            vec[i].clear();
        }

        cin>>N>>E>>Q>>R;
        long long complement=0;
        long long ans = 0;

        for (int j=0; j<E; j++){
            cin>> a[j]>> b[j];
        }

        for (int k=0; k<Q; k++){
            int khusus;
            cin>> khusus;
            special[khusus]=1;
        }

        for (int l=0; l<R; l++){
            int urutan;
            cin>>urutan;
            a[urutan-1]=-1;
            b[urutan-1]=-1;
        }

        for (int x=0; x<E; x++){
            if (a[x]!=-1){
                vec[a[x]].push_back(b[x]);
                vec[b[x]].push_back(a[x]);
            }
        }

        for (int m=0; m<N; m++){
            if(visited[m])continue;
            long long h = countSpecialInCluster(m);
            complement += h*(h-1)/2;
        }
        
        ans = Q*(Q-1)/2 - complement;
        cout << ans << endl;
    }
}

/*
2
4 4 4 3
1 2
1 4
2 4
3 4
1 2 3 4
1 2 3
2 1 1 1
1 2
2
1
*/