#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N;
    cin >> N;
    int h[1000001];
    int ret = 0;
    memset(h, 0, sizeof(h));
    for(int i = 0; i < N; i++) {
        int balloon;
        cin >> balloon;
        if(h[balloon + 1] != 0) {
            h[balloon + 1] -= 1;
        }
        h[balloon] += 1;
    }
    for(int i = 0; i < 1000001; i++) {
        ret += h[i];
    }
    cout << ret << endl;

    return 0;
}