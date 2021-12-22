#include <iostream>
using namespace std;

int main () {
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    int n, hl = 0, pl = 0, sl = 0, hr = 0, pr = 0, sr = 0, maximum = 0;
    cin >> n;
    char hps[n];
    for (int i = 0; i < n; i++) {
        cin >> hps[i];
        if (hps[i] == 'H') hr++;
        else if (hps[i] == 'P') pr++;
        else if (hps[i] == 'S') sr++;
    }
    maximum = max(max(hl, max(pl, sl)) + max(hr, max(pr, sr)), maximum);
    for (int i = 0; i < n; i++) {
        if (hps[i] == 'H') {hl++; hr--;}
        else if (hps[i] == 'P') {pl++; pr--;}
        else if (hps[i] == 'S') {sl++; sr--;}
        maximum = max(max(hl, max(pl, sl)) + max(hr, max(pr, sr)), maximum);
    }
    cout << maximum << endl;
}