#include <iostream>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int limits[100];
    int current = 0;
    for (int i = 0; i < n; i++) {
        int segment, limit;
        cin >> segment >> limit;
        for (int j = 0; j < segment; j++) {
            limits[current] = limit;
            current++;
        }
    }
    int spd[100];
    current = 0;
    for (int i = 0; i < m; i++) {
        int segment, limit;
        cin >> segment >> limit;
        for (int j = 0; j < segment; j++) {
            spd[current] = limit;
            current++;
        }
    }
    int maxi = 0;
    for (int i = 0; i < 100; i++) {
        if (spd[i] - limits[i] > maxi) maxi = spd[i] - limits[i];
    }
    cout << maxi << endl;
}
