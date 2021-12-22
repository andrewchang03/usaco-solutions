#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

string names[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
// Array storing cow name input
string cow[100];
// Array storing amount of milk input
int milk[100];
// Un-merged amount of milk
int cowInt[100][2];

int sum[7][2] = {0};

int indexSearch(string a) {
    int i = 0;
    for (; i < 7; i++) {if (a == names[i]) break;}
    return i;
}

int main () {
    freopen("notlast.in", "r", stdin);
    freopen ("notlast.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cow[i] >> milk[i];
    }
    for (int i = 0; i < n; i++) {
        cowInt[i][0] = indexSearch(cow[i]);
        cowInt[i][1] = milk[i];
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < n; j++) {
            if (cowInt[j][0] == i) {
                sum[i][0] = i;
                sum[i][1] += milk[j];
            }
        }
    }
    // finds second min
    int firstMin = 1000;
    for (int i = 0; i < 7; i++) {
        if (sum[i][1] < firstMin) firstMin = sum[i][1];
    }
    int setter = 1e9;
    int secondMin;
    for (int i = 0; i < 7; i++) {
        if (sum[i][1] > firstMin && sum[i][1] < setter) {
            secondMin = sum[i][1];
            setter = sum[i][1];
        }
    }
    int counter = 0;
    string soloCow;
    for (int i = 0; i < 7; i++) {
        if (sum[i][1] == secondMin) {
            soloCow = names[i];
            counter++;
        }
    }
    if (counter == 1) cout << soloCow << endl;
    else cout << "Tie" << endl;
}
