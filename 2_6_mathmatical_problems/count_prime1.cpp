#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll A,B;
    cin >> A >> B;
    bool is_prime[(ll)sqrt(B)+2], is_prime_ans[B-A];
    vector<ll> ans;
    memset(is_prime, 1, sizeof(is_prime));
    memset(is_prime_ans, 1, sizeof(is_prime_ans));
    is_prime[0]=is_prime[1]=false;
    for(ll i=2; i<=sqrt(B); i++){
        if(is_prime[i]){
            is_prime[i]=false;
            for(ll j=2*i; j<=sqrt(B); j+=i) is_prime[j]=false;
            ll tmp=A/i;
            if(A%i!=0) tmp++;
            for(ll j=tmp*i; j<B; j+=i) is_prime_ans[j-A]=false;
        }
    }
    for(int i=0; i<B-A; i++){
        if(is_prime_ans[i]){
            ans.push_back(i+A);
        }
    }
    cout << ans.size() << endl;
    return 0;
}