#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
//O(n^2logn) solution
typedef long long ll;

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  vector<int> towers;

  int k1; cin >> k1;
  towers.PB(k1);
  for(int i=0; i<n-1; i++){
    int k; cin >> k;
    sort(towers.begin(), towers.end());

    auto tower = upper_bound(towers.begin(), towers.end(), k);

    if(tower < towers.end()){
      towers[tower-towers.begin()] = k;
    } else {
      towers.PB(k);
    }
  }
  cout << towers.size();
}
