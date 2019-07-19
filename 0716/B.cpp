#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

int tt[1001];

int main() {
    for(int i = 0; i < 1001; i++) {
        tt[i] = 0;
    }
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        for(int j = s; j < t; j++) {
            tt[j] += b;
        }
    }
    int max_val = tt[0];
    for(int i = 1; i < 1001; i++) {
        max_val = max(tt[i], max_val);
    }
    cout << max_val << endl;

    return 0;
}