#include<bits/stdc++.h>

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

  int n; cin >> n;
  vector<int> towers;

  int k1; cin >> k1;
  towers.PB(k1);

  for(int i=1; i<n; i++){
    int k; cin >> k;
    auto it = upper_bound(towers.begin(), towers.end(), k);

    if(it != towers.end()) {
      towers[it-towers.begin()] = k;    
    } else { 
      towers.PB(k);  
    }
  }
  cout << towers.size();
}
