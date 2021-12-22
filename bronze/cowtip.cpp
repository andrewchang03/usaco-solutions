#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main () {
    freopen ("cowtip.in", "r", stdin);
    freopen ("cowtip.out", "w", stdout);
    int n;
    cin >> n;
    char grid[n][n];
    const char wrong = '1';
	const char correct = '0';
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
		for (int j = 0; j < n; j++) {
			grid[i][j] = s.at(j);
		}
	}
	int numTips = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if (grid[i][j] == wrong) {
				numTips++;
				for (int a = 0; a <= i; a++) {
					for (int b = 0; b <= j; b++) {
						if (grid[a][b] == wrong) grid[a][b] = correct;
						else grid[a][b] = wrong;
					}
				}
			}
		}
	}
	cout << numTips << endl;
}
