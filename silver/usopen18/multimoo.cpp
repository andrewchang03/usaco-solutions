#include <iostream>
#include <queue>
using namespace std;

int n, g[250][250], d[250][250], p[62500], id = 0, f, s;
bool v[250][250];
queue<pair<int, int>> q;

int main () {
    // freopen("multimoo.in", "r", stdin);
    // freopen("multimoo.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> g[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j]) continue;
            int x = g[i][j], y = 0;
            q.push(make_pair(i, j));
            while (!q.empty()) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                if (r < 0 || r >= n || c < 0 || c >= n || v[r][c] || g[r][c] != x) continue;
                y++;
                v[r][c] = true;
                d[r][c] = id;
                q.push(make_pair(r+1, c));
                q.push(make_pair(r-1, c));
                q.push(make_pair(r, c+1));
                q.push(make_pair(r, c-1));
            }
            f = max(f, y);
            p[id] = y;
            id++;
        }
    }
    for (int i = 0; i < 10; i++) cout << p[i] << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i-1 >= 0 && d[i][j] != d[i-1][j]) {
                s = max(s, p[d[i][j]] + p[d[i-1][j]]);
            }
            if (i+1 < n && d[i][j] != d[i+1][j]) {
                s = max(s, p[d[i][j]] + p[d[i+1][j]]);
            }
            if (j-1 >= 0 && d[i][j] != d[i][j-1]) {
                s = max(s, p[d[i][j]] + p[d[i][j-1]]);
            }
            if (j+1 < n && d[i][j] != d[i][j+1]) {
                s = max(s, p[d[i][j]] + p[d[i][j+1]]);
            }
        }
    }
    cout << f << endl;
    cout << s << endl;
}