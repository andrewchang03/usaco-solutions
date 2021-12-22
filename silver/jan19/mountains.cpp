#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Mountain {
    int x, y;
} m[100001];

bool comp (Mountain a, Mountain b) {
    return a.x < b.x;
}

int main () {
    // freopen("mountains.in", "r", stdin);
    // freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i].x >> m[i].y;
    sort(m, m+n, comp);
    vector<pair<int, int>> v;
    v.push_back(make_pair(m[0].x, m[0].y));
    for (int i = 1; i < n; i++) {
        int a = m[i].x, b = m[i].y, c = v[v.size()-1].first, d = v[v.size()-1].second;
        if (abs(a - c) > abs(b - d)) {
            v.push_back(make_pair(a, b));
            continue;
        }
        if (b < d && abs(a - c) <= abs(b - d)) continue;
        if (abs(a - c) <= abs(b - d)) {
            for (int j = 0; j < v.size();) {
                if (abs(a - v[j].first) > abs(b - v[j].second)) j++;
                else v.erase(v.begin()+j);
            }
        }
        v.push_back(make_pair(a, b));
    }
    cout << v.size() << endl;
}