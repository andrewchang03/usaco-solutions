#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

struct {
    string person;
    int total;
} gift[10];

int main () {
    // freopen ("gift1.in", "r", stdin);
    // freopen ("gift1.out", "w", stdout);
    map<string, int> m;
    int NP; cin >> NP;
    for (int i = 0; i < NP; i++) {
        string s;
        cin >> s;
        m[s] = i;
        gift[i].person = s;
        gift[i].total = 0;
    }
    int index;
    for (int i = 0; i < NP; i++) {
        string s;
        cin >> s;
        int money, n;
        cin >> money >> n;
        if (n == 0) continue;
        index = m.find(s)->second;
        int left = money % n, donate = money / n;
        gift[index].total += (-money);
        gift[index].total += left;
        for (int j = 0; j < n; j++) {
            string p;
            cin >> p;
            index = m.find(p)->second;
            gift[index].total += donate;
        }
    }
    for (int i = 0; i < NP; i++) {
        cout << gift[i].person << " " << gift[i].total << endl;
    }
}
