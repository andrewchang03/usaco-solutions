#include <iostream>
#include <math.h>
using namespace std;

int n, arr[4] = {2, 3, 5, 7};

bool prime (int x) {
	for (int i = 3; i * i <= x; i++) if (x % i == 0) return false;
	return true;
}

void gen (int x, int base) {
	if (base == 0) {
		bool cond = true;
		for (int i = x; i > 10; i /= 10) if (!prime(i)) cond = false;
		if (cond) cout << x << endl;
		return;
	}
	gen(x + base * 1, base / 10);
	gen(x + base * 3, base / 10);
	gen(x + base * 7, base / 10);
	gen(x + base * 9, base / 10);
}

int main () {
	freopen ("sprime.in", "r", stdin);
    freopen ("sprime.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < 4; i++) gen(pow(10, n-1) * arr[i], pow(10, n-2));
}