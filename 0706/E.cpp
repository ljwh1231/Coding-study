#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string ret = "-1";

int main() {
    string word;
    cin >> word;
    int i;
    for(i = 1; i * i <= word.size(); i++) {
        if(word.size() % i != 0) {
            continue;
        } else {
            int count = 0;
            ret = word.substr(0, i);
            for(int j = 0; j < (word.size() / i) - 1; j++) {
                string temp[2];
                temp[0] = word.substr(i * j, i);
                temp[1] = word.substr(i * (j + 1), i);
                sort(temp[0].begin(), temp[0].end());
                sort(temp[1].begin(), temp[1].end());
                if(temp[0] != temp[1]) {
                    ret = "-1";
                    break;
                } else {
                    count++;
                }
            }
            if(count == (word.size() / i) - 1) {
                cout << ret << endl;
                return 0;
            }
        }
    }
    if(ret == "-1") {
        for(;i <= word.size(); i++) {
            if(word.size() % i != 0) {
                continue;
            } else {
                int count = 0;
                ret = word.substr(0, i);
                if(ret == word) {
                    ret = "-1";
                    break;
                }
                for(int j = 0; j < (word.size() / i) - 1; j++) {
                    string temp[2];
                    temp[0] = word.substr(i * j, i);
                    temp[1] = word.substr(i * (j + 1), i);
                    sort(temp[0].begin(), temp[0].end());
                    sort(temp[1].begin(), temp[1].end());
                    if(temp[0] != temp[1]) {
                        ret = "-1";
                        break;
                    } else {
                        count++;
                    }
                }
                if(count == (word.size() / i) - 1) {
                    cout << ret << endl;
                    return 0;
                }
            }
        }
    }
    cout << ret << endl;

    return 0;
}