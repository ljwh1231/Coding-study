#include <iostream>

using namespace std;

int main() {
    int ret = 0;
    int N, K, B;
    int *no_lights, *subtotal;
    int *lights;

    cin >> N >> K >> B;

    lights = new int[N];
    no_lights = new int[B];
    subtotal = new int[N - K + 1];

    for(int i = 0; i < N; i++) {
        lights[i] = 1;
    }

    for(int i = 0; i < B; i++) {
        cin >> no_lights[i];
        lights[no_lights[i] - 1] = 0;
    }

    for(int i = 0; i < N - K + 1; i++) {
        for(int j = i; j < K + i; j++) {
            subtotal[i] += lights[j];
        }
        ret = max(ret, subtotal[i]);
    }

    cout << K - ret << endl;

    return 0;

}