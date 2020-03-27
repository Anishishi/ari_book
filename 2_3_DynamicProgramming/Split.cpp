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
    int n, m, M;
    cin >> n >> m >> M;
    int dp[m+1][n+1];//dp[i][j]:合計がjで、それがi個以下の数の和で表せる時の場合の数
    dp[0][0]=1;
    for(int j=1; j<=n; j++){
        dp[0][j]=0;
    }
    
    for(int i=1; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(j<i){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-i])%M;
            }
        }
    }
    cout << dp[m][n] << endl;

    return 0;
}