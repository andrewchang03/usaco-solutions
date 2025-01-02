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
    // freopen ("palsquare.in", "r", stdin);
    // freopen ("palsquare.out", "w", stdout);
    int b; cin >> b;
    for (int i = 1; i <= 300; i++) {
        int x = i * i;
        string s = convert(x, b);
        if (palindrome(s)) cout << convert(i, b) << " " << s << endl;
    }
}
