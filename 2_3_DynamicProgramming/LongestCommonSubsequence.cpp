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
    int n,m;
    cin >> n >> m;
    char s[n+1], t[m+1];
    cin >> s >> t;
    int dp[n+1][m+1];//dp[i][j]：sのi文字目までとtのj文字目までにおける共通部分文字列の長さの最大値
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n+1; i++){
        for(int j=1; j<=m+1; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    
    return 0;
}