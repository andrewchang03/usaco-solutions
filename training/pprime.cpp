#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v = {3, 5, 7, 11};

bool prime (int x) {
	for (int i = 3; i * i <= x; i++) if (x % i == 0) return false;
	return true;
}

int main () {
	freopen ("pprime.in", "r", stdin);
    	freopen ("pprime.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= 9; i += 2) {
		for (int j = 0; j <= 9; j++) {
			v.push_back(100*i+10*j+i);
			v.push_back(1000*i+100*j+10*j+i);
			for (int k = 0; k <= 9; k++) {
				v.push_back(10000*i+1000*j+100*k+10*j+i);
				v.push_back(100000*i+10000*j+1000*k+100*k+10*j+i);
				for (int l = 0; l <= 9; l++) {
					v.push_back(1000000*i+100000*j+10000*k+1000*l+100*k+10*j+i);
					v.push_back(10000000*i+1000000*j+100000*k+10000*l+1000*l+100*k+10*j+i);
				}
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) if (prime(v[i]) && v[i] >= a && v[i] <= b) cout << v[i] << endl;
}
