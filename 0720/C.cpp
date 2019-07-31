#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> characters[100];
vector<int> max_count[100];
int main() {
    int N;
    vector<string> check;
    vector< pair<string, int> > count;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string animal;
        int num;
        cin >> animal;
        cin >> num;
        for(int j = 0; j < num; j++) {
            string str;
            cin >> str;
            if(find(check.begin(), check.end(), str) != check.end()) {
                count[distance(check.begin(), find(check.begin(), check.end(), str))].second++;
            } else {
                check.push_back(str);
                count.push_back(make_pair(str, 1));
            }
            characters[i].push_back(str);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < characters[i].size(); j++) {
            max_count[i].push_back(count[distance(check.begin(), find(check.begin(), check.end(), characters[i][j]))].second);
        }
    }

    int ret[N];
    for(int i = 0; i < N; i++) {
        vector<int> temp;
        temp = max_count[i];
        for(int j = 0; j < characters[i].size(); j++) {
            if(max_count[i][j] == 1) {
                temp.erase(find(temp.begin(), temp.end(), max_count[i][j]));
            }
        }
        ret[i] = temp.size() + 1;
    }
    cout << *max_element(ret, ret + N) << endl;
    return 0;
    
}