#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, N;
    int x, y, r;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        vector< vector< pair< pair<int, int>, int> > > groups;
        for(int j = 0; j < N; j++) {
            cin >> x >> y >> r;
            if(j == 0) {
                vector< pair< pair<int, int>, int> > group;
                group.push_back(make_pair(make_pair(x, y), r));
                groups.push_back(group);
                continue;
            }
            int cnt = 0;
            for(int k = 0; k < groups.size(); k++) {
                for(int l = 0; l < groups[k].size(); l++) {
                    int group_x = groups[k][l].first.first, group_y = groups[k][l].first.second;
                    int group_r = groups[k][l].second;
                    if((group_r + r) * (group_r + r) >= (group_x - x) * (group_x - x) + (group_y - y) * (group_y - y)) {
                        groups[k].push_back(make_pair(make_pair(x, y), r));
                        break;
                    } else {
                        vector< pair< pair<int, int>, int> > group;
                        group.push_back(make_pair(make_pair(x, y), r));
                        groups.push_back(group);
                    }
                }
            }
        }
    }
}