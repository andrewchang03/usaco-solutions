#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");

    int x, y, m;
    int maxQ1, maxQ2;
    fin >> x >> y >> m;
    maxQ1 = m / x;
    maxQ2 = m / y;
    int a[maxQ1+1], b[maxQ2+1];
    for (int i = 0; i < maxQ1+1; i++) {
        a[i] = i;
    }
    for (int i = 0; i < maxQ2+1; i++) {
        b[i] = i;
    }
    int milk = 0, newMax = 0;
    for (int i = 0; i <= maxQ1; i++) {
        for (int j = 0; j <= maxQ2; j++) {
            milk = x * a[i] + y * b[j];
            if (milk > newMax && milk <= m) newMax = milk;
        }
    }

    fout << newMax << endl;

}
