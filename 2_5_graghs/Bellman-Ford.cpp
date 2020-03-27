#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int INF=10000000, MAX_E=1000, MAX_V=100;//きちんと数字を定義する
struct edge{int from, to, cost;};//頂点fromから頂点toへのコスト
edge es[MAX_E];
int d[MAX_V];//最短距離
int V, E;//V:頂点数,E:辺数

void shortest_path(int s)//s番目の頂点から各頂点への最短距離を求める
{
    for(int i=0; i<V; i++) d[i] = INF;
    d[s]=0;
    while(true){
        bool update = false;
        for(int i=0; i<E; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }
}

//負の閉路の有無を調べる
bool find_negative_loop()
{
    memset(d, 0, sizeof(d));
    for(int i=0; i<V; i++){
        for(int j=0; j<E; j++){
            edge e = es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                if(i==V-1)return true;//n回目にも更新があるなら負の閉路が存在する。
            }
        }
    }
    return false;
}