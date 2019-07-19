#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector< pair<int, int> > order;
int ret = 0;

bool compare(pair<int, int> _a, pair<int, int> _b) {
    if(_a.first < _b.first) return true;
    else return false;
}
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int arrive, cost;
        cin >> arrive >> cost;
        order.push_back(make_pair(arrive, cost));
    }
    sort(order.begin(), order.end(), compare);

    for(int i = 0; i < N; i++) {
        if(i == 0) ret = order[i].first + order[i].second;
        else {
            if(ret < order[i].first) {
                ret = order[i].first + order[i].second;
            } else {
                ret += order[i].second;
            }
        }
    }
    cout << ret << endl;
    return 0;

}