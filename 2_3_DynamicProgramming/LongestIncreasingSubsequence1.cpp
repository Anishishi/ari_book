#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n; 
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int dp[n];//dp[i]:長さがi+1の増加部分列の最終要素の最小値
    int INF=100000000;
    fill(dp, dp+n, INF);
    
    for(int i=0; i<n; i++){
        *lower_bound(dp, dp+n, a[i])=a[i];
    }
    cout << lower_bound(dp, dp+n, INF)-dp << endl;//lower_boundはINF以上の最小の値のイテレータを返す。upper_boundはINFより大きい…

    return 0;
}