#include <iostream>

using namespace std;

int main() {
    int T;
    int* result;
    cin >> T;
    result = new int[T];
    for(int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        int greater = max(a, b), smaller = min(a, b);
        while(true) {
            if(greater / 2 > smaller) {
                greater /= 2;
                continue;
            } else if(greater / 2 < smaller) {
                smaller /= 2;
                continue;
            } else if(greater / 2 == smaller) {
                result[i] = smaller;
                break;
            }
        }
    }
    for(int i = 0; i < T; i++) {
        cout << 10 * result[i] << endl;
    }
}