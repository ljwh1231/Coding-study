#include <iostream>

using namespace std;
int sum[1001] = { 0 };
int dp[1001];

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if(j == 0) sum[j] += num;
            else {
                sum[j] = sum[j - 1] + num; 
            }
        }
    }
}