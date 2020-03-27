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

int INF;
int cost[MAX_V][MAX_V];//cost[u][v]は辺e=(u,v)のコスト(存在しない場合はINF)
int d[MAX_V];//頂点sからの最短距離
bool used[MAX_V];//すでに使われたかのフラグ
int V;//頂点数

//始点sから各頂点への最短距離を求める
void dijkstra1(int s){//計算量O(|V^2|)
    fill(d, d+V, INF);
    fill(used, used+V, false);
    d[s]=0;

    while(true){
        int v=-1;
        //まだ使われていない頂点のうち距離が最小のものを探す
        for(int u=0; u<V; u++){
            if(!used[u] && (v==-1 || d[u]<d[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        for(int u=0; u<V; u++){
            d[u]=min(d[u], d[v]+cost[v][u]);
        }
    }
}

struct edge{int to, cost;};
typedef pair<int, int> P;//firstは最短距離、secondは頂点の番号
vector<edge> G[MAX_V];

void dijkstra2(int s){//計算量O(|E|log|V|)
    priority_queue<P, vector<P>, greater<P> > que;//greaterを指定するとfirstが小さい順に取り出せる
    fill(d, d+V, INF);
    d[s]=0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}