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
    int n,k;
    cin >> n; 
    vector<int> a(n),m(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> m[i];
    }
    cin >> k;
    int dp[n][k+1];//dp[i][j]:i+1番目まででjを作る時余る最大のi+1番目の数の個数
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        dp[i][0]=m[i];
    }
    for(int j=1; j<k+1; j++){
        for(int i=0; i<n; i++){
            if(dp[i-1][j]>=0 && i!=0){
                dp[i][j]=m[i];
            }else if(a[i]>j || dp[i][j-a[i]]<=0){
                dp[i][j]=-1;
            }else{
                dp[i][j]=dp[i][j-a[i]]-1;
            }
        }
    }
    if(dp[n-1][k]>=0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}