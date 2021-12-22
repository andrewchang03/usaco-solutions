#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;
struct Prog {int num, diff;};
bool mark[125001];
vector<Prog> v;
bool comp (Prog x, Prog y) {return x.diff < y.diff || (x.diff == y.diff * x.num < y.num);}

int main () {
    // freopen ("ariprog.in", "r", stdin);
    // freopen ("ariprog.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            if (!mark[i*i+j*j]) numbers.push_back(i*i+j*j);
            mark[i*i+j*j] = true;
        }
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            int diff = numbers[j] - numbers[i];
            bool cond = true;
            for (int i = 1; i <= n-2; i++) {
                if (numbers[j] + i * diff > 125001) {
                    cond = false;
                    break;
                }
                if (!mark[numbers[j] + i * diff]) cond = false;
            }
            if (cond) v.push_back({numbers[i], diff});
        }
    }
    sort(v.begin(), v.end(), comp);
    if (v.size() == 0) cout << "NONE" << endl;
    else for (int i = 0; i < v.size(); i++) cout << v[i].num << " " << v[i].diff << endl;
}
