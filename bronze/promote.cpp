#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream fin ("promote.in");
    ofstream fout ("promote.out");
    int b1, b2, s1, s2, g1, g2, p1, p2;
    fin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;
    fout << s2 + g2 + p2 - s1 - g1 - p1 << endl;
    fout << g2 + p2 - g1 - p1 << endl;
    fout << p2 - p1 << endl;
    return 0;
}
