#include <iostream>
#include <queue>
using namespace std;

struct Shuffle {int pos, delta;} s[100001];

int main() {
    // freopen("shuffle.in", "r", stdin);
    // freopen("shuffle.out", "w", stdout);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s[i].pos = x;
        s[x].delta++;
    }
    queue<int> q;
    int counter = n;
    for (int i = 1; i <= n; i++) if (s[i].delta == 0) {q.push(i); counter--;}
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (s[s[t].pos].delta == 1) {
            q.push(s[t].pos);
            counter--;
        }
        if (s[s[t].pos].delta >= 2) s[s[t].pos].delta--;
    }
    cout << counter << endl;
}