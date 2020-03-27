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
    int n,m,M;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> M;
    int dp[m+1][n+1];//dp[i][j]はj番目の品物までを使って、i個の品物を選ぶ場合の数
    for(int j=0; j<=n; j++){
        dp[0][j]=1;
    }
    for(int i=1; i<=m; i++){
        dp[i][0]=0;
    }
    int sum=0;
    cout << "table:" << endl;
    for(int j=1; j<=n; j++){
        sum+=a[j-1];
        for(int i=1; i<=m; i++){
            if(i>sum){
                dp[i][j]=0;
            }else if(i-a[j-1]<=0){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
            }else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-a[j-1]-1][j-1])%M;
            }
            cout << dp[i][j];
        }
        cout << endl;
    }
    cout << "answer=" << dp[m][n] << endl;

    return 0;
}