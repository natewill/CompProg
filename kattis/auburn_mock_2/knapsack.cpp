#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#include <queue>
#include <set>
#include <functional>
#include <tuple>
#include <deque>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c;
  while(cin >> c){

    int n; cin >> n;
    vector<pair<int, int>> arr;

    for(int i=0; i<n; i++){
      int k, g; cin >> k >> g;
      arr.PB(make_pair(k, g));
    }

    sort(arr.rbegin(), arr.rend());

    int sum = 0;
    int i = 0;
    vector<int> inds;
    while(i < arr.size()){
      if(arr[i].second + sum <= c){
        sum += arr[i].second;
        inds.PB(arr[i].first);  
      }
      i++;
    }

    cout << inds.size() << endl;
    for(int i=0; i<inds.size()-1; i++){
      cout << inds[i]+1 << " ";
    }
    if(inds.size() != 0)
      cout << inds[inds.size()-1] << endl;;
  }
}
