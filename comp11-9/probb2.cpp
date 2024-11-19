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

bool m1[1001][1001];
bool m2[1001][1001];
void swap(bool m1, bool m2){
  bool temp = m1;
  m1 = m2;
  m2 = temp;
}

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c, n;
  cin >> c >> n;

  int items[1000];

  for(int i=0; i<n; i++){
    cin >> items[i];
  }

  auto oldm = m1;
  auto newm = m2;

  oldm[0][0] = true;

  for(int k=0; k<n; k++){
    for(int i=0; i<=c; i++){
      for(int j=0; j<=c; j++){
        if(oldm[i][j]){
          newm[i][j] = true;
          if(i+items[k] <= c)
            newm[i+items[k]][j] = true;
          if(j+items[k] <= c)
            newm[i][j+items[k]] = true;
        }
      }
    }
    swap(oldm, newm);
  }

  int besti = 0;
  int bestj = 0;
  for(int i=0; i<=c; i++){
    for(int j=0; j<=c; j++){
      if(oldm[i][j] && i + j >= besti + bestj) {
        if (i + j == besti + bestj) {
          if (abs(i - j) < abs(besti - bestj)) {
            besti = i;
            bestj = j;
          }  
        }
        else {
          besti = i;
          bestj = j;
        }
      }  
    }
  }
  if(besti > bestj){
    cout << besti << " " << bestj;
  } else {
    cout << bestj << " " << besti;
  }
}
