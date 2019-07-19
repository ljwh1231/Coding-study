#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<char> op;

int calc(vector<int> _temp, int _i) {
    if(op[_i] == '+') {
        return _temp[_i] + _temp[_i + 1];
    } else if(op[_i] == '-') {
        return _temp[_i] - _temp[_i + 1];
    } else if(op[_i] == '*') {
        return _temp[_i] * _temp[_i + 1];
    } else if(op[_i] == '/') {
        return _temp[_i] / _temp[_i + 1];
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int _num;
        cin >> _num;
        num.push_back(_num);
    }
    for(int i = 0; i < 4; i++) {
        int op_num;
        cin >> op_num;
        if(i == 0) {
            for(int j = 0; j < op_num; j++) {
                op.push_back('+');
            }
        } else if(i == 1) {
            for(int j = 0; j < op_num; j++) {
                op.push_back('-');
            }
        } else if(i == 2) {
            for(int j = 0; j < op_num; j++) {
                op.push_back('*');
            }
        } else if(i == 3) {
            for(int j = 0; j < op_num; j++) {
                op.push_back('/');
            }
        }
    }
    sort(op.begin(), op.end());
    int max_val, min_val;
    max_val = 0x80000000;
    min_val = 0x7fffffff;
    do {
        vector<int> temp = num;
        for(int i = 0; i < n - 1; i++) {
            temp[i + 1] = calc(temp, i);
        }
        max_val = max(temp[n - 1], max_val);
        min_val = min(temp[n - 1], min_val);
    } while(next_permutation(op.begin(), op.end()));

    cout << max_val << endl << min_val << endl;

    return 0;
}