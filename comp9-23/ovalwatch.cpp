// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    // Write C++ code here
    int n, k;
    
    cin >> n >> k;
    
    vector<pair<int, int>> arr;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    
    auto comp = [] (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    };
    
    sort(arr.begin(), arr.end(), comp);
    
    for(int j=0; j<n; j++){
        int currp = j;
        for(int i=0; i<k; i++){
            if(arr[i].first == currp){
                currp = arr[i].first+1;
            } else if(arr[i].first == currp-1){
                currp = arr[i].first;
            }
        }
        cout << currp << " ";
    }
  

    return 0;
}