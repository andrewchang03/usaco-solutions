#include <iostream>
#include <cstdio>
using namespace std;

struct Rect {int x1, y1, x2, y2;};

int main () {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect lawn, feed;
    cin >> lawn.x1 >> lawn.y1 >> lawn.x2 >> lawn.y2;
    cin >> feed.x1 >> feed.y1 >> feed.x2 >> feed.y2;

    if (feed.x2 >= lawn.x2 && feed.x1 <= lawn.x1 && feed.y2 >= lawn.y2 && feed.y1 <= lawn.y1) cout << 0 << endl;
    else if (feed.y2 >= lawn.y2 && feed.y1 <= lawn.y1 && feed.x2 >= lawn.x2) cout << (feed.x1 - lawn.x1) * (lawn.y2 - lawn.y1) << endl;
    else if (feed.y2 >= lawn.y2 && feed.y1 <= lawn.y1 && feed.x1 <= lawn.x1) cout << (lawn.x2 - feed.x2) * (lawn.y2 - lawn.y1) << endl;
    else if (feed.x2 >= lawn.x2 && feed.x1 <= lawn.x1 && feed.y2 >= lawn.y2) cout << (lawn.x2 - lawn.x1) * (feed.y1 - lawn.y1) << endl;
    else if (feed.x2 >= lawn.x2 && feed.x1 <= lawn.x1 && feed.y1 <= lawn.y1) cout << (lawn.x2 - lawn.x1) * (lawn.y2 - feed.y2) << endl;
    else cout << (lawn.x2 - lawn.x1) * (lawn.y2 - lawn.y1) << endl;
}
