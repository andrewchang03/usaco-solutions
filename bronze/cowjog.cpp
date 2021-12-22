#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    int n;
    cin >> n;
    int pos[n];
    int speed[n];
    for (int i = 0; i < n; i++) {
        cin >> pos[i] >> speed[i];
    }
    int minimum = speed[n-1];
    int counter = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (speed[i] <= minimum) {
            counter++;
            minimum = speed[i];
        }
    }
    cout << counter << endl;
}
