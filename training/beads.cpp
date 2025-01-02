#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    // freopen ("beads.in", "r", stdin);
    // freopen ("beads.out", "w", stdout);
    int n, maximum = 0; cin >> n;
    string beads; cin >> beads;
    bool visit[n]; for (int i = 0; i < n; i++) visit[i] = false;
    for (int i = 0; i < n; i++) {
        int left = ((i-1 == -1) ? n-1 : i-1), right = i, counter = 0;
        char li = beads[left], ri = beads[right];
        for (int j = left;; j--) {
            if (li == 'w' && beads[j] != 'w') li = beads[j];
            if (j == -1) j = n-1;
            if (visit[j]) break;
            if (beads[j] != 'w' && beads[j] != li) break;
            visit[j] = true;
            counter++;
            if ((j-1 == -1 ? n-1 : j-1) == left) break;
        }
        if (counter == n) {
            maximum = counter;
            break;
        }
        for (int j = right;; j++) {
            if (ri == 'w' && beads[j] != 'w') ri = beads[j];
            if (j == n) j = 0;
            if (visit[j]) break;
            if (beads[j] != 'w' && beads[j] != ri) break;
            visit[j] = true;
            counter++;
            if ((j+1 == n ? 0 : j+1) == right) break;
        }
        maximum = max(maximum, counter);
        counter = 0;
        for (int j = 0; j < n; j++) visit[j] = false;
    }
    cout << maximum << endl;
}
