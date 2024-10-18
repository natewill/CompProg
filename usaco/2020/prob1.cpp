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

  int arr[7];
  for(int i=0; i<7; i++){
    cin >> arr[i];
  }

  sort(arr, arr+7);

  int a, b, c;
  a = arr[0];
  b = arr[1];
  c = arr[5]-b;

  cout << a << " " << b << " " << c << endl;
}
