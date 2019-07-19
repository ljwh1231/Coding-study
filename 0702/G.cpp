#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, K, R;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, -1, 0 };

bool board[100][100][4];
vector< pair<int, int> > cows;

int ret = 0;

void dfs(int _i, int _j) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 4; k++) {
        
            }
        }
    }
}

int main() {

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            for(int k = 0; k < 4; k++) {
                board[i][j][k] = 1;
            }
        }
    }

    cin >> N >> K >> R;
    for(int i = 0; i < R; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;        
        if(r2 - r1 == -1) {
            board[r1 - 1][c1 - 1][0] = 0;
            board[r2 - 1][c2 - 1][2] = 0;
        } else if(r2 - r1 == 1) {
            board[r1 - 1][c1 - 1][2] = 0;
            board[r2 - 1][c2 - 1][0] = 0;
        } else if(c2 - c1 == -1) {
            board[r1 - 1][c1 - 1][3] = 0;
            board[r2 - 1][c2 - 1][1] = 0;
        } else if(c2 - c1 == 1) {
            board[r1 - 1][c1 - 1][1] = 0;
            board[r2 - 1][c2 - 1][3] = 0;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 4; k++) {
                if(i + di[k] < 0 || i + di[k] >= N || j + dj[k] < 0 || j + dj[k] >= N) {
                    board[i][j][k] = 0;
                }
            }
        }
    }

    for(int i = 0; i < K; i++) {
        int x_pos, y_pos;
        cin >> x_pos >> y_pos;
        cows.push_back(make_pair(x_pos - 1, y_pos - 1));
    }

    for(int i = 0; i < K; i++) {
        dfs(cows[i].first, cows[i].second);        
    }

}