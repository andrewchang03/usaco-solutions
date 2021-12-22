#include <iostream>
using namespace std;

struct Cow {
    int x, y;
} c[100001];

int main () {
    // freopen("pairup.in", "r", stdin);
    // freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i].x >> c[i].y;
    }
}