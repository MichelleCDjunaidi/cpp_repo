#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, cost;
};

int dsu[200005];

int find(int x){
    if (dsu[x]==x) return x;
    return dsu[x]=find(dsu[x]);
}

bool light(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    dsu[a]=b;
    return true;
}

bool cmp(edge a, edge b){
    return a.cost<b.cost;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int junction, road;
    while(cin>>junction>>road){

        vector<edge> edgeList;

        int wasted = 0;

        if (junction == 0 && road == 0) break;
        for (int i=0; i<road; i++){
            int x, y, z;
            cin>>x>>y>>z;
            edgeList.push_back({x, y, z});
            dsu[i]=i;
            wasted += z;
        }

        sort(edgeList.begin(), edgeList.end(), cmp);

        int saved = 0;
        for(int j = 0; j < edgeList.size(); j++){
            if(light(edgeList[j].u, edgeList[j].v)){
                saved += edgeList[j].cost;
            }
        }

        cout<<wasted-saved<<endl;

    }
}
