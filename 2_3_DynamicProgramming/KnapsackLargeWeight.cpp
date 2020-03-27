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
    int n, w_max, max_value=100;
    cin >> n;
    vector<vector < int > > tools(2, vector<int>(n));
    for(int i=0; i<n; i++){
        cin >> tools[0][i] >> tools[1][i];//一つ目が重さ、二つ目が価値
    }
    cin >> w_max;
    
    int dp[n+1][max_value*n+1];//dp[i][j]:i番目までの品物を使って、価値の総和=jの時の最小重量

    int INF = 1000000001;
    fill(dp[0], dp[0]+max_value*n+1, INF);
    dp[0][0]=0;
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<max_value*n+1; j++){
            if(tools[1][i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=min(dp[i-1][j], dp[i-1][j-tools[1][i-1]]+tools[0][i-1]);
            }
        }
    }
    int ans=0;
    for(int j=max_value*n; j>=0; j--){
        if(w_max>=dp[n][j] && dp[n][j]!=0){
            ans=j;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}