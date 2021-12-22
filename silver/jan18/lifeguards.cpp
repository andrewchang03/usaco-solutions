#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int cows[100001];

struct Lifeguards {
    int time, delta, id;
} l[200001];

bool comp (Lifeguards x, Lifeguards y) {
    return x.time < y.time;
}

int main () {
    // freopen("lifeguards.in", "r", stdin);
    // freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i*2].time >> l[i*2+1].time;
        l[i*2].delta = 1;
        l[i*2+1].delta = -1;
        l[i*2].id = i+1;
        l[i*2+1].id = i+1;
    }
    sort(l, l+n*2, comp);
    // when cow is alone, counter up by 1, then subtract from total
    set<int> s;
    int total = 0, sum = 0, c = 0;
    for (int i = 0; i < n*2-1; i++) {
        c += l[i].delta;
        if (l[i].delta == 1) s.insert(l[i].id);
        else s.erase(s.find(l[i].id));
        if (s.size() == 1) cows[* s.begin()] += (l[i+1].time - l[i].time);
        if (c != 0) total += (l[i+1].time - l[i].time);
    }
    sort(cows+1, cows+n+1);
    cout << total - cows[1] << endl;
}