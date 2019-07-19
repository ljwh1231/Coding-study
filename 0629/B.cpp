#include <iostream>

using namespace std;

int grid[2001][2001] = { 0 };
// main함수에 400만 사이즈의 변수를 선언하면 스택에 쌓이기 때문에 스택은 그만한 사이즈를 감당하기 어려움! -> 전역변수로 선언하거나 동적할당(동적할당은 heap에 쌓임)
int main() {
    int x1, y1, x2, y2;
    int total = 0;
    int covered = 0;
    for (int i = 0; i < 3; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(i != 2) {
            total += (x2 - x1) * (y2 - y1);
        }
        for(int j = x1; j < x2; j++) {
            for(int k = y1; k < y2; k++) {
                grid[j + 1000][k + 1000] += 1;
                if (grid[j + 1000][k + 1000] == 2) covered++;
            }
        }
    }
    cout << total - covered << endl;
    return 0;
}