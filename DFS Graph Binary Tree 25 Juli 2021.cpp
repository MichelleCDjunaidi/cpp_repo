/*#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int> > lst[N];
int dist[N];

int cnt = 0;
int arr[N]; // Hold si heap structure

void insert(int a){
  // ++cnt -> di tambah baru dipake
  // cnt++ -> dipake nilainya baru ditambah
  // ++0 -> dipake 1
  // 0++ -> dipake 0
  arr[++cnt] = a;
  int cur_idx = cnt;
  
  while(cur_idx > 1){
    int par = cur_idx / 2;
    if(arr[par] > arr[cur_idx]){
      swap(arr[par], arr[cur_idx]);
      continue;
    }
    break;
  }
}

int left_child(int a){
  return a * 2;
}

int right_child(int a){
  return a * 2 + 1;
}

int pop(){
  int res = arr[1];
  swap(arr[1], arr[cnt--]);
  
  int cur_idx = 1;
  while(cur_idx * 2 <= cnt){
    vector<pair<int, int> > vec;
    vec.push_back(make_pair(arr[cur_idx], cur_idx));
    
    if(left_child(cur_idx) <= cnt){
      vec.push_back(make_pair(arr[left_child(cur_idx)], left_child(cur_idx)));
    }
    
    if(right_child(cur_idx) <= cnt){
      vec.push_back(make_pair(arr[right_child(cur_idx)], right_child(cur_idx)));
    }
    
    sort(vec.begin(), vec.end());
    pair<int, int> minimum = vec[0];
    
    if(cur_idx == minimum.second)break;
    
    swap(arr[cur_idx], arr[minimum.second]);
    cur_idx = minimum.second;
  }
  
  return res;
}

void test_heap() {
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    insert(a);
  }
  
  for(int i = 0; i < n; i++){
    pop();
  }
  
  for(int i = 1; i <= n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  test_heap();
  return 0;
  // V E
  // u1 v2
  // u2 v2
  // ...
  // a b
  // u1 terhubung dengan v2 bidirectional
  
  */
  /*
  Sample TC
  7 9
  1 2 2
  1 3 5
  2 3 2
  2 4 4
  3 4 1
  3 5 3
  5 7 8
  4 6 5
  6 7 1
  1 7
  */
	/*int n, m; cin >> n >> m;
  // O(V + E);
  for(int i = 0; i < m; i++){
    int u, v, c; cin >> u >> v >> c;
    lst[u].push_back({v, c});
    lst[v].push_back({u, c});
  }
  
  int a, b; cin >> a >> b;
  
  memset(dist, -1, sizeof dist);
  
  priority_queue<pair<int, int> > q; q.push({0, a});
  dist[a] = 0;
  
  while(!q.empty()){
    int cur = q.top().second;
    int cst = q.top().first; 
    q.pop();
    
    if(dist[cur] < cst)continue;
    
    for(int i = 0; i < lst[cur].size(); i++){
      int nx = lst[cur][i].first;
      int total_cost = cst + lst[cur][i].second;
      
      if(dist[nx] == -1 || dist[nx] > total_cost){
        dist[nx] = total_cost;
        q.push({total_cost, nx});
      }
      
    }
  }
  
  cout << dist[b] << endl;
	
}*/

#include <bits/stdc++.h>
using namespace std;

const int A = 1e2 + 5;
int N, M, X, Y;
int arr[A][A];
int dist[A][A];
bool visit[A][A];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int> > q;

bool inRange(int x, int y){
  return x >= 0 && y >= 0 && x < N && y < M;
}

void grid(int x, int y){
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(inRange(nx, ny) && arr[nx][ny] != -1 && visit[nx][ny]==false){
      dist[nx][ny] = dist[x][y]+1;
      visit[nx][ny] = true;
      q.push({nx,ny});
    }
  }
}

int count(int a, int b){
  a--; b--;
  q.push({a, b});
  visit[a][b] = true;
  dist[a][b] = 1;
  
  while(!q.empty()){
    pair<int, int> cur = q.front(); q.pop();
    grid(cur.first, cur.second);
  }
  
  int minimum = 1e9;
  for(int i = 0; i < N; i++){
    if(visit[i][0]){
      minimum = min(minimum, dist[i][0]);
    }
    if(visit[i][M-1]){
      minimum = min(minimum, dist[i][M-1]);
    }
  }
  
  for(int i = 0; i < M; i++){
    if(visit[0][i]){
      minimum = min(minimum, dist[0][i]);
    }
    if(visit[N-1][i]){
      minimum = min(minimum, dist[N-1][i]);
    }
  }
  
  return minimum;
}

int main(){
  cin>> N >> M;
  for (int i=0; i<N; i++){ //i nya baris
    for (int j=0; j<M; j++){ //j nya kolom
      cin>>arr[i][j];
    }
  }
  cin>> X>> Y;
  cout << count(X, Y) << endl;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int A = 1e2 + 5;
// int N, M, X, Y;

// queue<pair<int, int> q;

// int main(){
//   cin>> N >> M;
//   for (i=0; i<N; i++){ //i nya baris
//     for (j=0; j<M; i++){ //j nya kolom
//       cin>>arr[i][j];
//     }
//   }
//   cin>> X>> Y;
// }