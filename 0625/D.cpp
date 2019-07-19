#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > board;

void flip_board(int row, int col) {
    for(int m = 0; m <= row; m++) {
        for(int n = 0; n <= col; n++) {
            if(board[m][n] == 0) board[m][n] = 1;
            else if(board[m][n] == 1) board[m][n] = 0;
        }
    }
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> row;
        string cow;
        cin >> cow;
        for(int iter = 0; iter < N; iter++) {
            row.push_back((int)cow[iter] - 48);
        }
        board.push_back(row);
    }
    int result = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if(board[i][j] == 1) {
                flip_board(i, j);
                result++;
            }
        }
    }   
    cout << result << endl;
    return 0;
}