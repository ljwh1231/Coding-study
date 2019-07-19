#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long mod_num = 1000000007;
long long sum = 0;

vector<int> keys;

int main() {
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int key;
        cin >> key;
        keys.push_back(key);
    }
    vector<int> idx;
    for(int i = 0; i < K; i++) idx.push_back(1);
    for(int i = 0; i < N - K; i++) idx.push_back(0);
    sort(idx.begin(), idx.end());
    do {
        int max_key = 0;
        for(int i = 0; i < N; i++) {
            if(idx[i] == 1) {
                max_key = max(max_key, keys[i]);
            }
        }
        sum += max_key;
    } while(next_permutation(idx.begin(), idx.end()));

    if(sum < mod_num) {
        cout << sum << endl;
        return 0;
    } else {
        
    }

    return 0;
}