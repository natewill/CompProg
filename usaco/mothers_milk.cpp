/*
ID: nwillia2
LANG: C++
TASK: milk3
*/
#include<bits/stdc++.h>
#include <fstream>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

//int ma, mb, mc; 
//arrays are automatically pointers, vectors are not
//& means pass by pointer? i think
//also you can do this in c++

bool checked[20][20][20] = {false};

void swap_buckets(int bucket1, int bucket2, vector<int> milk, int cap[], unordered_set<int>& milk_in_c, int lvl){
  checked[milk[0]][milk[1]][milk[2]] = true;
  if(bucket1 == bucket2 || lvl > 12)
    return;

  if(milk[bucket1] + milk[bucket2] > cap[bucket2]){
    int temp = milk[bucket1] + milk[bucket2];
    milk[bucket2] = cap[bucket2];
    milk[bucket1] = temp - cap[bucket2];
  } else {
    milk[bucket2] += milk[bucket1];
    milk[bucket1] = 0;
  }

  if(milk[0] == 0){
    milk_in_c.insert(milk[2]);
  }
  if(checked[milk[0]][milk[1]][milk[2]])
    return;
    //optimization!
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(!(i == bucket1 && j == bucket2) && !(i == bucket2 && j == bucket1) && i != j && milk[j] != cap[j] && milk[i] != 0){//should of thought about this more
        swap_buckets(i, j, milk, cap, milk_in_c, lvl+1);
      }
    }
  }
}

int main(){
  //make i/o faster
  ofstream fout ("milk3.out");
  ifstream fin ("milk3.in");
  ios::sync_with_stdio(0);
  cin.tie(0);
  

  int cap[3];
  fin >> cap[0] >> cap[1] >> cap[2];
  vector<int> milk = {0, 0, cap[2]};
  
  unordered_set<int>milk_in_c;
  milk_in_c.insert(cap[2]);

  swap_buckets(2, 1, milk, cap, milk_in_c, 0);
  swap_buckets(2, 0, milk, cap, milk_in_c, 0);
  

  vector<int> myArray(milk_in_c.begin(), milk_in_c.end());
  sort(myArray.begin(), myArray.end());
  for(int i=0; i<myArray.size()-1; i++){
    fout << myArray[i] << " ";
  }
  fout << myArray[myArray.size()-1] << endl;


}
