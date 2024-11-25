// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write C++ code here
    int n, h;
    cin >> n >> h;
//yay!
    int cnt = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a > h)
            cnt+=2;
        else
            cnt++;
    }
    cout << cnt;
}
