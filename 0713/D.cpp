#include <iostream>

using namespace std;

int main() {
    int T, N;
    int *result;
    cin >> T;
    result = new int[T];
    for(int i = 0; i < T; i++) {
        int sum = 0;
        result[i] = 0;
        cin >> N;
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;
            sum += num;
            if(j == 0) {
                result[i] = sum;
            } else {
                result[i] = max(result[i], sum);
            }
            if(sum < 0) {
                sum = 0;
            }

        }
    }
    for(int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
}