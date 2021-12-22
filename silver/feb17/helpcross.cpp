#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

multiset<int> chickens;
vector<pair<int, int>> cows;

int main () {
    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    int x, y, counter = 0;
    for (int i = 0; i < c; i++) {
        cin >> x;
        chickens.insert(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cows.push_back(make_pair(y, x));
    }
    sort(cows.begin(), cows.end());
    for (int j = 0; j < n; j++) {
        auto index = chickens.lower_bound(cows[j].second);
        if (index != chickens.end() && *index <= cows[j].first) {
            counter++;
            chickens.erase(index);
        }
    }
    cout << counter << endl;
}