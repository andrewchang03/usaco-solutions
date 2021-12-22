#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main () {
    cout << "PACMAN GAME" << endl;
    ifstream fin ("pacman.txt");
    int n, mod, x, y;
    fin >> n;
    string ws, maze[n];
    getline(fin, ws);
    char arr[10] = {'.', '.', 'M', '.', '.', '.', '.', 'G', '.', '.'};
    for (int i = 0; i < n; i++) getline(fin, maze[i]);
    srand(time(NULL));
    int monster = 0, gemnum = 0, gemcol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < maze[i].length(); j++) {
            if (maze[i][j] == 'P') {
                x = i;
                y = j;
            }
            if (maze[i][j] == '.') {
                maze[i][j] = arr[rand()%10];
                if (maze[i][j] == 'M') {
                    monster++;
                    if (monster == 2) arr[2] = 'G';
                }
                if (maze[i][j] == 'G') gemnum++;
            }
        }
    }
    char input;
    bool cond = true;
    while (cond) {
        cout << endl;
        for (int i = 0; i < n; i++) cout << maze[i] << endl;
        cout << endl << "Enter 'a' for left, 'd' for right, 'w' for up, 's' for down, \navoid monsters (M), collect all gems (G) and go to the exit (E): " << endl;
        cin >> input;
        switch (input) {
            case 'a':
                if (maze[x][y-1] == '#') {
                    cout << endl << "INVALID MOVE" << endl;
                    break;
                } else if (maze[x][y-1] == 'E') {
                    cout << endl << "YOU WIN!" << endl;
                    cond = false;
                    break;
                } else if (maze[x][y-1] == 'G') {
                    maze[x][y-1] = '.';
                    swap(maze[x][y], maze[x][y-1]);
                    gemcol++;
                    break;
                }
                swap(maze[x][y], maze[x][y-1]);
                y--;
                break;
            case 'd':
                if (maze[x][y+1] == '#') {
                    cout << endl << "INVALID MOVE" << endl;
                    break;
                } else if (maze[x][y+1] == 'E') {
                    cout << endl << "YOU WIN!" << endl;
                    cond = false;
                    break;
                } else if (maze[x][y+1] == 'G') {
                    maze[x][y+1] = '.';
                    swap(maze[x][y], maze[x][y+1]);
                    gemcol++;
                    break;
                }
                swap(maze[x][y], maze[x][y+1]);
                y++;
                break;
            case 'w':
                if (maze[x-1][y] == '#') {
                    cout << endl << "INVALID MOVE" << endl;
                    break;
                } else if (maze[x-1][y] == 'E') {
                    cout << endl << "YOU WIN!" << endl;
                    cond = false;
                    break;
                } else if (maze[x-1][y] == 'G') {
                    maze[x-1][y] = '.';
                    swap(maze[x][y], maze[x-1][y]);
                    gemcol++;
                    break;
                }
                swap(maze[x][y], maze[x-1][y]);
                x--;
                break;
            case 's':
                if (maze[x+1][y] == '#') {
                    cout << endl << "INVALID MOVE" << endl;
                    break;
                } else if (maze[x+1][y] == 'E') {
                    cout << endl << "YOU WIN!" << endl;
                    cond = false;
                    break;
                } else if (maze[x+1][y] == 'G') {
                    maze[x+1][y] = '.';
                    swap(maze[x][y], maze[x+1][y]);
                    gemcol++;
                    break;
                }
                swap(maze[x][y], maze[x+1][y]);
                x++;
                break;
            case 'q':
                cond = false;
                cout << endl << "GAME OVER" << endl;
                break;
        }
    }
}
