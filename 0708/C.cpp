#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T, N;
    vector<int> result;
    cin >> T;
    vector<int> woods[T];
    for(int i = 0; i < T; i++) {
        cin >> N;
        int* order = new int[N];
        
        for(int j = 0; j < N; j++) {
            int wood;
            cin >> wood;
            woods[i].push_back(wood);
        }
        sort(woods[i].begin(), woods[i].end());
        // for(int j = 0; j < N; j++) {
        //     cout << woods[i][j] << endl;
        // }
        // cout << endl;
        order[0] = woods[i][0];
        if(N % 2 == 0) {
            for(int j = 1; j <= (N - 1) / 2; j++) {
                order[j] = woods[i][2 * j - 1];
                order[N - j] = woods[i][2 * j];
            }
            order[N / 2] = woods[i][N - 1];
        } else {
            for(int j = 1; j <= (N - 1) / 2; j++) {
                order[j] = woods[i][2 * j - 1];
                order[N - j] = woods[i][2 * j];
            }
        }
        int max_val = abs(order[1] - order[0]);
        for(int j = 1; j < N - 1; j++) {
            max_val = max(max_val, abs(order[j + 1] - order[j]));
        }
        max_val = max(max_val, abs(order[N - 1] - order[0]));
        result.push_back(max_val);
    }
    for(int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    return 0;
}