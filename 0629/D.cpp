#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

class Record {
public:
    int day;
    string name;
    int delta;
    Record(int _day, string _name, int _delta) {
        day = _day;
        name = _name;
        delta = _delta;
    }
};

bool compare(Record a, Record b) {
    if(a.day < b.day) return true;
    else return false;
}


vector<Record> records;
int cows[3] = { 7, 7, 7 }; // 0: Bessie, 1: Elsie, 2: Mildred 
int ret = 0;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int day,  delta;
        string name;
        cin >> day >> name >> delta;
        records.push_back(Record(day, name, delta));
    }
    sort(records.begin(), records.end(), compare);
    
    vector<int> max_cows;
    max_cows.push_back(0);
    max_cows.push_back(1);
    max_cows.push_back(2);
    for(int i = 0; i < N; i++) {
        if(records[i].name == "Bessie") {
            cows[0] += records[i].delta;
        } else if(records[i].name == "Elsie") {
            cows[1] += records[i].delta;
        } else if(records[i].name == "Mildred") {
            cows[2] += records[i].delta;
        }
        int* max = max_element(cows, cows + 3);
        vector<int> new_max;
        for(int j = 0; j < 3; j++) {
            if(cows[j] == *max) {
                new_max.push_back(j);
            }
        }
        // cout << new_max.size()<< endl;
        if(max_cows != new_max) {
            ret++;
            max_cows = new_max;
        }
    }
    cout << ret << endl;
    return 0;
}