#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cows;

int main() {
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int cow;
        cin >> cow;
        cows.push_back(cow);
    }
    sort(cows.begin(), cows.end());

    int g_num;
    int result = 0;
    if(N % K == 0) g_num = N / K;
    else g_num = N / K + 1;
    for(int i = N - 1; i >= N - g_num; i--) {
        if(i == N - g_num) {
            result += cows[i] * (N - K * (g_num - 1));
        } else {
            result += cows[i] * K;
        }
    }

    cout << result << endl;
    return 0;
}