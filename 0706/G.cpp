#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comapre(long long a, long long b) {
    if(a > b) return true;
    else return false;
}

int main() {
    vector<long long> histo;
    vector<long long> removed;
    long long sum = 0;
    long long N, X;
    cin >> N >> X;
    long long max_histo = ((N - 1) * (N - 2)) / 2;

    if(X > max_histo) {
        cout << "-1" << endl;
        return 0;
    }

    histo.push_back(N);
    for(long long i = N - 2; i >= 1; i--) {
        if(i <= max_histo - X - sum ) {
            sum += i;
            removed.push_back(N - 1 - i);
        } else {
            histo.push_back(N - 1 - i);
        }
    }
    sort(removed.begin(), removed.end(), comapre);
    histo.push_back(N - 1);
    for(int i = 0; i < removed.size(); i++) {
        histo.push_back(removed[i]);
    }

    for(long long i = 0; i < N; i++) {
        cout << histo[i] << " ";
    }
    cout << endl;

    return 0;
}