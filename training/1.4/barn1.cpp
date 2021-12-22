#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    // freopen ("barn1.in", "r", stdin);
    // freopen ("barn1.out", "w", stdout);
    int m, s, c; cin >> m >> s >> c;
    int arr[c], answer = c; for (int i = 0; i < c; i++) cin >> arr[i];
    sort(arr, arr+c);
    vector<int> v;
    for (int i = 0; i < c; i++) if (i != 0 && arr[i] - arr[i-1] >= 2) v.push_back(arr[i] - arr[i-1] - 1);
    sort(v.begin(), v.end());
    int limit = ((v.size() < m) ? 0 : (v.size() - (m-1)));
    for (int i = 0; i < limit; i++) answer += v[i];
    cout << answer << endl;
}
