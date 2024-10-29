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
  ll l2r[n];
  ll r2l[n];
  ll nums[n];

  for(int i=0; i<n; i++){
    cin >> nums[i];
  }
  
  l2r[0] = nums[0];
  for(int i=1; i<n; i++){
    if(nums[i] >= nums[i-1]){
      l2r[i] = l2r[i-1];
    } else {
      l2r[i] = nums[i];
    }
  }
/*
  for(int i=0; i<n; i++)
    cout << l2r[i] << " ";
  cout << endl;
*/
  r2l[n-1] = nums[n-1];
  for(int i=n-2; i>=0; i--){
    if(nums[i+1] <= nums[i]){
      r2l[i] = r2l[i+1];
    } else {
      r2l[i] = nums[i];
    }
  }

  /*
  for(int i=0; i<n; i++)
    cout << r2l[i] << " ";
  cout << endl;
*/

  ll maxi = 0;
  for(int i=1; i<n-1; i++){
    if(min(nums[i] - l2r[i], nums[i] - r2l[i]) > maxi){
       maxi = min(nums[i] - l2r[i], nums[i] - r2l[i]);
    }
  }

  cout << maxi;

}
