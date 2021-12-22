#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string convert (int num, int base) {
    int a = 1;
    while (a <= num) a *= base;
    a /= base;
    string s = "";
    while (a >= 1) {
        int p = num / a; char q;
        if (p < 10) q = (char) (p + 48);
        else q = (char) (p + 55);
        s.push_back(q);
        num -= (a * p);
        a /= base;
    }
    return s;
}

bool palindrome (string s) {
    int l = 0, r = s.length()-1;
    while (r-l >= 1) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main () {
    // freopen ("dualpal.in", "r", stdin);
    // freopen ("dualpal.out", "w", stdout);
    int n, s, counter = 0; cin >> n >> s;
    while (counter < n) {
        s++;
        int x = 0; bool cond = false;
        for (int i = 2; i <= 10; i++) {
            if (palindrome(convert(s, i))) x++;
            if (x == 2) {cond = true; break;}
        }
        if (cond) {
            cout << s << endl;
            counter++;
        }
    }
}
