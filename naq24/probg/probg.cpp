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

  int n;
  cin >> n;

  unordered_map<int, vector<int>>gears;

  for(int i=0; i<n; i++){
    int k, v;

    cin >> k >> v;

    gears[k].PB(v);
  }

  double product = 1;

  for(auto pairing : gears){
    vector<int> vec = pairing.S;
    sort(vec.begin(), vec.end());
    
    int m = vec.size();
    for(int i=0; i<m/2; i++){
      product *= (double)vec[m-1-i]/vec[i];
    }


    if(vec.size() % 2 == 1)
      product *= (double)vec[m/2]*vec[m/2-1];

    }
  cout << log(product) << endl;
}
