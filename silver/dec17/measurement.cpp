#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Cow {int day, id, delta;} c[100001];
bool comp (Cow a, Cow b) {return a.day < b.day;}
map<int, int, greater<int>> p, m;

int main () {
    // freopen("measurement.in", "r", stdin);
    // freopen("measurement.out", "w", stdout);
    // notice cow id range is between 1 and billion but since n is less than 100K, there is no more than 100K cow ids
    int n, g, counter = 0;
    cin >> n >> g;
    for (int i = 0; i < n; i++) cin >> c[i].day >> c[i].id >> c[i].delta;
    sort(c, c+n, comp);
    m[0] = n;
    for (int i = 0; i < n; i++) {
        bool b = (p[c[i].id] == m.begin()->first); // if it was max or not
        int g = m[p[c[i].id]];
        if (m[p[c[i].id]] == 1) m.erase(p[c[i].id]);
        else m[p[c[i].id]]--;
        p[c[i].id] += c[i].delta;
        m[p[c[i].id]]++;
        if (b) {
            if (p[c[i].id] != m.begin()->first) counter++;
            else if (g == 1 && m[p[c[i].id]] >= 2) counter++;
            else if (g > 1 && m[p[c[i].id]] == 1) counter++;
        } else if (p[c[i].id] == m.begin()->first) counter++;
    }
    cout << counter << endl;
}