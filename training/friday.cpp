#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main () {
    // freopen ("friday.in", "r", stdin);
    // freopen ("friday.out", "w", stdout);
    int n; cin >> n;
    int days[7];
    for (int i = 0; i < 7; i++) days[i] = 0;
    int init = 5;
    days[init]++;
    for (int year = 1900; year < 1900 + n; year++) {
        bool leap = (year % 4 == 0);
        if (year % 4 == 0 && year % 400 != 0 && year % 100 == 0) leap = false;
        for (int i = 1; i <= 12; i++) {
            if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 12)) {
                init = (init + (31 % 7)) % 7;
                days[init]++;
            } else if ((i == 4) || (i == 6) || (i == 9) || (i == 11)) {
                init = (init + (30 % 7)) % 7;
                days[init]++;
            } else if (i == 2) {
                if (leap) init = (init + (29 % 7)) % 7;
                else init = (init + (28 % 7)) % 7;
                days[init]++;
            }
        }
    }
    days[init]--;
    cout << days[5] << " ";
    cout << days[6] << " ";
    cout << days[0] << " ";
    cout << days[1] << " ";
    cout << days[2] << " ";
    cout << days[3] << " ";
    cout << days[4] << endl;
}
