#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <queue>
#include <utility>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <string>
#include <map>


using namespace std;


int t[500][500];
bool f[500][500];
int n, m;

int xadd[4] = {1, 0, -1, 0};
int yadd[4] = {0, 1, 0, -1};

int dfs(int i, int j, int c){
    if(c==0){
        return t[i][j];
    } else{
        int ret = 0;


        for(int k=0;k<4;k++){
            int nx = i, ny = j;

            nx += xadd[k];
            ny += yadd[k];

            if(nx>=0 && nx<=n-1 && ny>=0 && ny<=m-1 && !f[nx][ny]){
                f[i][j] = true;
                ret = max(ret, dfs(nx, ny, c-1));
                f[i][j] = false;
            }
        }


        return ret + t[i][j];
    }

}


int main(){

    scanf("%d %d", &n, &m);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &t[i][j]);
            f[i][j] = false;
        }
    }

    
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans, dfs(i, j, 3));
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int val = 0;
                if(k==0){
                    if((i+1)<n && (i-1)>=0 && (j-1)>=0){
                        val += t[i][j] + t[i+1][j] + t[i-1][j] + t[i][j-1];
                        ans = max(ans, val);
                    }
                } else if(k==1){
                    if((i+1)<n && (i-1)>=0 && (j+1)<n){
                        val += t[i][j] + t[i+1][j] + t[i-1][j] + t[i][j+1];
                        ans = max(ans, val);
                    }
                } else if(k==2){
                     if((i+1)<n && (j+1)<n && (j-1)>=0){
                        val += t[i][j] + t[i+1][j] + t[i][j+1] + t[i][j-1];
                        ans = max(ans, val);
                    }
                } else if(k==3){
                    if((i-1)>=0 && (j+1)<n && (j-1)>=0){
                        val += t[i][j] + t[i-1][j] + t[i][j+1] + t[i][j-1];
                        ans = max(ans, val);
                    }
                }

            }
        }
    }



    cout<<ans<<endl;



    return 0;
}