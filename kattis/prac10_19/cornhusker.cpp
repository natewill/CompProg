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

  //((sum(A * L) / 5) * N) / KWF
  
  int A[5];
  int L[5];
  
  int N;
  int KWF;

  for(int i=0; i<10; i++){
    if(i % 2 == 0){
      cin >> A[i/2];
    } else {
      cin >> L[i/2];
    }
  }
  cin >> N;
  cin >> KWF;

  int sum = 0;
  for(int i=0; i<5; i++){
    sum += A[i] * L[i];
  }
  
  cout <<  ((sum / 5) * N) / KWF;
}
