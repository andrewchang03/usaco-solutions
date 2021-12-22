#include <iostream>
#include <cstdio>
using namespace std;

int n;
bool globe;

int diff (int first, int second) {
    int dif;
    if (first <= n && first >= n-3 && second <= 4 && second >= 1) {dif = (n-first) + (second-0);}
    else if (second <= n && second >= n-3 && first <= 4 && first >= 1) {dif = (n-second) + (first-0);}
    else {dif = ((second - first > 0) ? second - first : first - second);}
    if (n <= 5) return n;
    switch (dif) {
        case 4:
            globe = false;
            return 1;
            break;
        case 3:
            return 2;
            break;
        case 2:
            return 3;
            break;
        case 1:
            return 4;
            break;
        case 0:
            return 5;
            break;
        default:
            globe = true;
            return 1;
            break;
    }
}

struct Combo {
    int first;
    int second;
    int third;
};

int main () {
    // freopen ("combo.in", "r", stdin);
    // freopen ("combo.out", "w", stdout);
    cin >> n;
    Combo john;
    cin >> john.first >> john.second >> john.third;
    Combo master;
    cin >> master.first >> master.second >> master.third;
    bool one, two, three;
    int val = diff(john.first, master.first) * diff(john.second, master.second) * diff(john.third, master.third);
    diff(john.first, master.first);
    one = globe;
    diff(john.second, master.second);
    two = globe;
    diff(john.third, master.third);
    three = globe;
    if (one && two && three) val = 0;
    int total = ((n > 5) ? 125 * 2 : n * n * n * 2);
    cout << total - val << endl;
}
