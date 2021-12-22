#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[5001];

int main () {
    // freopen("mootube.in", "r", stdin);
    // freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> vec[n+1];
    for (int i = 0; i < n-1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        vec[p].emplace_back(make_pair(q, r));
        vec[q].emplace_back(make_pair(p, r));
    }
    for (int i = 0; i < q; i++) {
        int k, v, counter = 0;
        cin >> k >> v;
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int j = 0; j < vec[x].size(); j++) {
                if (!visited[vec[x][j].first] && vec[x][j].second >= k) {
                    visited[vec[x][j].first] = true;
                    q.push(vec[x][j].first);
                    counter++;
                }
            }
        }
        for (int i = 0; i <= n; i++) visited[i] = false;
        cout << counter << endl;
    }
}