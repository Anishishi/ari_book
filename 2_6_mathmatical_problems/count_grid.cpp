#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a==0) return b;
    else return gcd(b%a, a);
}

int main(){
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll X=abs(x1-x2), Y=abs(y1-y2);
    
    if(X==0) X=max((ll)1, Y);
    if(Y==0) Y=max(X,(ll)1);
    cout << gcd(X,Y)-1 << endl;
    
    return 0;
}