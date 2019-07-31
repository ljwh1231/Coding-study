#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num[100];
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    int ret = 0;
    for(int i = N - 1; i > 0; i--) {
        if(num[i] < num[i - 1]) {
            ret = i;
            break;
        }
    }
    cout << ret << endl;

    return 0;
}