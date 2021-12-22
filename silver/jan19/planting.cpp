#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> v[100001];
    int n, a, b, ans = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) ans = max(ans, (int) v[i].size()+1);
    cout << ans << endl;
}