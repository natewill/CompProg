#include <bits/stdc++.h>

using namespace std;

int main(){
   int nt;
   cin >> nt;

   for(int i=0; i<nt; i++){
    int n, m, provedcnt;
    cin >> n >> m;
    for(int j=0; j<m; j++){
        int s1, s2;
        cin >> s1 >> s2;

        if(s2-s1==1||(s1==n&&s2==1))
            provedcnt++;
    }
    cout << (n+1) - provedcnt << endl;
   }

}