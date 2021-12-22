#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c, t[100000];

bool pos (int wait) {
    int bus = 1;
    int firstArrival = t[0];
    int firstIndex = 0;
    for (int i = 1; i < n; i++) {
        if (t[i] - firstArrival > wait || i + 1 - firstIndex > c) {
            bus += 1;
            firstArrival = t[i];
            firstIndex = i;
        }
    }
    return (bus <= m);
}

int binSearch (int low, int high) {
    if (low == high) return low;
    if (low + 1 == high) {
        if (pos(low)) return low;
        return high;
    }
    int mid = (low + high) / 2;
    if (pos(mid)) return binSearch(low, mid);
    else return binSearch(mid+1, high);
}

int main () {
    // freopen("convention.in", "r", stdin);
    // freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t, t+n);
    cout << binSearch(0, 1000000000) << endl;
}