#include <iostream>
#include <vector>

using namespace std;

vector< vector<char> > board;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, X;
    cin >> N >> M >> X;

    for(int i = 0; i < N; i++) {
        vector<char> temp;
        for(int j = 0; j < M; j++) {
            temp.push_back('.');
        }
        board.push_back(temp);
    }
    for(int i = 0; i < M; i++) {
        board[N - X][i] = '-';
    }
    for(int i = 0; i < M; i++) {
        int h;
        cin >> h;
        for(int j = N - h; j < N; j++) {
            if(board[j][i] == '-') {
                board[j][i] = '*';
                continue;
            }
            board[j][i] = '#';
        }
        if(i % 3 == 2) {
            for(int j = N - X + 1; j < N - h; j++) {
                board[j][i] = '|';
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;

}