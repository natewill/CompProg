#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

//frog problem from colin galen's tutorial on dynamic programming
//let's say you're a frog and you can only jump 1 or 2 units to the right
//count the number of different paths from 0 to n
//
int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int dp[n+1];

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for(int i=3; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2]; //at point n, you can only add a 1 jump to all of the paths from n-1, or you can add a 2 jump to all of the paths from n-2.
  }

  cout << dp[n];
}
