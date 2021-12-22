#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ifstream fin ("cowsignal.in");
    ofstream fout ("cowsignal.out");
    int m, n, k;
    fin >> m >> n >> k;
    string rows[m];
    string newrows[m];
    for (int i = 0; i < m; i++) fin >> rows[i];
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            string x = string(k, rows[a].at(b));
            newrows[a].append(x);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            fout << newrows[i] << endl;
        }
    }
}
