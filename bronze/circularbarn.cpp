#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int rooms[n];
    for (int i = 0; i < n; i++) cin >> rooms[i];
    int minimum = 100 * n * n;
    for (int open = 0; open < n; open++) {
        int dist = 0;
        for (int rp = 0; rp < n; rp++) {
            dist += rp * rooms[(rp+open) % n];
        }
        if (dist < minimum) {
            minimum = dist;
        }
    }
    cout << minimum << endl;
}
