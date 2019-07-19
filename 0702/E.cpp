#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

vector<int> chickens;
vector< pair<int, int> > cows;

stack<int> c_order;
stack< pair<int, int> > n_order;

int ret = 0;

bool compare_n(pair<int, int> _a, pair<int, int> _b) {
    if(_a.first > _b.first) {
        return true;
    } else return false;
}

bool compare_c(int _a, int _b) {
    if(_a > _b) {
        return true;
    } else return false;
}

int main() {
    int C, N;
    cin >> C >> N;
    for(int i = 0; i < C; i++) {
        int _c;
        cin >> _c;
        chickens.push_back(_c);
    }
    for(int i = 0; i < N; i++) {
        int a_n, b_n;
        cin >> a_n >> b_n;
        cows.push_back(make_pair(a_n, b_n));
    }
    sort(chickens.begin(), chickens.end(), compare_c);
    sort(cows.begin(), cows.end(), compare_n);

    for(int i = 0; i < chickens.size(); i++) {
        c_order.push(chickens[i]);
    }
    for(int i = 0; i < cows.size(); i++) {
        n_order.push(cows[i]);
    }

    while(!n_order.empty()) {
        if(c_order.empty()) break;
        else {
            if(c_order.top() >= n_order.top().first && c_order.top() <= n_order.top().second) {
                ret++;
                c_order.pop();
                n_order.pop();
            } else if(c_order.top() < n_order.top().first) {
                c_order.pop();
            } else if(c_order.top() > n_order.top().second) {
                n_order.pop();
            }
        }
    }
    cout << ret << endl;
    return 0;
}