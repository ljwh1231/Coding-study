#include <iostream>
#include <algorithm>

using namespace std;

int sum(int x) {
    return (x / 10000) + ((x % 10000) / 1000) + ((x % 1000) / 100) + ((x % 100) / 10) + (x % 10);
}

int main() {
    int L, D, X;
    cin >> L >> D >> X;
    int min_val = 10000, max_val = 1;
    for(int i = L; i <= D; i++) {
        if(sum(i) == X) {
            min_val = min(min_val, i);
            max_val = max(max_val, i);
        }
    }
    cout << min_val << endl << max_val << endl;

    return 0;
}