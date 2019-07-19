#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

list< pair<int, int> > snake;
vector< pair<int, char> > actions;
bool board[101][101] = { 0 };

int N, K;
int head = 1;
int cur_x = 1, cur_y = 1;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

bool is_end() {
    int new_x = cur_x + di[head];
    int new_y = cur_y + dj[head];
    if(new_x < 1 || new_x > N || new_y < 1 || new_y > N) {
        return true;
    } else {
        if(find(snake.begin(), snake.end(), make_pair(new_x, new_y)) != snake.end()) {
            return true;
        }
        else return false;
    }
}

int main() {
    cin >> N >> K;

    for(int i = 0; i < K; i++) {
        int x_pos, y_pos;
        cin >> x_pos >> y_pos;
        board[x_pos][y_pos] = true;
    }

    int L;
    cin >> L;
    for(int i = 0; i < L; i++) {
        int sec;
        char dir;
        cin >> sec >> dir;
        actions.push_back(make_pair(sec, dir));
    }
    int ret = 0;
    snake.push_front(make_pair(1, 1));
    for(int i = 0; i < L; i++) {
        while(ret != actions[i].first) {
            if(is_end()) {
                ret++;
                cout << ret << endl;
                return 0;
            } else {
                
                if(board[cur_x + di[head]][cur_y + dj[head]] == true) {
                    snake.push_front(make_pair(cur_x+ di[head], cur_y + dj[head]));
                    board[cur_x + di[head]][cur_y + dj[head]] = false;
                } else {
                    snake.push_front(make_pair(cur_x + di[head], cur_y + dj[head]));
                    snake.pop_back();
                }
            }
            cur_x += di[head];
            cur_y += dj[head];
            ret++;
        }
        if(actions[i].second == 'D') {
            if(head == 3) head = 0;
            else head += 1;
        } else if(actions[i].second == 'L') {
            if(head == 0) head = 3;
            else head -= 1;
        }
    }
    while(!is_end()) {
        if(board[cur_x + di[head]][cur_y + dj[head]] == true) {
            snake.push_front(make_pair(cur_x + di[head], cur_y + dj[head]));
            board[cur_x + di[head]][cur_y + dj[head]] = false;
        } else {
            snake.push_front(make_pair(cur_x + di[head], cur_y + dj[head]));
            snake.pop_back();
        }
        cur_x += di[head];
        cur_y += dj[head];
        ret++;
    }
    ret++;

    cout << ret << endl;

    return 0;
}