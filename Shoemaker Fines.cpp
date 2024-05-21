#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int cases;
int jobs;
pair<int, pair<int, int> > arr[1005];
// arr[0].first, arr[0].second
// arr[x].first, arr[x].second.first, arr[x].second.second

void compare() {
    for (int j = 0; j < jobs; j++) {
        for (int k = 1; k < jobs; k++) {
            if (arr[k].first * arr[k - 1].second.first < arr[k - 1].first * arr[k].second.first) {
                swap(arr[k], arr[k - 1]);
            }
        }
    }
}

int main() {
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        if (i > 0)cout << "\n";
        cin >> jobs;
        for (int j = 0; j < jobs; j++) {
            cin >> arr[j].first >> arr[j].second.first;
            arr[j].second.second = j + 1;
        }
        compare();
        for (int k = 0; k < jobs - 1; k++) {
            cout << arr[k].second.second << " ";
        }
        cout << arr[jobs - 1].second.second;
        cout << "\n";
    }
}#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int cases;
int jobs;
pair<int, pair<int, int> > arr[1005];
// arr[0].first, arr[0].second
// arr[x].first, arr[x].second.first, arr[x].second.second

void compare() {
    for (int j = 0; j < jobs; j++) {
        for (int k = 1; k < jobs; k++) {
            if (arr[k].first * arr[k - 1].second.first < arr[k - 1].first * arr[k].second.first) {
                swap(arr[k], arr[k - 1]);
            }
        }
    }
}

int main() {
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        if (i > 0)cout << "\n";
        cin >> jobs;
        for (int j = 0; j < jobs; j++) {
            cin >> arr[j].first >> arr[j].second.first;
            arr[j].second.second = j + 1;
        }
        compare();
        for (int k = 0; k < jobs - 1; k++) {
            cout << arr[k].second.second << " ";
        }
        cout << arr[jobs - 1].second.second;
        cout << "\n";
    }
}

/*bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
  int lft = b.first * a.second.first;
  int rgt = a.first * b.second.first;;
  return lft > rgt;
}

int main(){
  cin>>cases;
  for (int i=0; i< cases; i++){
    if(i > 0)cout << "\n";
    cin>>jobs;
    for (int j=0; j<jobs; j++){
      cin>>arr[j].first>>arr[j].second.first;
      arr[j].second.second=j+1;
    }
    sort(arr, arr + jobs, cmp);
    for(int k=0; k<jobs-1; k++){
      cout<<arr[k].second.second<<" ";
    }
    cout<<arr[jobs-1].second.second;
    cout << "\n";
  }
}*/