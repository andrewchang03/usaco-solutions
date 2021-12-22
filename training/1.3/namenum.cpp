#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<char, string> m;
vector<string> v;
vector<string> text;
string n;

void word (string s, int pos) {
    if (pos == n.length()) {
        if (binary_search(text.begin(), text.end(), s)) v.push_back(s);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (i != 0) s.pop_back();
        s.push_back((m.find(n[pos])->second)[i]);
        word(s, pos+1);
    }
}

int main () {
    // freopen ("namenum.in", "r", stdin);
    // freopen ("namenum.out", "w", stdout);
    ifstream fin("dict.txt");
    cin >> n;
    m['2'] = "ABC"; m['3'] = "DEF"; m['4'] = "GHI";
    m['5'] = "JKL"; m['6'] = "MNO"; m['7'] = "PRS";
    m['8'] = "TUV"; m['9'] = "WXY";
    string y; while (fin >> y) text.push_back(y);
    word("", 0);
    sort(v.begin(), v.end());
    if (v.size() == 0) cout << "NONE" << endl;
    else for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}
