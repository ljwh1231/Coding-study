#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string in;
    bool p[14] = {0}, k[14] = {0}, h[14] = {0}, t[14] = {0};
    int miss_p = 0, miss_k = 0, miss_h = 0, miss_t = 0;
    cin >> in;
    for(int i = 0; i < in.size() / 3; i++) {
        int idx = ((int)in[i * 3 + 1] - 48) * 10 + (int)in[i * 3 + 2] - 48;
        if(in[i * 3] == 'P') {
            if(p[idx] == true) {
                cout << "GRESKA" << endl;
                return 0;
            }
            p[idx] = true;
        } else if(in[i * 3] == 'K') {
            if(k[idx] == true) {
                cout << "GRESKA" << endl;
                return 0;
            }
            k[idx] = true;
        } else if(in[i * 3] == 'H') {
            if(h[idx] == true) {
                cout << "GRESKA" << endl;
                return 0;
            }
            h[idx] = true;
        } else if(in[i * 3] == 'T') {
            if(t[idx] == true) {
                cout << "GRESKA" << endl;
                return 0;
            }
            t[idx] = true;
        }
    }
    miss_p = count(p, p + 14, false) - 1;
    miss_k = count(k, k + 14, false) - 1;
    miss_h = count(h, h + 14, false) - 1;
    miss_t = count(t, t + 14, false) - 1;
    cout << miss_p << " " << miss_k << " " << miss_h << " " << miss_t << endl;
    return 0;
}