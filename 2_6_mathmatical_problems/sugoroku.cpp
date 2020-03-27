#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd_exted(int a, int b, int nums){
    if(b==1) return nums;
    else if(b==0) return -1;
    else return gcd_exted(b, a%b, nums+a/b);
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << gcd_exted(n, k, 1) << endl;
    
    return 0;
}