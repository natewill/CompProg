// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>

using namespace std;
int binarySearch(vector<int> arr, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;
        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }
    // If we reach here, then element was not present
    return low;
}
int main() {
    // Write C++ code here
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        vector<int> search;
        int j, l;
        cin >> j >> l;
        for(int j=0; j<l; j++){
            int a;
            cin >> a;
            sort(search.begin(), search.end());
            if(search.size() == 0){
                search.push_back(a);
                cout << a-1 << "\n";
            } else {
                int added = binary_search(search, 0, n - 1, a);
                cout << "added: " << added << "\n";
            }
        }
    }
    
}