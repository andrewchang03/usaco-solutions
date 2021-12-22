#include <iostream>
#include <fstream>
using namespace std;
 
struct Rect {
  int x1, y1, x2, y2;
};
 
int area(Rect r)
{
  return (r.x2 - r.x1) * (r.y2 - r.y1);
}
 
int intersect_area(Rect p, Rect q)
{
  int x_overlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
  int y_overlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
  return x_overlap * y_overlap;
}
 
int main(void)
{
  ifstream fin ("billboard.in");
  ofstream fout ("billboard.out");
  
  Rect a, b, t;  // billboards A & B, and the truck
 
  fin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  fin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  fin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
 
  fout << area(a) + area(b) - intersect_area(a,t) - intersect_area(b,t) << "\n";
 
  return 0;
}