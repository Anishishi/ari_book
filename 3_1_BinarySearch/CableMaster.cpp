#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;
typedef long long ll;

double solve(vector<double>& a, ll n, ll k){//二分探索
    double l=0.1, r=1000000.0;
    for(int i=0; i<100; i++){//十分調べられる10^30の精度まで調べられる。
        double mid=(l+r)/2.0;
        ll tmp=0;
        for(int j=0; j<n; j++){
            tmp+=(ll)a[j]/mid;
        }
        if(tmp>=k) l=mid;
        else r=mid;
    }

    return l;
}

int main(){
    int N,K;
    cin >> N >> K;
    vector<double> L(N);
    for(int i=0; i<N; i++){
        cin >> L[i];
    }

    sort(L.begin(), L.end());
    cout << fixed << setprecision(2) << solve(L, N, K) << endl;

    return 0;
}