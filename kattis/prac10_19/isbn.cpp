#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

int get10checksum(string str){
  int s = 0;
  int cnt = 0;
  for(int i=0; i<str.size(); i++){
    int strtoint = 0;
   
    if(str[i] != '-'){
      if(str[i] == 'X'){
        strtoint = 10;
      } else {
        strtoint = str[i] - '0';
      }
      s += (10-cnt) * strtoint; 
      cnt++;
     
    }
  }
  return s;
}


bool isvalid(string str){
  if(str[0] == '-' || str[str.size()-1] == '-'){
    return false;
  } 

  int hyphencnt = 0;
  int lettercnt = 0;
  for(int i=0; i<str.size(); i++){
    if(str[i] == '-'){
      if(i > 0 && str[i-1] == '-'){
        return false;
      }

      hyphencnt++;
    } else {
      lettercnt++;
    }
  }

  if(lettercnt != 10){
    return false;
  }

  if(hyphencnt > 3){
    return false;
  }

  if(hyphencnt == 3){
    if(str[str.size() - 2] != '-'){ 
      return false;
    }
  }
  
  if(get10checksum(str) % 11 != 0){
    return false;
  }
  return true;
}

string get13(string str){
  string newstr = "";
  newstr += "978-";
  newstr += str.substr(0, str.size()-1);
  return newstr;
}

void get13sum(string str){
  for(int j=0; j<11; j++){
    int s = 0;
    int cnt = 0;
    for(int i=0; i<str.size(); i++){
      int strtoint = 0;
      if(str[i] != '-'){
        strtoint = str[i] - '0';
        s += (1+((cnt%2)*2)) * strtoint;
        cnt++;
      }
    }
    s += (1+((cnt%2)*2)) * j; 
    if(s % 10 == 0){
      cout << str + to_string(j) << endl;
      return;
    }
  }
}

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string str;
    cin >> str;
    if(isvalid(str)){
      get13sum(get13(str));
    } else {
      cout << "invalid" << endl;
    }
  }
}
