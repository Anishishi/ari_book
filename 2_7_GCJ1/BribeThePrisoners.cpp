#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;
int inf=100000000;

int main(){
    int P,Q;
    cin >> P >> Q;
    vector<int> A(Q+2);
    A[0]=0, A[Q+1]=P+1;
    for(int i=1; i<=Q; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector< vector<int> > dp(Q+2, vector<int>(Q+2, 0));//dp[i][j]は区間(i,j)の囚人を解放するのに必要な硬貨の数

    for(int q=0; q<Q+1; q++){//初期化
        dp[q][q+1]=0;
    }
    for(int w=2; w<=Q+1; w++){//区間の幅が小さいものから順に考えていく
        for(int i=0; i+w<=Q+1; i++){
            int j=i+w, coins=inf;
            for(int k=i+1; k<j; k++){
                coins=min(coins, dp[i][k]+dp[k][j]+A[j]-A[i]-2);
            }
            dp[i][j]=coins;
        }
    }

    //デバック用
    /*for(int i=0; i<Q+2; i++){
        for(int j=i+1; j<Q+2; j++){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }*/
    
    cout << dp[0][Q+1] << endl;

    return 0;
}