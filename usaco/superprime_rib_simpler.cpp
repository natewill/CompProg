#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

vector<int> nums;

bool is_prime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

void sprime(int x, int n){
  if(n == 0)
    nums.PB(x);

  x*=10;

  if(is_prime(x+1))
    sprime(x+1, n-1);
  
  if(is_prime(x+3))
    sprime(x+3, n-1);
  
  if(is_prime(x+7))
    sprime(x+7, n-1);
  
  if(is_prime(x+9))
    sprime(x+9, n-1);
  
}

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;

  sprime(2, n-1);
  sprime(3, n-1);
  sprime(5, n-1);
  sprime(7, n-1);
  
  sort(nums.begin(), nums.end());

  for(int i=0; i<nums.size(); i++){
    cout << nums[i] << "\n";
  }
}
