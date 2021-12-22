#include <iostream>
#include <cstdio>
using namespace std;

int matrix[1001][1001];

int main () {
	// freopen("numtri.in", "r", stdin);
	// freopen("numtri.out", "w", stdout);
	int n, answer = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> matrix[i][j];
			matrix[i][j] += max(matrix[i-1][j-1], matrix[i-1][j]);
			if (i == n) answer = max(answer, matrix[i][j]);
		}
	}
	cout << answer << endl;
}
