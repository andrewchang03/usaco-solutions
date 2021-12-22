#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    freopen ("hps.in", "r", stdin);
    freopen ("hps.out", "w", stdout);
    int n;
    cin >> n;
    // initialize a 2D array to store the number of each ordered pair that shows up
    int matches[4][4] = {0};
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        matches[first][second]++;
    }
    // compute the maximum number of wins
    int maximumWins = matches[1][2] + matches[2][3] + matches[3][1];
	if (matches[1][3] + matches[3][2] + matches[2][1] > maximumWins) {
		maximumWins = matches[1][3] + matches[3][2] + matches[2][1];
	}
    cout << maximumWins << endl;
}
