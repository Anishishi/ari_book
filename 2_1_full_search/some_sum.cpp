#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

bool plus_some(int depth, int n, int k, vector<int> vt)
{
    if(depth==n){
        return k==0;
    }
    if(plus_some(depth+1, n, k-vt[depth], vt)){
        return true;
    }
    if(plus_some(depth+1, n, k, vt)){
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vt(n), flag(n);
    for(int i=0; i<n; i++){
        cin >> vt[i];
    }
    int k;
    cin >> k;
    if(plus_some(0, n, k, vt)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}