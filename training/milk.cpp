#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Farmer {int pi, ai;} f[5000];

bool comp (Farmer x, Farmer y) {return x.pi < y.pi;};

int main () {
    // freopen ("milk.in", "r", stdin);
    // freopen ("milk.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> f[i].pi >> f[i].ai;
    sort(f, f+m, comp);
    int cost = 0;
    for (int i = 0; i < m; i++) {
        if (f[i].ai <= n) {
            cost += (f[i].pi * f[i].ai);
            n -= f[i].ai;
        } else {
            cost += (n * f[i].pi);
            break;
        }
    }
    cout << cost << endl;
}
