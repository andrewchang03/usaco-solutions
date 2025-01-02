#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main () {
    // freopen ("skidesign.in", "r", stdin);
    // freopen ("skidesign.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int mini = 0, maxi = 17, sum = 0;
    int minimum = 1000000;
    while (maxi <= 100) {
        for (int i = 0; i < n; i++) {
            if (arr[i] < mini) sum += pow((mini - arr[i]), 2);
            if (arr[i] > maxi) sum += pow((arr[i] - maxi), 2);
        }
        minimum = min(minimum, sum);
        sum = 0;
        mini++;
        maxi++;
    }
    cout << minimum << endl;
}
