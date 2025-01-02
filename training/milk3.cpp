#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int maxA, maxB, maxC;
struct Triplet {int x, y, z;};
queue<Triplet> q;
bool mark[21], visited[21][21];

void bfs (int a, int b, int c) {
    q.push(Triplet{a, b, c});
    while(!q.empty()) {
        int r1 = q.front().x, c1 = q.front().y, d1 = q.front().z;
        q.pop();
        if (visited[r1][c1]) continue;
        visited[r1][c1] = true;
        if (r1 == 0) mark[d1] = true;
        if (r1 != 0 && c1 < maxB) q.push(Triplet{max(0, r1+c1-maxB), min(r1+c1, maxB), d1});
        if (r1 != 0 && d1 < maxC) q.push(Triplet{max(0, r1+d1-maxC), c1, min(r1+d1, maxC)});
        if (c1 != 0 && r1 < maxA) q.push(Triplet{min(c1+r1, maxA), max(0, c1+r1-maxA), d1});
        if (c1 != 0 && d1 < maxC) q.push(Triplet{r1, max(0, c1+d1-maxC), min(c1+d1, maxC)});
        if (d1 != 0 && r1 < maxC) q.push(Triplet{min(d1+r1, maxA), c1, max(0, d1+r1-maxA)});
        if (d1 != 0 && c1 < maxB) q.push(Triplet{r1, min(d1+c1, maxB), max(0, d1+c1-maxB)});
    }
}

int main () {
    // freopen ("milk3.in", "r", stdin);
    // freopen ("milk3.out", "w", stdout);
    cin >> maxA >> maxB >> maxC;
    bfs(0, 0, maxC);
    for (int i = 0; i < 21; i++) if (mark[i] && i != maxC) cout << i << " ";
    cout << maxC << endl;
}
