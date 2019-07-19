#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_val[100001];
int sum[100001];
int q[100001];

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> q[i];
    }
    
    reverse(q, q + N);
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            sum[i] = q[i];
            min_val[i] = q[i];
        } else {
            sum[i] = sum[i - 1] + q[i];
            min_val[i] = min(min_val[i - 1], q[i]);
        }
    }

    vector<int> max_k;
    double max_avg = 0;
    for(int i = N - 2; i >= 1; i--) {
        double new_avg = ((double)sum[i] - (double)min_val[i]) / (double)(i);
        if(i == N - 2) {
            max_k.push_back(N - i - 1);
            max_avg = new_avg;
            continue;
        }
        if(new_avg == max_avg) {
            max_k.push_back(N - i - 1);
            max_avg = new_avg;
            continue;
        }
        if(new_avg > max_avg) {
            max_k.erase(max_k.begin(), max_k.end());
            max_k.push_back(N - i - 1);
            max_avg = new_avg;
        } else {
            continue;
        }
    }
    sort(max_k.begin(), max_k.end());
    for(int i = 0; i < max_k.size(); i++) {
        cout << max_k[i] << endl;
    }
    return 0;
}