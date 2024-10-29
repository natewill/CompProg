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
  int arr2[n] = { 0 };
  
  string s; cin >> s;
  for(int i=0; i<n; i++){
    arr[i] = s[i] - '0';
  }

  for(int i=0; i<n; i++){
    if(arr[i] == 1){
      if(i < n-1)
        arr2[i+1] = 1;
      if(i < n-2)
        arr2[i+2] = 1;
    }
  }
  
  int cnt = 0;

  for(int i=0; i<n; i++){
    if(arr[i] == 1 || arr2[i] == 1){
      cnt++;
    }
  }

  cout << cnt;
}
