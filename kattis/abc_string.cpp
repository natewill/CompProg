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
  
  string s;
  getline(cin, s);

  int arr[3] = { 0 };

  for(int i=0; i<s.size(); i++){
    arr[s[i]-'A']++;
  }

  sort(arr, arr+3);

  cout << arr[0];
}
