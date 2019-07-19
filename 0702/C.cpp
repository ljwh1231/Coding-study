#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack<char> cow_seq;
vector<char> cow_list;

bool is_cow(vector<char> _cows, char cow) {
    int it = 0;
    if(_cows.size() == 0) return false;
    for(int i = 0; i < _cows.size(); i++) {
        if(_cows[i] == cow) {
            return true;
        } else {
            it++;
            if(it == _cows.size()) return false;
            else continue;
        }
    }
}
int ret = 0;
int main() {
    for(int i = 0; i < 52; i++) {
        char cow;
        cin >> cow;
        if(!is_cow(cow_list, cow)) {
            cow_seq.push(cow);
            cow_list.push_back(cow);
        } else {
            vector<char> backup;
            while(true) {
                if(cow_seq.top() == cow) {
                    cow_seq.pop();
                    break;
                } else {
                    backup.push_back(cow_seq.top());
                    cow_seq.pop();
                    ret++;
                }
            }
            for(int j = backup.size() - 1; j >= 0; j--) {
                cow_seq.push(backup[j]);
            }
        }
    }
    cout << ret << endl;
    return 0;    
}