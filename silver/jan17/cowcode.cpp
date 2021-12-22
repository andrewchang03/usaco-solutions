#include <iostream>
#include <math.h>
using namespace std;

int main () {
    // freopen("cowcode.in", "r", stdin);
    // freopen("cowcode.out", "w", stdout);
    string s;
    long long n;
    cin >> s >> n;
    while (n > s.length()) {
        long long x = s.length() * pow(2, (int) log2(n / s.length()));
        if (n == x) x /= 2;
        if (n - x == 1) n--;
        else n = n - x - 1;
    }
    cout << s[n-1] << endl;
}