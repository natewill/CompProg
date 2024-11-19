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

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int l2r[26][s.size()];
  int r2l[26][s.size()];

  for(int i=0; i<26; i++){
    l2r[i][0] = 0;
    r2l[i][s.size()-1] = 0;
  }

  for(int i=1; i<s.size(); i++){
    for(int j=0; j<26; j++){
      l2r[s[i]-'A'][i-1]++;
      cout << l2r[s[i]-'A'][i-1] << " ";
    }
  }
  cout << endl;

  for(int i=s.size()-2; i>=0; i--){
    r2l[s[i]-'A'][i+1]++;
    cout << r2l[s[i]-'A'][i+1] << " ";
  }
  cout << endl;

  

  int m;
  cin >> m;

  for(int i=0; i<m; i++){
    int ret[26] = { 0 };
    int a, b;
    cin >> a >> b;
    ret['T'-'A'] = r2l['T'-'A'][b] - l2r['T'-'A'][a];
    ret['C'-'A'] = r2l['C'-'A'][b] - l2r['C'-'A'][a];
    ret['G'-'A'] = r2l['G'-'A'][b] - l2r['G'-'A'][a];
    ret['A'-'A'] = r2l['A'-'A'][b] - l2r['A'-'A'][a];

    pair<char, int>newRet[4];
    newRet[0] = MP(ret['T'-'A'], 'T');
    newRet[1] = MP(ret['C'-'A'], 'C'); 
    newRet[2] = MP(ret['G'-'A'], 'G');
    newRet[3] = MP(ret['A'-'A'], 'A');

    sort(newRet, newRet+4);

    for(int i=3; i>=0; i++){
      cout << newRet[i].S;
    }
  }

  
  
  



}
