#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    ifstream fin ("dict.txt");
    string word[5];
    cout << word.length << endl;

    //string arr[5];
    //for (int i = 0; i < arr.length; i++) fin >> arr[i];
    string word = arr[srand(time(0))%5];
    string reveal = word;
    for (int i = 0; i < word.length(); i++) reveal[i] = '_';
    int mistakes = 0, catches = 0;
    char input;
    vector<char> used;
    while (mistakes < 5) {
        int counter = 0;
        bool exist = false;
        cout << "Enter a character:" << endl;
        cin >> input;
        for (int i = 0; i < used.size(); i++) if (used[i] == input) exist = true;
        if (exist) {
            cout << "Used letters: ";
            for (int i = 0; i < used.size(); i++) cout << used[i] << ' ';
            cout << endl << "You already entered that letter. Please try again." << endl << endl;
            continue;
        }
        exist = false;
        used.push_back(input);
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == input) {
                reveal[i] = input;
                counter++;
                catches++;
            }
        }
        if (counter == 0) {
            mistakes++;
            cout << "Oops! Current # of mistakes: " << mistakes << endl;
            cout << "Used letters: ";
            for (int i = 0; i < used.size(); i++) cout << used[i] << ' ';
            cout << endl << reveal << endl << endl;
        } else {
            cout << "Nice catch! Current # of mistakes: " << mistakes << endl;
            cout << "Used letters: ";
            for (int i = 0; i < used.size(); i++) cout << used[i] << ' ';
            cout << endl << reveal << endl << endl;
        }
        if (catches == word.length()) {
            cout << "Great job! You got it! You win!" << endl;
            break;
        }
        counter = 0;
    }
}
