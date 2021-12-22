#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    // freopen("lemonade.in", "r", stdin);
    // freopen("lemonade.out", "w", stdout);
    int n, w[10001], x = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w, w+n, greater<int>());
    for (int i = 0; i < n; i++) if (x <= w[i]) x++;
    cout << x << endl;
}