#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int *order;
    int *cows;
    int *shuffle;
    order = new int[N];
    cows = new int[N];
    shuffle = new int[N];
    for(int i = 0; i < N; i++)
        cin >> order[i];
    for(int i = 0; i < N; i++)
        cin >> cows[i];
    
    for(int i = 0; i < 3; i++) {
        for(int i = 0; i < N; i++) {
            shuffle[i] = cows[order[i] - 1];
        }
        for(int i = 0; i < N; i++) {
            cows[i] = shuffle[i];
        }
    }
    for(int i = 0; i < N; i++) {
        cout << shuffle[i] << endl;
    }
    
}