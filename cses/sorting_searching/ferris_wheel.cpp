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

  int n, x;
  cin >> n >> x;
  int arr[n];

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  sort(arr, arr+n);

  int big = n-1;
  int sml = 0;
  int cnt = 0;

  while(big >= sml){
    if(arr[sml] + arr[big] <= x){
      cnt++;
      sml++;
      big--;
    } else if(sml == big){
      cnt++;
      break;
    } else {
      cnt++;
      big--;
    }
  }

  cout << cnt;
}
