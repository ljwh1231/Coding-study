#include <iostream>
#include <utility>

using namespace std;

pair<int, bool>** board;
pair< pair<int, int>, int> robot;
int clean_num = 0;

int main() {
    int N, M;
    int r, c, dir;
    cin >> N >> M >> r >> c >> dir;
    robot = make_pair(make_pair(r, c), dir);
    board = new pair<int, bool>*[N];
    for(int i = 0; i < N; i++) {
        board[i] = new pair<int, bool>[M];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int state;
            cin >> state;
            board[i][j] = make_pair(state, state);
        }
    }
    clean_num++;
    while(true) {
        // clean
        board[robot.first.first][robot.first.second].second = true;
        // 2-c, 2-d
        if(board[robot.first.first - 1][robot.first.second].second == 1 
            && board[robot.first.first][robot.first.second + 1].second == 1
            && board[robot.first.first + 1][robot.first.second].second == 1
            && board[robot.first.first][robot.first.second - 1].second == 1) {
            if(robot.second == 0) {
                if(board[robot.first.first + 1][robot.first.second].first == 0) {
                    robot.first.first++;
                    continue;
                } else {
                    break;
                }
            } else if(robot.second == 1) {
                if(board[robot.first.first][robot.first.second - 1].first == 0) {
                    robot.first.second--;
                    continue;
                } else {
                    break;
                }
            } else if(robot.second == 2) {
                if(board[robot.first.first - 1][robot.first.second].first == 0) {
                    robot.first.first--;
                    continue;
                } else {
                    break;
                }
            } else if(robot.second == 3) {
                if(board[robot.first.first][robot.first.second + 1].first == 0) {
                    robot.first.second++;
                    continue;
                } else {
                    break;
                }
            }
        }
        // 2-a, 2-b
        if(robot.second == 0) {
            if(board[robot.first.first][robot.first.second - 1].second == 0) {
                robot.second = 3;
                robot.first.second--;
                clean_num++;
                continue;
            } else {
                robot.second = 3;
                continue;
            } 
        } else if(robot.second == 1) {
            if(board[robot.first.first - 1][robot.first.second].second == 0) {
                robot.second = 0;
                robot.first.first--;
                clean_num++;
                continue;
            } else {
                robot.second = 0;
                continue;
            }
        } else if(robot.second == 2) {
            if(board[robot.first.first][robot.first.second + 1].second == 0) {
                robot.second = 1;
                robot.first.second++;
                clean_num++;
                continue;
            } else {
                robot.second = 1;
                continue;
            }
        } else if(robot.second == 3) {
            if(board[robot.first.first + 1][robot.first.second].second == 0) {
                robot.second = 2;
                robot.first.first++;
                clean_num++;
                continue;
            } else {
                robot.second = 2;
                continue;
            }
        }
    }
    cout << clean_num << endl;
    return 0;   
}