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
    int dp[n];//dp[i]:iが増加部分列の最後となるようなものの長さ
    dp[0]=1;
    int ans=1;
    for(int i=1; i<n; i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(a[j]<a[i]){
                dp[i]=max(dp[i], dp[j]+1);
            }else{
                dp[i]=max(dp[i], dp[j]);
            }
        }
        ans=max(dp[i], ans);
    }
    cout << ans << endl;

    return 0;
}