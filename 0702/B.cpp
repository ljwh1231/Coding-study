#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

bool search_cow(vector<int> _cows, int _cow) {
    int it = 0;
    if(_cows.size() == 0) return false;
    for(int i = 0; i < _cows.size(); i++) {
        if(_cows[i] == _cow) {
            return true;
        } else {
            it++;
            if(it == _cows.size()) return false;
            continue;
        }
    }
}

vector< pair<int, int> > obs;
vector<int> cows;
int ret = 0;
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int cow, pos;
        cin >> cow >> pos;
        if(!search_cow(cows, cow)) {
            cows.push_back(cow);
            obs.push_back(make_pair(cow, pos));
            // cout << cow << endl;
        } else {

            int idx = find(cows.begin(), cows.end(), cow) - cows.begin();
            if(obs[idx].second == pos) {
                continue;
            } else {
                obs[idx].second = pos;
                ret++;
            }
        }
    }
    cout << ret << endl;
}