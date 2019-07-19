#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prize;
int sum = 0;

bool compare(int a, int b) {
    if(a > b) return true;
    else return false;
}
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int prod;
        cin >> prod;
        prize.push_back(prod);
    }
    sort(prize.begin(),  prize.end(), compare);
    for(int i = 0; i < 3 * (N / 3); i++) {
        if(i % 3 == 2) continue;
        else {
           sum += prize[i]; 
        }
    }
    for(int i = 3 * (N / 3); i < N; i++) {
        sum += prize[i];
    }
    cout << sum << endl;

    return 0;
}