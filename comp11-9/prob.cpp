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

  int c, n;
  cin >> c >> n;
  c = c*2;
  int arr[n];

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  sort(arr, arr+n, greater<int>());

  int dp[c+1][n+1];
  for(int i=0; i<c; i++){
    for(int j=0; j<n; j++){
      dp[i][j] = 0;
    }
  }

  for(int i=0; i<=c; i++){
    for(int j=0; j<n; j++){
      if(arr[j] <= i){
        dp[i][j+1] = max(dp[i][j], dp[i-arr[j]][j] + arr[j]);
      } else {
        dp[i][j+1] = dp[i][j];
      }
    }
  }

  int maxFill = dp[c][n];
  int remainingFill = c;


  vector<int> bag;

  

  for (int itemIdx = n; remainingFill >= 0 && itemIdx > 0; itemIdx--) {
    if (dp[remainingFill][itemIdx] > dp[remainingFill][itemIdx-1]) {
      bag.PB(arr[itemIdx-1]);
      remainingFill -= arr[itemIdx-1];
    }
  }
  
  sort(bag.rbegin(), bag.rend());

  
  int ret[2];
  ret[0] = bag[0]; ret[1] = 0;
  
 
  if(n != 1){
  for(int i=1; i<bag.size(); i++){
    if(ret[0] < ret[1]){
      ret[0] += bag[i];
    } else {
      ret[1] += bag[i];
    }
  }
  }


  sort(ret, ret+2);

  cout << ret[1] << " " << ret[0] << endl;  
  
}
