#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

const int INF = 100000000;
typedef pair<int, int> P;

int main()
{
    char maze[100][101];//迷路を表す文字列の配列
    int N, M;
    int sx, sy;//sの座標
    int gx, gy;//gの座標
    int d[100][101];//各点までの最短距離の配列
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> maze[i];
    }

    int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

    //最短距離を求める
    queue<P> que;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(maze[i][j]=='S'){
                sx=i;
                sy=j;
            }else if(maze[i][j]=='G'){
                gx=i;
                gy=j;
            }
            d[i][j]=INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy]=0;
    while(que.size()>0){
        P p = que.front();
        que.pop();
        if(p.first == gx && p.second == gy){
            break;
        }

        for(int i=0; i<4; i++){
            int nx = p.first+dx[i], ny=p.second+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]!='#' && d[nx][ny]==INF){
                que.push(P(nx, ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
    cout << d[gx][gy] << endl;
    return 0;
}