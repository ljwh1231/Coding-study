#include <bits/stdc++.h>

using namespace std;

int N;
vector< vector<int> > board;
int ret = 0;

void move(vector< vector<int> > _board, int cnt) {
    if(cnt == 0) return;
    for(int i = 0; i < 4; i++) {
        vector< vector<int> > temp = _board;
        stack<int> add;
        stack<bool> visited;
        if(i == 0) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    if(temp[k][j] == 0) {
                        continue;
                    }
                    if(add.empty()) {
                        add.push(temp[k][j]);
                        visited.push(false);
                        continue;
                    }
                    if(add.top() == temp[k][j]) {
                        if(visited.top() == false) {
                            add.pop();
                            add.push(temp[k][j] * 2);
                            visited.pop();
                            visited.push(true);
                        } else {
                            add.push(temp[k][j]);
                            visited.push(false);
                        }
                    } else {
                        add.push(temp[k][j]);
                        visited.push(false);
                    }
                }
                for(int k = N - 1; k >= (int)add.size(); k--) {
                    temp[k][j] = 0;
                }
                for(int k = (int)add.size() - 1; k >= 0; k--) {
                    temp[k][j] = add.top();
                    add.pop();
                }
            }
        } else if(i == 1) {
            for(int j = 0; j < N; j++) {
                for(int k = N - 1; k >= 0; k--) {
                    if(temp[j][k] == 0) {
                        continue;
                    }
                    if(add.empty()) {
                        add.push(temp[j][k]);
                        visited.push(false);
                        continue;
                    }
                    if(add.top() == temp[j][k]) {
                        if(visited.top() == false) {
                            add.pop();
                            add.push(temp[j][k] * 2);
                            visited.pop();
                            visited.push(true);
                        } else {
                            add.push(temp[j][k]);
                            visited.push(false);
                        }
                    } else {
                        add.push(temp[j][k]);
                        visited.push(false);
                    }
                }
                for(int k = 0; k < N - (int)add.size(); k++) {
                    temp[j][k] = 0;
                }
                for(int k = N - (int)add.size(); k < N; k++) {
                    temp[j][k] = add.top();
                    add.pop();
                }
            }
        } else if(i == 2) {
            for(int j = 0; j < N; j++) {
                for(int k = N - 1; k >= 0; k--) {
                    if(temp[k][j] == 0) {
                        continue;
                    }
                    if(add.empty()) {
                        add.push(temp[k][j]);
                        visited.push(false);
                        continue;
                    }
                    if(add.top() == temp[k][j]) {
                        if(visited.top() == false) {
                            add.pop();
                            add.push(temp[k][j] * 2);
                            visited.pop();
                            visited.push(true);
                        } else {
                            add.push(temp[k][j]);
                            visited.push(false);
                        }
                    } else {
                        add.push(temp[k][j]);
                        visited.push(false);
                    }
                }
                for(int k = 0; k < N - (int)add.size(); k++) {
                    temp[k][j] = 0;
                }
                for(int k = N - (int)add.size(); k < N; k++) {
                    temp[k][j] = add.top();
                    add.pop();
                }
            }
        } else if(i == 3) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    if(temp[j][k] == 0) {
                        continue;
                    }
                    if(add.empty()) {
                        add.push(temp[j][k]);
                        visited.push(false);
                        continue;
                    }
                    if(add.top() == temp[j][k]) {
                        if(visited.top() == false) {
                            add.pop();
                            add.push(temp[j][k] * 2);
                            visited.pop();
                            visited.push(true);
                        } else {
                            add.push(temp[j][k]);
                            visited.push(false);
                        }
                    } else {
                        add.push(temp[j][k]);
                        visited.push(false);
                    }
                }
                for(int k = N - 1; k >= (int)add.size(); k--) {
                    temp[j][k] = 0;
                }
                for(int k = (int)add.size() - 1; k >= 0; k--) {
                    temp[j][k] = add.top();
                    add.pop();
                }
            }
        }
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                ret = max(ret, temp[j][k]);
            }
        }
        move(temp, cnt - 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        vector<int> row;
        for(int j = 1; j <= N; j++) {
            int tile;
            cin >> tile;
            row.push_back(tile);
        }
        board.push_back(row);
    }

    move(board, 5);

    cout << ret << endl;
    return 0;
}