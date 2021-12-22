#include <iostream>
#include <algorithm>
using namespace std;

struct Bubble {
    int element;
    int initial;
} b[100001];

bool comp (Bubble x, Bubble y) {
    return x.element < y.element || (x.element == y. element && x.initial < y.initial);
}

int main () {
    // freopen("sort.in", "r", stdin);
    // freopen("sort.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i].element;
        b[i].initial = i;
    }
    sort(b, b+n, comp);
    for (int i = 0; i < n; i++) ans = max(ans, b[i].initial - i + 1);
    cout << ans << endl;
}