#include <iostream>
using namespace std;

int n, g[21][21], v[21][21];

void dfs (int x, int y, int z, int w) {

}

int main () {
    // freopen("where.in", "r", stdin);
    // freopen("where.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            g[i][j] = c - 'A';
        }
    }
    for (int i = 1; i <= n-1; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= n-1; k++) {
                for (int l = k; l <= n; l++) {
                    dfs(i, j, k, l);
                }
            }
        }
    }
}