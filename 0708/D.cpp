#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> connected[501];
int result[500][501] = { 0 };

int bfs(int _city) {
    queue<int> q;
    int dist[501] = { 0 };
    bool visited[501] = { 0 };
    dist[_city] = 0;
    if(_city == 1) {
        return 0;
    }
    else {
        visited[_city] = true;
        q.push(_city);
        while(!q.empty()) {
            for(int i = 0; i < connected[q.front()].size(); i++) {
                if(!visited[connected[q.front()][i]]) {
                    if(connected[q.front()][i] == 1) {
                        dist[1] = dist[q.front()] + 1;
                        return dist[1];
                    }
                    q.push(connected[q.front()][i]);
                    visited[connected[q.front()][i]] = true;
                    dist[connected[q.front()][i]] = dist[q.front()] + 1;
                }
                else continue;
            }
            q.pop();
        }
    }
    if(dist[1] == 0) {
        return -1;
    } else {
        return dist[1];
    }
}

int main() {
    int city, road, plan;
    cin >> city >> road;
    for(int i = 0; i < road; i++) {
        int a_city, b_city;
        cin >> a_city >> b_city;
        connected[a_city].push_back(b_city);
        connected[b_city].push_back(a_city);
    }
    cin >> plan;
    for(int i = 0; i < plan; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            connected[b].push_back(c);
            connected[c].push_back(b);
        } else if(a == 2) {
            connected[b].erase(find(connected[b].begin(), connected[b].end(), c));
            connected[c].erase(find(connected[c].begin(), connected[c].end(), b));
        }
        for(int j = 1; j <= city; j++) {
            result[i][j] = bfs(j);
        }
    }

    for(int i = 0; i < plan; i++) {
        for(int j = 1; j <= city; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}