#include <iostream>
#include <algorithm>
using namespace std;

int haybales[100001];

int binarysearch (int left, int right, int x) {
    int t;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (haybales[middle] == x) return middle;
        if (haybales[middle] < x) left = middle + 1;
        else right = middle - 1;
        t = middle;
    }
    if (haybales[t] > x) return t-1;
    return t;
}

int main () {
    // freopen("haybales.in", "r", stdin);
    // freopen("haybales.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> haybales[i];
    sort(haybales, haybales+n);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int x = binarysearch(0, n-1, a), y = binarysearch(0, n-1, b);
        bool c1 = (a == haybales[x]), c2 = (b == haybales[y]);
        if (c1) cout << y - x + 1 << endl;
        else cout << y - x << endl;
    }
}