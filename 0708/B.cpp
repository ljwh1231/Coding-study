#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector< vector<char> > board;
vector< vector< vector<char> > > result;


bool end_game(int x, int y, vector< vector<char> > _temp) {
    if(((_temp[0][0] == _temp[1][1]) && (_temp[1][1] == _temp[2][2]) && (_temp[1][1] == 'o' || _temp[1][1] == 'x')) 
        || ((_temp[0][2] == _temp[1][1]) && (_temp[1][1] == _temp[2][0]) && (_temp[1][1] == 'o' || _temp[1][1] == 'x'))) {
        return true;
    }
    if(((_temp[x][0] == _temp[x][1]) && (_temp[x][1] == _temp[x][2]) && (_temp[x][0] == 'o' || _temp[x][0] == 'x')) 
        || ((_temp[0][y] == _temp[1][y]) && (_temp[1][y] == _temp[2][y]) && (_temp[0][y] == 'o' || _temp[0][y] == 'x'))) {
        return true;
    }
    return false;
}

int main() {
    int T;
    char player;
    cin >> T;

    for(int i = 0; i < 3; i++) {
        vector<char> vec(3, '-');
        board.push_back(vec);
    }
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                cin >> board[j][k];
            }
        }
        cin >> player;
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                vector< vector<char> > temp = board;
                if(temp[j][k] == '-') {
                    temp[j][k] = player;
                    if(end_game(j, k, temp)) {
                        result.push_back(temp);
                    }
                }
            }
        }
    }

    for(int i = 0; i < T; i++) {
        cout << "Case " << i + 1 << ":" << endl;
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                cout << result[i][j][k];
            }
            cout << endl;
        }
    }
    return 0;
}