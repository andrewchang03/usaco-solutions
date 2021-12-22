#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;
    int start[n], ends[n];
    int boolarr[1001];
    for (int i = 0; i < 1001; i++) boolarr[i] = 0;
    for (int i = 0; i < n; i++) cin >> start[i] >> ends[i];

    int out = 0;
    int maximum = 0;
    int counter = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (out == j) continue;
            for (int k = start[j]; k < ends[j]; k++) {
                boolarr[k] = 1;
            }
        }
        for (int m = 0; m < 1001; m++) {
            if (boolarr[m] == 1) counter++;
        }
        if (counter > maximum) maximum = counter;
        counter = 0;
        for (int p = 0; p < 1001; p++) boolarr[p] = 0;
        out++;
    }
    cout << maximum << endl;
}
