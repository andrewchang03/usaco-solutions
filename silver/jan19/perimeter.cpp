#include <iostream>
#include <queue>
using namespace std;
int n, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
char grid[1001][1001];
bool visited[1001][1001];
bool mark[1001][1001];
struct Ice {
    int x, y;
};
int area = 0, perimeter = 0;
int maxarea = 0, minperi = 0;

void bfs (int x, int y) {
    queue<Ice> q;
    q.push({x, y});
    while (!q.empty()) {
        int r = q.front().x, c = q.front().y;
        q.pop();
        if (r < 0 || r >= n || c < 0 || c >= n || visited[r][c] || grid[r][c] == '.') continue;
        visited[r][c] = true;
        area++;
        for (int i = 0; i < 4; i++) {
            if (r+dx[i] == n || c+dy[i] == n) perimeter++;
            else if (grid[r+dx[i]][c+dy[i]] == '.') {
                if (!mark[r+dx[i]][c+dy[i]]) mark[r+dx[i]][c+dy[i]] = true;
                perimeter++;
            }
            q.push({r+dx[i], c+dy[i]});
        }
    }
}

void peri (int x, int y) {
    queue<Ice> q;
    q.push({x, y});
    while (!q.empty()) {
        int r = q.front().x, c = q.front().y;
        q.pop();
        if (r < 0 || r >= n || c < 0 || c >= n || !visited[r][c] || grid[r][c] == '#') continue;
    }
}

int main () {
    // freopen("perimeter.in", "r", stdin);
    // freopen("perimeter.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') continue;
            area = 0;
            perimeter = 0;
            bfs(i, j);
            if (area > maxarea) {
                maxarea = area;
                minperi = perimeter;
            } else if (area == maxarea) {
                minperi = min(minperi, perimeter);
            }
        }
    }
    cout << maxarea << " " << minperi << endl;
}