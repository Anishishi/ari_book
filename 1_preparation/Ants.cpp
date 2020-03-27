#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int L, n;
    cin >> L >> n;
    vector<int> vt(n);
    for(int i=0; i<n; i++){
        cin >> vt[i];
    }
    int M,m;
    M=0;
    m=0;
    for(int i=0; i<n; i++){
        if(vt[i]*2<=L){
            m=max(vt[i],m);
            M=max((L-vt[i]),M);
        }else{
            m=max((L-vt[i]),m);
            M=max(vt[i],M);
        }
    }
    cout << "(max, min)=(" << M << ',' << m << ")\n";

    return 0;
}