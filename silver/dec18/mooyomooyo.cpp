#include <iostream>
#include <stack>
using namespace std;

int n, k, g[100][10], it = 0;
string s;
bool mark[100][10], loop;
stack<pair<int, int>> st;

void dfs (int r, int c, int x) {
    if (r < 0 || r >= n || c < 0 || c >= 10 || mark[r][c] || g[r][c] == 0 || g[r][c] != x) return;
    mark[r][c] = true;
    st.push(make_pair(r, c));
    dfs(r-1, c, x);
    dfs(r+1, c, x);
    dfs(r, c-1, x);
    dfs(r, c+1, x);
}

int main () {
    // freopen("mooyomooyo.in", "r", stdin);
    // freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < 10; j++) g[i][j] = s[j] - '0';
    }
    while (loop || it == 0) {
        loop = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (g[i][j] == 0 || mark[i][j]) continue;
                dfs(i, j, g[i][j]);
                if (st.size() >= k) {
                    loop = true;
                    while (!st.empty()) {
                        g[st.top().first][st.top().second] = 0;
                        st.pop();
                    }
                } else while (!st.empty()) st.pop();
            }
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < 10; j++) mark[i][j] = false;
        for (int j = 0; j < 10; j++) {
            int x = 0;
            for (int i = n-1; i >= 0; i--) {
                if (g[i][j] != 0 && x != 0) {
                    g[i+x][j] = g[i][j];
                    g[i][j] = 0;
                } else if (g[i][j] == 0) x++;
            }
        }
        it++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) cout << g[i][j];
        cout << endl;
    }
}