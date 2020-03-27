#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N,L,P;
    cin >> N >> L >> P;
    vector <pair<int, int> > gs(N+1);
    for(int i=0; i<N; i++){
        cin >> gs[i].first;//gs[0]がガソリンスタンドの場所、gs[1]は補給できる量
    }
    for(int i=0; i<N; i++){
        cin >> gs[i].second;
    }
    gs[N]=make_pair(L, 0);
    sort(gs.begin(), gs.end());

    priority_queue<int> pque;
    
    int ans=0, pos=0, tank=P;
    for(int i=0; i<=N; i++){
        int d=gs[i].first-pos;
        while(d>tank){
            if(pque.empty()){
                ans=-1;
                break;
            }
            tank+=pque.top();
            pque.pop();
            ans++;
        }
        if(ans==-1){
            break;
        }
        tank-=d;
        pos+=d;
        pque.push(gs[i].second);
    }
    cout << ans << endl;

    return 0;
}