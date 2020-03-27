#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    bool is_prime[N+1];
    int prime[N];//i番目の素数

    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    int cnt=0;
    for(int i=2; i<=N; i++){
        if(is_prime[i]){
            prime[cnt]=i;
            cnt++;
            for(int j=2*i; j<=N; j+=i) is_prime[j]=false;
        }
    }
    cout << "nums(under N+1)=" << cnt << endl;
    return 0;
}