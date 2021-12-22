#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ifstream fin ("blocks.in");
    ofstream fout ("blocks.out");
    int N;
    fin >> N;
    string a[N], b[N];
    for (int i = 0; i < N; i++) {
        fin >> a[i] >> b[i];
    }
    int num3[26] = {0};
    for (int i = 0; i < N; i++) {
        int num1[26] = {0};
        int num2[26] = {0};
        for (int j = 0; j < a[i].length(); j++) {
            num1[(a[i].at(j)-'a')]++;
        }
        for (int j = 0; j < b[i].length(); j++) {
            num2[b[i].at(j)-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            num3[i] += max(num1[i], num2[i]);
        }
    }
    for (int i = 0; i < 26; i++) {
        fout << num3[i] << endl;
    }
}
