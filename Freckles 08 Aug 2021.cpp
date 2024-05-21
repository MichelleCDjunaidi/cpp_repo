#include<bits/stdc++.h>

using namespace std;

const int N = 105;

struct edge {
    double u, v, cost;
};

double x[N], y[N];

double dist(int a, int b){
    double xx = x[a] - x[b];
    double yy = y[a] - y[b];
    return sqrt(xx * xx + yy * yy); 
}

// DSU -> Disjoint Set Union
int dsu[N];

int find(int x){
    if(dsu[x] == x)return x;
    int res = find(dsu[x]);
    dsu[x] = res;
    return res;
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)return false;
    dsu[a] = b;
    return true;
}

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);

    int t; cin >> t;
    while(t--){
        vector<edge> edgeList;
        
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            dsu[i] = i;
            cin >> x[i] >> y[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                edgeList.push_back({i, j, dist(i, j)});
            }
        }

        sort(edgeList.begin(), edgeList.end(), cmp);
        
        double ans = 0;
        for(int i = 0; i < edgeList.size(); i++){
            if(merge(edgeList[i].u, edgeList[i].v)){
                ans += edgeList[i].cost;
            }
        }

        cout << ans << endl;
        if(t)cout << endl;
    }
}