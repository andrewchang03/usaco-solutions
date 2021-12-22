#include <iostream>
#include <vector>
using namespace std;

struct Grid {
    bool cow, n, w, s, e;
} g[101][101];

bool mark[101][101];
int n, k, r, counter = 0;

void dfs (int x, int y, int initialx, int initialy) {
    if (x < 1 || x > n || y < 1 || y > n || mark[x][y]) return;
    mark[x][y] = true;
    if (g[x][y].cow && !(x == initialx && y == initialy)) counter++;
    if (!g[x][y].n) dfs(x-1, y, initialx, initialy);
    if (!g[x][y].s) dfs(x+1, y, initialx, initialy);
    if (!g[x][y].w) dfs(x, y-1, initialx, initialy);
    if (!g[x][y].e) dfs(x, y+1, initialx, initialy);
}

int main () {
    // freopen("countcross.in", "r", stdin);
    // freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        if (y-w == -1) g[x][y].e = g[z][w].w = true;
        else if (y-w == 1) g[x][y].w = g[z][w].e = true;
        else if (x-z == -1) g[x][y].s = g[z][w].n = true;
        else if (x-z == 1) g[x][y].n = g[z][w].s = true;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y].cow = true;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < v.size(); i++) {
        dfs(v[i].first, v[i].second, v[i].first, v[i].second);
        for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) mark[j][k] = false;
    }
    cout << (k * (k-1) - counter) / 2 << endl;
}