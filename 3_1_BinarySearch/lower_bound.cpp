#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

ll solve(vector<ll>& a, ll n, ll k){//二分探索
    int l=-1, r=n;
    while(r-l>1){
        int mid=(l+r)/2;
        if(a[mid]>=k)r=mid;
        else l=mid; 
    }
    return r;
}

int main(){
    ll n, k;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> k;

    cout << solve(a, n, k) << endl;
    return 0;
}