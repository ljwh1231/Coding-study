#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector < vector<char> > result[T];

    for(int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;
        for(int j = 0; j < n; j++) {
            vector<char> line;
            for(int k = 0; k < m; k++) {
                char meat;
                cin >> meat;
                line.push_back(meat);
            }
            result[i].push_back(line);
        }
        for(int j = 0; j < n; j++) {
            reverse(result[i][j].begin(), result[i][j].end());
        }
    }
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < result[i].size(); j++) {
            for(int k = 0; k < result[i][j].size(); k++) {
                cout << result[i][j][k];
            }
            cout << endl;
        }
    }
}