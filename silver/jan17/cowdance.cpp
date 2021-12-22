#include <iostream>
#include <queue>
using namespace std;

int main () {
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    int duration[n+1];
    for (int i = 1; i <= n; i++) cin >> duration[i];
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << i << endl;
            break;
        }
        priority_queue<int, vector<int>, greater<int>> p;
        for (int j = 1; j <= i; j++) p.push(duration[j]);
        int time = 0, index = i+1;
        while (!p.empty()) {
            int x = p.top();
            p.pop();
            time = x;
            if (index <= n) {
                p.push(time + duration[index]);
                index++;
            }
        }
        if (time <= t) {
            cout << i << endl;
            break;
        }
    }
}