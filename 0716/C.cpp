#include <iostream>

using namespace std;

int buckets[2][10];
bool milk_possible[2001];

void change(int day, bool turn, int gallon) {
    if(day == 0) {
        milk_possible[gallon] = true;
        return;
    }
    if(day >= 2) change(day - 2, turn, gallon);
    for(int i = 0; i < 10; i++) {
        if(buckets[turn][i] == 0) continue;
        int cur = buckets[turn][i];
        int new_gallon;
        new_gallon = (turn == 0) ? (gallon - cur) : (gallon + cur);
        buckets[turn][i] = 0;
        change(day - 1, !turn, new_gallon);
        buckets[turn][i] = cur;
    }
}

int main() {
    for(int i = 0; i < 2001; i++) {
        milk_possible[i] = false;
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> buckets[i][j];
        }
    }

    change(4, 0, 1000);

    int cnt = 0;
    for(int i = 0; i < 2001; i++) {
        if(milk_possible[i] == true) cnt++;
    }
    cout << cnt << endl;

    return 0;
}