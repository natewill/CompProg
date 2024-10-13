// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    // Write C++ code here
    int n, k;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        
        map<string, int> cnts;
        
        for(int j=0; j<k; j++){
            string a, key;
            cin >> a >> key;
            if (cnts.count(key)){
                cnts[key]++;
            } else {
                cnts[key] = 1;
            }
        }
        
        int sum = 1;
        map<string, int>::iterator it;
        for (it = cnts.begin(); it != cnts.end(); it++)
        {
            sum *= (it->second+1);
        }
        cout << sum-1 << "\n";
    }
}