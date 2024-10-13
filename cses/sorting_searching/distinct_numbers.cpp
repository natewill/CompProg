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

  unordered_set<int>s;

  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    int k;
    cin >> k;
    s.insert(k);
}

cout << s.size();
