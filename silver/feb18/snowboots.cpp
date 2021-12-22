#include <iostream>
#include <queue>
using namespace std;

int n, b, f[251], s[251], d[251], minimum = 10000;
bool mark[251][251];

void bfs () {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    while (!q.empty()) {
        int tile = q.front().first, boot = q.front().second;
        q.pop();
        if (mark[tile][boot]) continue;
        mark[tile][boot] = true;
        if (tile == n) {
            minimum = min(minimum, boot-1);
            continue;
        }
        for (int i = 1; i <= d[boot] && tile+i <= n; i++) if (f[tile+i] <= s[boot]) q.push(make_pair(tile+i, boot));
        for (int i = boot+1; i <= b; i++) if (f[tile] <= s[i]) q.push(make_pair(tile, i));
    }
}

int main () {
    // freopen("snowboots.in", "r", stdin);
    // freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= b; i++) cin >> s[i] >> d[i];
    bfs();
    cout << minimum << endl;
}