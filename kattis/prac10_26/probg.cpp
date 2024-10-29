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

  int n, k;
  cin >> n >> k;
  double probs[n];
  double dp[n+1][2*n+1] = { 0 };


  for(int i=0; i<n; i++)
    cin >> probs[i];
  
  sort(probs, probs+n, greater<double>());

  dp[0][(2*n+1)/2] = 1.0;
/*
  for(int i=0; i<n; i++){
    cerr << probs[i] << " ";
  } cerr << endl;
 */
  double best = 0;
  for(int i=1; i<n+1; i++){
    double sum = 0;
    for(int j=0; j<(2*n+1); j++){
      if(j != 2*n)
        dp[i][j] += dp[i-1][j+1] * (1 - probs[i-1]); 
      if(j != 0)
        dp[i][j] += dp[i-1][j-1] * probs[i-1]; 

      if(j >= (2*n+1)/2 + k)
        sum += dp[i][j];
    }

    best = max(best, sum);
  }

  cout << best << endl;
      /*
  for(int i=1; i<n; i++){
    for(int j=0; j<n; j++){
      dp[i][j] = dp[i-1][j] * (1 - probs[j]);
    }
  }

  int sum = 0;
  for(int i=0; i<n; i++){
    cout << endl;
    for(int j=0; j<n; j++){
      cout << dp[i][j] << " ";
    }
    //sum += dp[n-1][i];
  }
*/
  //cout << sum;
}
