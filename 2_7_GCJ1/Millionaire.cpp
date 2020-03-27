#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;
typedef long long ll;

int main(){
    int M,X;
    double P;
    cin >> M >> P >> X;

    double dp[2][(1<<M)+1];//dp[i][j]:
    
    int n=1<<M;
    double *prv = dp[0], *nxt = dp[1];
    memset(prv, 0, sizeof(double)*(n+1));
    prv[n]=1.0;

    for(int r=0; r<M; r++){//rラウンド
        for(int i=0; i<=n; i++){//分岐の数
            int jub=min(i,n-i);
            double t=0.0;
            for(int j=0; j<=jub; j++){//いくら上がる可能性がある賭けをするか
                t=max(t, P*prv[i+j]+(1-P)*prv[i-j]);//その時賭けが成功した場合と失敗した場合の和をとる
            }
            nxt[i]=t;
        }
        swap(prv, nxt);
    }

    int i=(ll)X*n/1000000;
    cout << fixed << setprecision(6) << prv[i] << endl;
    return 0;
}