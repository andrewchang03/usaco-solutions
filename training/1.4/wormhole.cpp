#include <iostream>
#include <cstdio>
using namespace std;

int n, paired[15], toright[15], counter = 0;
struct Point {int x, y;} p[15];

void dfs () {
    int i;
    for (i = 1; i <= n; i++) if (paired[i] == 0) break;
    if (i > n) {
        bool cond =  false;
        for (int a = 1; a <= n; a++) {
            int c = a;
            for (int b = 1; b <= n; b++) c = toright[paired[c]];
            if (c) {cond = true;}
        }
        if (cond) counter++;
        return;
    }
    for (int j = i + 1; j <= n; j++) {
        if (paired[j] == 0) {
            paired[i] = j; paired[j] = i;
            dfs();
            paired[i] = 0; paired[j] = 0;
        }
    }
}

int main () {
    // freopen ("wormhole.in", "r", stdin);
    // freopen ("wormhole.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j].x > p[i].x && p[i].y == p[j].y) {
                if (toright[i] == 0 || p[j].x < p[toright[i]].x) toright[i] = j;
            }
        }
    }
    dfs();
    cout << counter << endl;
}
