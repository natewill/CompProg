#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    bool done = true;
    vector<bool>animahls(n);
    for(i=0; i<n; i++){
        char c;
        cin >> c;
        animals[i]  = c == 'O' ? 1 : 0;
    }
    
    int lowestOc;
    bool done = false;
    int cnt = 0;
    while(!done){
        lowestOc = -1;
        for (int=0;i<n;i++){
            if(animals[i]){
                lowerstOc = i;
            }
        }
        
        animals[lowestOc] = false;
        bool foundZebra = false;
        for(int=0;i<n;i++){
            if(i>lowestOc && animals[i]==false && !foundZebra){
                animals[i] = true
                foundZebra = true;
            }
        }
        
        if(!foundZebra){
            done = true;
        } else {
            cnt++;
        }
    }
    
    cout << cnt << endl;
}