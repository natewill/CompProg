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
  pair<int, int> arr[n];//made a pair to keep track of the original index of each number before it's sorted

  for(int i=0; i<n; i++){
    cin >> arr[i].F;
    arr[i].S = i;
  }

  sort(arr, arr+n);

  int sml = 0;
  int big = n-1;

  bool done = false;
  while(sml < big){
    if(arr[sml].F + arr[big].F == x){
      done = true;
      break;
    } else if(arr[sml].F + arr[big].F > x){
      big--;
    } else {
      sml++;
    }
  }

  if(done)
    cout << arr[sml].S + 1 << " " << arr[big].S + 1;//need to read problem carefully, it asks for the index of the number in the orginal array
   else 
    cout << "IMPOSSIBLE";
}
