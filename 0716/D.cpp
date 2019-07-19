#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> cows;
int main() {
    int N, M, C;
    cin >> N >> M >> C;

    for(int i = 0; i < N; i++) {
        int cow;
        cin >> cow;
        cows.push_back(cow);
    }
    sort(cows.begin(), cows.end());
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < C; j++) {
            
        }
    }
}