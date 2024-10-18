#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;

struct Point {
  char dir;
  int x, y;
};

//change to N
vector<int>intersections(50);
int ret[50] = {0};

void make_intersect(Point point1, Point point2, int i1, int i2){
  int diff_on_y_axis = abs(point1.y - point2.y);
  int diff_on_x_axis = abs(point1.x - point2.x);
  if(diff_on_y_axis > diff_on_x_axis){
    if(point1.dir == 'N' || point1.dir == 'S')
      intersections[i1] = min(intersections[i1], diff_on_y_axis);
    else
      intersections[i2] = min(intersections[i2], diff_on_y_axis);
  } else if(diff_on_x_axis > diff_on_y_axis){
    if(point1.dir == 'W' || point1.dir == 'E')
      intersections[i1] = min(intersections[i1], diff_on_x_axis);
    else
      intersections[i2] = min(intersections[i2], diff_on_x_axis);;
  }
}

void new_case(Point point1, Point point2, int i1, int i2){
  int diff_on_y_axis = abs(point1.y - point2.y);
  int diff_on_x_axis = abs(point1.x - point2.x);

  if(diff_on_x_axis != 0){
    ret[i1] = ((point1.x + point2.x)/2);
    ret[i2] = ((point1.x + point2.x)/2);
  } else {
    ret[i1] = ((point1.y + point2.y)/2);
    ret[i2] = ((point1.y + point2.y)/2);
  }
}
void check_new(Point point1, Point point2, int i1, int i2){
  if(
  (point1.dir == 'S' && point2.dir == 'E' && point2.x < point1.x && point1.y > point2.y) || 
  (point2.dir == 'S' && point1.dir == 'E' && point1.x < point2.x && point2.y > point1.y) || 
  (point1.dir == 'S' && point2.dir == 'W' && point1.x < point2.x && point1.y > point2.y) || 
  (point2.dir == 'S' && point1.dir == 'W' && point2.x < point1.x && point2.y > point1.y) ||
  (point2.dir == 'N' && point1.dir == 'E' && point1.x < point2.x && point2.y < point1.y) ||
  (point2.dir == 'E' && point1.dir == 'N' && point2.x < point1.x && point1.y < point2.y) ||
  (point2.dir == 'N' && point1.dir == 'W' && point2.x > point1.x && point1.y > point2.y) ||
  (point2.dir == 'W' && point1.dir == 'N' && point2.x < point1.x && point1.y < point2.y)
  )
  {
    make_intersect(point1, point2, i1, i2);
  } else if((point1.dir == 'E' && point2.dir == 'W' && point1.y == point2.y)||
    (point1.dir == 'W' && point2.dir == 'E' && point1.y == point2.y)||
    (point1.dir == 'S' && point2.dir == 'N' && point1.x == point2.x)||
    (point1.dir == 'N' && point2.dir == 'S' && point1.x == point2.x)
  ) {
    new_case(point1, point2, i1, i2);
  }
}

void simulate(vector<Point> points){
  for(int i=0; i<points.size(); i++){
    for(int j=0; j<points.size(); j++){
      if(points[i].dir != 'C' && points[j].dir != 'C')
        check_new(points[i], points[j], i, j);
    }
  }
}

int main(){
  //make i/o faster
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<Point>points;

  for(int i=0; i<50; i++){
    intersections[i] = 10e9;
  }

  for(int i=0; i<n; i++){
    char dir;
    int x, y;
      
    cin >> dir >> x >> y;
    Point new_point = {dir, x, y};
    points.PB(new_point);
  }

  int l=0;
  simulate(points);
  while(l < 51){
    l++;

    int smallest = 10e9;
    int ind = -1;
    for(int i=0; i<n; i++){
      if(smallest > intersections[i] && intersections[i] != 10e9){
        smallest = intersections[i];
        ind = i;
      }
    }

    if(smallest == 10e9)
      break;

    ret[ind] = intersections[ind];
    points[ind].dir = 'C';
    intersections.clear();
    for(int i=0; i<50; i++){
      intersections[i] = 10e9;
    }
    simulate(points);
  }


  for(int intersect : ret){
    if(intersect == 0)
      cout << "Infinity" << endl;
    else
      cout << intersect << endl;
  }
  //print intersects
}
