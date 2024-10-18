/*
ID: nwillia2
LANG: C++
TASK: sprime
*/

#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

bool isPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ofstream fout ("sprime.out");
  ifstream fin ("sprime.in");

  int n; fin >> n;
  vector<string>nums; 
  
  nums.PB("2");
  nums.PB("3");
  nums.PB("5");
  nums.PB("7");

  for(int i=0; i<n-1; i++){//this works, just gotta understand the first prime numbers were caluclated above
    int curr_size = nums.size();//nums.size() updates after every l++, so you need a copy
                                //i didn'e even know that after every look, l<n is checked
                                //that makes a lot of sense
    for(int l=0; l<curr_size; l++){
     if(nums[l] != "nothing"){//don't need to use strcmp
                              //don't forget to make sure you're logic is correct
      string num_temp = nums[l];
      for(int j=0; j<10; j++){
        string temp = num_temp + to_string(j);//to_string is how to convert integers to strings
                                              //.append() returns a reference to the string it appends to?
        int temp_to_int = stoi(temp);//string to integer is stoi
        if(isPrime(temp_to_int)){//isPrime from the interwebs
          nums.PB(temp);
        }
      }
      nums[l] = "nothing";//there's def a better way to do this
      }
    }
  }

  sort(nums.begin(), nums.end());

  for(string num : nums){
    if(num != "nothing")
      fout << num << "\n";
  }
}
