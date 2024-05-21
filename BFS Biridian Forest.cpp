/*#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e9 + 5;

class PriorityQueue {
  vector<pair<int, int> > vec;

public:
  void push(pair<int, int> a){
    vec.push_back(a);

    int idx = vec.size() - 1;
    while(idx > 0){
      int par = idx / 2;
      if(vec[idx] < vec[par]){
        swap(vec[idx], vec[par]);
        idx = par;
        continue;
      }
      break;
    }
  }

  pair<int, int> top() {
    return vec[0];
  }

  void pop() {
    int idx = vec.size() - 1;
    swap(vec[0], vec[idx]);
    vec.pop_back();

    for(int i = 0; i < vec.size();){
      // pair<data, idx>
      vector<pair<pair<int, int>, int> > tmp;

      tmp.push_back(make_pair(vec[i], i));
      if(i * 2 < vec.size())tmp.push_back(make_pair(vec[i * 2], i * 2));
      if(i * 2 + 1 < vec.size())tmp.push_back(make_pair(vec[i * 2 + 1], i * 2 + 1));

      sort(tmp.begin(), tmp.end());

      int idx_mini = tmp[0].second;
      if(idx_mini == i)break;

      swap(vec[i], vec[idx_mini]);
      i = idx_mini;
    }
  }

  bool empty() {
    return vec.size() == 0;
  }
};

vector<pair<int, int> > lst[N + 5];
int dist[N + 5];
int main() {
  */
  /*
  N M -> N kota, M jalan
  Ui Vi Ci -> Kotak u terhubung kota v dengan cost c
  A B -> Cari shortest dari A ke B
*/
/*
int n, m; cin >> n >> m;
for(int i = 1; i <= n; i++)dist[i] = INF;
for(int i = 0; i < m; i++){
  int u, v, c; cin >> u >> v >> c;
  lst[u].push_back({v, c});
  lst[v].push_back({u, c});
}

int a, b; cin >> a >> b;
// Keep track minimum pair pake greater<pair<int, int> >
PriorityQueue pq;
pq.push(make_pair(0, a));

dist[a] = 0;
while(!pq.empty()){
  pair<int, int> cur = pq.top(); pq.pop();
  int idx = cur.second;
  int cur_dist = cur.first;

  if(dist[idx] != cur_dist)continue;

  for(int i = 0; i < lst[idx].size(); i++){
    int nx = lst[idx][i].first;
    int nx_cost = cur_dist + lst[idx][i].second;

    if(dist[nx] > nx_cost){
      dist[nx] = nx_cost;
      pq.push(make_pair(nx_cost, nx));
    }
  }
}

cout << dist[b] << endl;
}
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int INF = 1e9 + 5;
int R, C;
string row[N];

int pos_i, pos_j;
int exit_i, exit_j;

int arr[N][N];
int dist[N][N];
bool vis[N][N];
int trainer[N][N];
int battle = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int> > que;

bool inRange(int x, int y) {
    return x >= 0 && y >= 0 && x < R&& y < C;
}

void grid(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inRange(nx, ny) && arr[nx][ny] != -1 && vis[nx][ny] == false) {
            dist[nx][ny] = dist[x][y] + 1;
            vis[nx][ny] = true;
            que.push({ nx,ny });
        }
    }
}

void count(int a, int b) {
    que.push({ a,b });
    vis[a][b] = true;

    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        grid(cur.first, cur.second);
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> row[i];
        for (int j = 0; j < row[i].length(); j++) {
            if (row[i][j] == 'T') {
                vis[i][j] = true;
            }
            if ('0' <= row[i][j] && row[i][j] <= '9') {
                // 0-9
                trainer[i][j] = int(row[i][j] - '0');
            }
            if (row[i][j] == 'S') {
                pos_j = j;
                pos_i = i;
            }
            if (row[i][j] == 'E') {
                exit_j = j;
                exit_i = i;
            }
        }
    }
    count(exit_i, exit_j);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dist[i][j] <= dist[pos_i][pos_j] && vis[i][j] == true) {
                battle += trainer[i][j];
            }
        }
    }
    cout << battle;
}
/*
5 5
E0T05
000T0
000T0
000T0
S00T0
*/