#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct edge{int u, v, cost;};
typedef pair<int,int> P;

int main(){
    int N,R;
    cin >> N >> R;
    vector<edge> G[N];

    int dist1[N],dist[N];

    priority_queue<P, vector<P>, greater<P> > que;
}