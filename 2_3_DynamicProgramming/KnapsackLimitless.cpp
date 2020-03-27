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
    int n, w_max;
    cin >> n;
    vector<vector < int > > tools(2, vector<int>(n));
    for(int i=0; i<n; i++){
        cin >> tools[0][i] >> tools[1][i];//一つ目が重さ、二つ目が価値
    }
    cin >> w_max;
    int dp[n+1][w_max+1];//dp[i][j]:i番目までの品物を使って、重さ制限がjの時の最大価値
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w_max+1; j++){
            if(j<tools[0][i-1]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-tools[0][i-1]]+tools[1][i-1]);
            }
        }
    }
    cout << dp[n][w_max] << endl;

    return 0;
}