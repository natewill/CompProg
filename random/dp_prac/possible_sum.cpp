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

  int n, t;
  cin >> n >> t; //must declare variable before making variable length array.
  int arr[n];

  vector<vector<int>>dp(n, vector<int>(1, 0));


  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  
  dp[0].PB(arr[0]);

  bool done = false;
  for(int i=1; i<n&&!done; i++){

    dp[i] = dp[i-1];// need to make new dp the old dp before adding more values
    for(int j=0; j<dp[i-1].size()&&!done; j++){

      int k = dp[i-1][j] + arr[i];
      if(k == t){
        cout << "True";
        done = true; //if done, need to stop loop, this seems like the only way to do it.
                     //break only works with one for loop
      }

      dp[i].PB(k);

    }
    dp[i].PB(arr[i]);
  }

  if(!done)
    cout << "False";//need to check if done
}
