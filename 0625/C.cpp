#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    vector<int> hps;
    for(int i = 1; i <= 3; i++)
        hps.push_back(i);

    int T;
    cin >> T;

    pair<int, int> match;
    vector< pair<int, int> > matches;

    for(int i = 0; i < T; i++) {
        cin >> match.first >> match.second;
        matches.push_back(match);
    }
    vector<int> wins;
    int iter = 0;
    do {
        wins.push_back(0);
        for(int i = 0; i < 3; i++) {
            pair<int, int> candidate;
            if(i == 2)
                candidate = make_pair(hps[i], hps[i - 2]);
            else
                candidate = make_pair(hps[i], hps[i + 1]);
            if(find(matches.begin(), matches.end(), candidate) != matches.end()) {
                wins[iter] += count(matches.begin(), matches.end(), candidate);
            }
        }
        iter++;
    } while (next_permutation(hps.begin(), hps.end()));
    int most_win = *max_element(wins.begin(), wins.end());
    
    cout << most_win << endl;

    return 0;
}