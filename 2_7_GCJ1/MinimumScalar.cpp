#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> v1(n), v2(n);
    for(int i=0; i<n; i++){
        cin >> v1[i];
    }
    for(int i=0; i<n; i++){
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<ll>());
    ll ans=0;
    for(int i=0; i<n; i++){
        ans+=v1[i]*v2[i];
    }

    cout << ans << endl;
    
    return 0;
}