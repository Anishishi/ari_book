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

vector<int> gragh[1000];
vector<int> color(1000);

bool dfs(int v, int c)
{
    color[v] = c;
    for(int i=0; i<gragh[v].size(); i++){
        if(color[gragh[v][i]]==c) return false;
        if(color[gragh[v][i]]==0 && !dfs(gragh[v][i], -c)) return false;
    }
    return true;
}

int main()
{
    int n, e_num;
    cin >> n;
    cout << "隣接している辺の数を入力して、ペアを全て入力してください。" << endl;
    cin >> e_num;
    for(int i=0; i<e_num; i++){
        int s,t;
        cin >> s >> t;
        gragh[s].push_back(t);
    }
    string ans="Yes";
    for(int i=0; i<n; i++){
        if(color[i]==0){//頂点が塗られていない、つまりこれまでの塗り方とは独立している（連結でない）時
            if(!dfs(i, 1)){
                ans="No";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}