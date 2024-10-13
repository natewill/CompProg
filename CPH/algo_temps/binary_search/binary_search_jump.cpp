using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k=0;

  for(int b = n/2; b >= 1; b /= 2){
    while(k+b < n && array[k+b] <= x) k+=b;
  }

  if(array[k] == x){
    //x found at index k
  }
}
