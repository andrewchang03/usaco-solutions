#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int questions[100001], prefixsum[100001], minarray[100001];

int main () {
    // freopen("homework.in", "r", stdin);
    // freopen("homework.out", "w", stdout);
    int n, minimum = 10001, sum = 0;
    double maximum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> questions[i];
        sum += questions[i];
        prefixsum[i] = prefixsum[i-1] + questions[i];
    }
    for (int i = n; i >= 1; i--) {
        minimum = min(minimum, questions[i]);
        minarray[i] = minimum;
    }
    vector<int> v;
    for (int i = 1; i <= n-2; i++) {
        double x = sum - prefixsum[i];
        x -= minarray[i];
        x /= (n - i - 1);
        if (x > maximum) {
            maximum = x;
            v.clear();
            v.push_back(i);
        } else if (x == maximum) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}