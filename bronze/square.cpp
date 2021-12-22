#include <iostream>
#include <fstream>
using namespace std;

struct Point {int x1, y1, x2, y2;};
int main(){
  ifstream fin ("square.in");
  ofstream fout("square.out");
  Point a, b;
  int n;
  fin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  n = max(max(a.x2, b.x2) - min(a.x1, b.x1), max(a.y2, b.y2) - min(a.y1, b.y1));
  fout << n * n << endl;
}
