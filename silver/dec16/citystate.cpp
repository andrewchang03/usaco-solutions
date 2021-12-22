#include <iostream>
using namespace std;

int n, address[26][26][26][26], sum;

int main () {
    // freopen("citystate.in", "r", stdin);
    // freopen("citystate.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string city, state;
        cin >> city >> state;
        if (city.substr(0, 2) == state) continue;
        address[city[0]-'A'][city[1]-'A'][state[0]-'A'][state[1]-'A']++;
        sum += address[state[0]-'A'][state[1]-'A'][city[0]-'A'][city[1]-'A'];
    }
    cout << sum << endl;
}