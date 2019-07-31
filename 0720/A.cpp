#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int board[21][21];
    vector<int> comp;
    vector<int> player;
    
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++) { 
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        player.push_back(i);
    }

    vector<int> idx;
    for(int i = 0; i < N / 2; i++) {
        idx.push_back(1);
    }
    for(int i = N / 2; i < N; i++) {
        idx.push_back(0);
    }

    sort(idx.begin(), idx.end());

    do {
        vector<int> s;
        vector<int> l;
        int sum_s = 0;
        int sum_l = 0;
        for(int i = 0; i < N; i++) {
            if(idx[i] == 1) {
                s.push_back(player[i]);
            } else {
                l.push_back(player[i]);
            }
        }
        for(int i = 0; i < N / 2; i++) {
            for(int j = i; j < N / 2; j++) {
                sum_s = sum_s + board[s[i]][s[j]] + board[s[j]][s[i]];
                sum_l = sum_l + board[l[i]][l[j]] + board[l[j]][l[i]];
            }
        }
        int diff = ((sum_s - sum_l) > 0) ? (sum_s - sum_l) : (sum_l - sum_s);
        comp.push_back(diff);
    } while(next_permutation(idx.begin(), idx.end()));

    int min_diff = *min_element(comp.begin(), comp.end());
    cout << min_diff << endl;

    return 0;
}