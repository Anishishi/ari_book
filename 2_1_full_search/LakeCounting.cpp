#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

void count_lake(vector<vector <int> >& vt, int h, int w)
{
    vt[h][w]=0;
    for(int dx=-1; dx<2; dx++){
        for(int dy=-1; dy<2; dy++){
            int nx=w+dx, ny=h+dy;
            if(vt[ny][nx]==1){
                count_lake(vt, ny, nx);
            }
        }
    }
    return ;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector <int> > vt(n+2, vector<int> (m+2, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char tmp;
            cin >> tmp;
            if(tmp=='W'){
                vt[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(vt[i][j]==1){
                count_lake(vt, i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}