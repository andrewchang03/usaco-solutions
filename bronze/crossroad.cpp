#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream fin ("crossroad.in");
    ofstream fout ("crossroad.out");
    int N;
    fin >> N;
    int cow[N], pos[N], counter[10] = {0};
    for (int i = 0; i < N; i++) fin >> cow[i] >> pos[i];
    int current, lastSeen, c = 0;
    for (int i = 1; i <= 10; i++) {
        current = i;
        for (int j = 0; j < N; j++) {
            if (cow[j] == current && c == 0) {
                lastSeen = pos[j];
                c++;
            }
            if (cow[j] == current && c!= 0 && lastSeen != pos[j]) {
                lastSeen = pos[j];
                counter[i-1]++;
            }
        }
        c = 0;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += counter[i];
    }
    fout << sum << endl;

    return 0;
}
