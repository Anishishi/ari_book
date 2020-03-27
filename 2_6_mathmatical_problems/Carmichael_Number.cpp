#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

bool is_prime(ll n){
    bool flag=true;
    for(ll i=2; i<=sqrt(n); i++){
        if(n%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}

int main(){
    ll N;
    cin >> N;
    vector<int> index_que;
    ll M=32768, cnt=15, n=N;
    ll mod=n;
    while(true){
        if(n==0) break;
        if(M<=n){
            index_que.push_back(cnt);
            n-=M;
        }
        M/=2;
        cnt--;
    }
    reverse(index_que.begin(), index_que.end());

    bool flag=true;
    if(is_prime(N)==true){
        cout << "This number is prime.\n";
        return 0;
    }

    for(int i=0; i<index_que.size(); i++){
        cout << index_que[i] << ' ';
    }
    cout << endl;

    for(int x=2; x<N; x++){
        vector<ll> times(16);
        times[0]=x;
        for(int i=1; i<16; i++){
            times[i]=times[i-1]*times[i-1]%mod;
        }
        ll tmp=1;
        for(int i=0; i<index_que.size(); i++){
            tmp=tmp*times[index_que[i]]%mod;
        }
        if(tmp!=x){
            flag=false;
            break;
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}