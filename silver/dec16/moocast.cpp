#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int n;
bool visited[201];
queue<int> q;
struct moocast {int x, y, r;} m[201];
double dist (int x1, int y1, int x2, int y2) {return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));}

int bfs (int index) {
    int counter = 0;
    q.push(index);
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        if (visited[w]) continue;
        visited[w] = true;
        counter++;
        for (int i = 0; i < n; i++) if (dist(m[w].x, m[w].y, m[i].x, m[i].y) <= m[w].r) q.push(i);
    }
    return counter;
}

int main () {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    int maximum = 0;
    for (int i = 0; i < n; i++) cin >> m[i].x >> m[i].y >> m[i].r;
    for (int i = 0; i < n; i++) {
        maximum = max(maximum, bfs(i));
        for (int j = 0; j < 201; j++) visited[j] = false;
    }
    cout << maximum << endl;
}