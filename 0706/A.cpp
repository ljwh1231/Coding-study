#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

deque<int> gears[5];
bool rotated[5];
int ret = 0;
void rotate(int _gear, int _dir) {
    if(rotated[_gear] == true) return;
    rotated[_gear] = true;

    if(_gear == 1) {
        if(gears[_gear][2] != gears[_gear + 1][6]) {
            rotate(_gear + 1, (-1) * _dir);
        }
    } else if(_gear == 4) {
        if(gears[_gear][6] != gears[_gear - 1][2]) {
            rotate(_gear - 1, (-1) * _dir);
        }
    } else {
        // cout << "debug: " << gears[_gear][6] << " " << gears[_gear - 1][2] << endl;
        if(gears[_gear][6] != gears[_gear - 1][2]) {
            rotate(_gear - 1, (-1) * _dir);
        }

        if(gears[_gear][2] != gears[_gear + 1][6]) {
            rotate(_gear + 1, (-1) * _dir);
        }
    }

    if(_dir == 1) {
        int temp = gears[_gear][7];
        gears[_gear].pop_back();
        gears[_gear].push_front(temp);
    } else if(_dir == -1) {
        int temp = gears[_gear][0];
        gears[_gear].pop_front();
        gears[_gear].push_back(temp);
    }
}

int main() {
    for(int i = 1; i <= 4; i++) {
        string gear;
        cin >> gear;
        for(int j = 0; j < 8; j++) {
            gears[i].push_back((int)(gear[j] - 48));
        }
    }
    
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int gear_num, dir;
        cin >> gear_num >> dir;
        rotate(gear_num, dir);
        for(int i = 1; i <= 4; i++) {
            rotated[i] = false;
        }
    }
    for(int i = 1; i <= 4; i++) {
        if(gears[i][0] == 1) {
            ret += (int)(pow((double)2, (double)(i - 1)));
        } else {
            continue;
        }
    }
    cout << ret << endl;
    return 0;
}