#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
typedef long long ll;

ll solve(vector<ll>& X, int M, int N){
    ll ld=0, rd=1000000001;
    while(rd-ld>1){
        ll mid=(rd+ld)/2;
        int cnt=1, prv=X[0];
        for(int i=1; i<N; i++){
            if(prv+mid<=X[i]){
                cnt++;
                prv=X[i];
            }
        }
        if(cnt>=M) ld=mid;
        else rd=mid;
    }
    return ld;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> X(N);
    for(int i=0; i<N; i++){
        cin >> X[i];
    }
    sort(X.begin(), X.end());

    cout << solve(X,M,N) << endl;

    return 0;
}