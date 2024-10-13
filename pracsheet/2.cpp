// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int acnt = 0;
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        if(c == 'A')
            acnt++;
    }
    if(acnt < (float)n/2)
        cout << "Danik";
    else if(acnt > (float)n/2)
        cout << "Anton";
    else
        cout << "Friendship";
}