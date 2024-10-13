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
  
  int n, T;
  cin >> n >> T;
  int dp[n+1][T+1] = {}; //initializes the array of all zeros
                         //can we make the sum j with the first i elements?
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  dp[0][0] = 1;//must set base case or this will not work
  for(int i=0; i<n; i++){
    for(int j=0; j<=T; j++){
      //at this point j is a sum that we achieved using i number of elements
      if(dp[i][j]==1){
        dp[i+1][j] = 1; //if this dp[i][j] is true, that means we can make the number j without the next element
        if(arr[i] + j <= T){//don't go out of bounds we don't want seg faults
          dp[i+1][arr[i] + j] = 1;//add this number to the curr sum
        }
      }
    }

  }
    cout << dp[n][T];
}
