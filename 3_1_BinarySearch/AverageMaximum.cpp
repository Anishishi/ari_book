#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;

double solve(vector<int>& w, vector<int>& v, int K, int N){
    vector<double> y(N);

    double l=0.0, r=1000001.0;
    for(int i=0; i<100; i++){
        double mid=(l+r)/2.0, sum=0;

        for(int i=0; i<N; i++){
            y[i]=v[i]-w[i]*mid;
        }
        sort(y.begin(), y.end(), greater<double>());

        for(int i=0; i<K; i++){
            sum+=y[i];
        }
        if(sum>=0) l=mid;
        else r=mid;
    }

    return l;
}

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> w(N), v(N);
    for(int i=0; i<N; i++){
        cin >> w[i] >> v[i];
    }

    cout << fixed << setprecision(2) << solve(w, v, K, N) << endl;

    return 0;
}