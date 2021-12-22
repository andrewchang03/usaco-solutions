#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n;
    cin >> n;
    int height[n];
    int sorted[n];
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        sorted[i] = height[i];
    }
    sort(sorted, sorted+n);
    int swaps = -1;
    for (int a = 0; a < n; a++) {
        if (sorted[a] != height[a]) {
            swaps++;
        }
    }
    swaps = max(0, swaps);
    cout << swaps << endl;
}
