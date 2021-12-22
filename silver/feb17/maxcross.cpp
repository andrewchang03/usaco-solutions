#include <iostream>
#include <climits>
using namespace std;

bool crosswalk[100001];
int num[100001];

int main () {
    // freopen("maxcross.in", "r", stdin);
    // freopen("maxcross.out", "w", stdout);
    int n, k, b;
    cin >> n >> k >> b;
    for (int i = 1; i <= b; i++) {
        int x;
        cin >> x;
        crosswalk[x] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (crosswalk[i]) num[i] = num[i-1] + 1;
        else num[i] = num[i-1];
    }
    int minimum = INT_MAX;
    for (int i = 1; i <= n-k+1; i++) {
        int counter = num[i+k-1] - num[i];
        minimum = min(minimum, counter);
    }
    cout << minimum << endl;
}