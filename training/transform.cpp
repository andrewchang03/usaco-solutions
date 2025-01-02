#include <iostream>
#include <cstdio>
using namespace std;

char before[10][10], after[10][10], c[10][10];
int minimum = 8;

bool one (char arr[10][10], int l, bool b) {
    int xi = 0, yi = 0;
    for (int i = 0; i < l; i++) {
        for (int j = l-1; j >= 0; j--) {
            if (arr[j][i] != after[xi][yi]) return false; yi++;
        }
        xi++; yi = 0;
    }
    if (b) minimum = min(minimum, 5);
    else minimum = min(minimum, 1);
    return true;
}

bool two (char arr[10][10], int l, bool b) {
    int xi = 0, yi = 0;
    for (int i = l-1; i >= 0; i--) {
        for (int j = l-1; j >= 0; j--) {
            if (arr[i][j] != after[xi][yi]) return false; yi++;
        }
        xi++; yi = 0;
    }
    if (b) minimum = min(minimum, 5);
    else minimum = min(minimum, 2);
    return true;
}

bool three (char arr[10][10], int l, bool b) {
    int xi = 0, yi = 0;
    for (int i = l-1; i >= 0; i--) {
        for (int j = 0; j < l; j++) {
            if (arr[j][i] != after[xi][yi]) return false; yi++;
        }
        xi++; yi = 0;
    }
    if (b) minimum = min(minimum, 5);
    else minimum = min(minimum, 3);
    return true;
}

bool four (int l) {
    bool cond = true;
    int xi = 0, yi = 0;
    for (int i = 0; i < l; i++) {
        for (int j = l-1; j >= 0; j--) {
            if (before[i][j] != after[xi][yi]) cond = false;
            c[xi][yi] = before[i][j]; yi++;
        }
        xi++; yi = 0;
    }
    if (!cond) return false;
    minimum = min(minimum, 4);
    return true;
}

bool five (int l) {
    if (one(c, l, true) || two(c, l, true) || three(c, l, true)) {
        minimum = min(minimum, 5);
        return true;
    }
    return false;
}

bool six (int l) {
    for (int i = 0; i < l; i++) for (int j = 0; j < l; j++) if (before[i][j] != after[i][j]) return false;
    minimum = min(minimum, 6);
    return true;
}

int main () {
    // freopen ("transform.in", "r", stdin);
    // freopen ("transform.out", "w", stdout);
    int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> before[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> after[i][j];
    one(before, n, false); two(before, n, false); three(before, n, false);
    four(n); five(n); six(n);
    if (minimum == 8) cout << 7 << endl;
    else cout << minimum << endl;
}
