#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Milk {int time, change;} m[10000];
bool comp (Milk x, Milk y) {return x.time < y.time;}

int main () {
    // freopen ("milk2.in", "r", stdin);
    // freopen ("milk2.out", "w", stdout);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i*2].time;
        cin >> m[i*2+1].time;
        m[i*2].change = 1;
        m[i*2+1].change = -1;
    }
    sort(m, m+(n*2), comp);
    int maxone = 0, maxzero = 0, sum = 0, begin = 0, t = 0;
    for (int i = 0; i < n*2; i++) {
        if (t == 0) {
            sum += m[i].change;
            begin = m[i].time;
            t++;
            continue;
        }
        /*
        if (m[i].time == m[i+1].time) {
            sum += m[i].change;
            continue;
        }*/
        if (sum == 0 && sum + m[i].change == 1  && m[i].time != m[i+1].time && m[i].time != m[i-1].time) {
            maxzero = max(maxzero, m[i].time-begin);
            begin = m[i].time;
        }
        if (sum == 1 && sum + m[i].change == 0  && m[i].time != m[i+1].time) {
            maxone = max(maxone, m[i].time-begin);
            begin = m[i].time;
        }
        sum += m[i].change;
    }
    cout << maxone << " " << maxzero << endl;
}
