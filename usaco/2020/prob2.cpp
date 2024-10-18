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
  
  
  int cnt = 0;
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      bool has_avg = false;
      int sum = 0;
       for(int m=i; m<=j; m++){
        sum += arr[m];
      }
      double avg = sum / ((double)(abs(i-j)+1));
      for(int m=i; m<=j; m++){
        if(avg == arr[m]){
          has_avg = true;
        }
      }
      if(has_avg)
        cnt++;
    }
  }

  cout << cnt << endl;
}
