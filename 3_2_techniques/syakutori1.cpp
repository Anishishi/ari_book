#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;

int main(){
    int N,S;
    cin >> N >> S;
    vector<int> a(N+1);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    a[N]=1000000000;
    int l=0,r=0, sum=a[0], ans=1000000;
    while(true){
        while(sum<S){
            r++;
            sum+=a[r];
        }
        if(r==N) break;
        ans=min(ans, r-l+1);
        sum-=a[l];
        l++;
    }
    cout << ans << endl;
    return 0;
}