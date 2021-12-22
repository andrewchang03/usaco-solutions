#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Time {
    int arrive, duration, seniority;
} t[100001];

bool sortComp (Time x, Time y) {
    return x.arrive < y.arrive;
}

struct queueComp {
    bool operator () (Time const& x, Time const& y) {
        return x.seniority > y.seniority;
    }
};

priority_queue<Time, vector<Time>, queueComp> q;

int main () {
    // freopen("convention2.in", "r", stdin);
    // freopen("convention2.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i].arrive >> t[i].duration;
        t[i].seniority = i;
    }
    sort(t, t+n, sortComp);
    long long index = 0, time = 0, maximum = 0;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            time = t[i].arrive;
            while (index < n && t[index].arrive <= time) {
                q.push({t[index].arrive, t[index].duration, t[index].seniority});
                index++;
            }
        }
        int a = q.top().arrive, b = q.top().duration;
        q.pop();
        maximum = max(maximum, time-a);
        time += b;
        while (index < n && t[index].arrive <= time) {
            q.push({t[index].arrive, t[index].duration, t[index].seniority});
            index++;
        }
    }
    cout << maximum << endl;
}