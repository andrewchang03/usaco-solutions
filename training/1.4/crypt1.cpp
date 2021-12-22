#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

set<int> s;
int arr[10], n, counter = 0;

void crypt (int k) {
    if (k == 5) {
        int x = 100 * arr[0] + 10 * arr[1] + arr[2], y = 10 * arr[3] + arr[4];
        int a = x * arr[3], b = x * arr[4], c = x * y;
        if (a / 1000 >= 1 || b / 1000 >= 1 || c / 10000 >= 1) return;
        // cout << x << " " << y << " " << a << " " << b << " " << x * y << " " << counter << endl;
        while (a / 10 >= 0) {
            if (a / 10 == 0 && s.find(a) != s.end()) break;
            else if (s.find(a % 10) != s.end()) a /= 10;
            else return;
        }
        while (b / 10 >= 0) {
            if (b / 10 == 0 && s.find(b) != s.end()) break;
            else if (s.find(b % 10) != s.end()) b /= 10;
            else return;
        }
        while (c / 10 >= 0) {
            if (c / 10 == 0 && s.find(c) != s.end()) break;
            else if (s.find(c % 10) != s.end()) c /= 10;
            else return;
        }
        counter++;
    } else {
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            if (k == 0 && (*it) == 0) continue;
            arr[k] = (*it);
            crypt(k+1);
        }
    }
}

int main () {
    // freopen ("crypt1.in", "r", stdin);
    // freopen ("crypt1.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    crypt(0);
    cout << counter << endl;
}
