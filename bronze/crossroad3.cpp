#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int n;
    fin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i] >> b[i];
    }
    int currentMin = 0, minDecide = 1000000, time = 0, index = 0;
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < n; i++) {
            if (a[i] > currentMin && a[i] < minDecide) {
                minDecide = a[i];
                index = i;
            }
        }
        currentMin = minDecide;
        minDecide = 1000000;
        if (currentMin > time) time = a[index] + b[index];
        else time += b[index];
    }
    fout << time << endl;
}
