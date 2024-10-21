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
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int mins[n];
  int maxs[n];

  maxs[0] = arr[0];
  for(int i=1; i<n; i++){
    if(arr[i] > maxs[i-1]){
      maxs[i] = arr[i];
    } else {
      maxs[i] = maxs[i-1];
    }
  }

  mins[n-1] = arr[n-1];
  for(int i=n-2; i>=0; i--){
    if(arr[i] < mins[i+1]){
      mins[i] = arr[i];
    } else {
      mins[i] = mins[i+1];
    }
  }
  
  /*
  for(int i=0; i<n; i++){
    cout << mins[i] << " " << maxs[i] << endl;
  }
 */
  vector<int> ans;
  for(int i=0; i<n; i++){
    if(maxs[i] == mins[i]){
      ans.PB(arr[i]);
    }
  }
    
    if(ans.size() == 0){
      cout << 0;
    } else {
      cout << ans.size() << " ";
      for(int i=0; i<ans.size()-1&&i<99; i++){
        cout << ans[i] << " ";
      }
      if(ans.size() > 0 && ans.size() < 100){
        cout << ans[ans.size()-1];
      } else if(ans.size() >= 100){
        cout << ans[99];
      }
    }


}
