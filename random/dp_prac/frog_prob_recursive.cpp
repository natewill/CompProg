#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

int frog(int n){
  if(n == 0){
    return 0;
  } else if(n == 1){
    return 1;
  } else if(n == 2){
    return 2;
  } else {
    return frog(n-1) + frog(n-2);
  }
}
int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << frog(n);
}
