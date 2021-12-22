#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    ifstream fin ("circlecross.in");
    ofstream fout ("circlecross.out");
    string cows;
    fin >> cows;
    fin.close();
    int cross[52];
    for (int i = 0; i < 52; i++) {
        cross[i] = cows.at(i) - 'A';
    }
    int index[26][2];
    bool first = true, second = true;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 52; j++) {
            if (cross[j] == i) {
                index[i][0] = j;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 51; j >= 0; j--) {
            if (cross[j] == i) {
                index[i][1] = j;
                break;
            }
        }
    }
    int counter = 0;
    int intersect = 0;
    for (int a = 0; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            for (int c = index[a][0]+1; c < index[a][1]; c++) {
                if (cross[c] == b) counter++;
            }
            if (counter == 1) intersect++;
            counter = 0;
        }
    }
    fout << intersect / 2 << endl;

}
