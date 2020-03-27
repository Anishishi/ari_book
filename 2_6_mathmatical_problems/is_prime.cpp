#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    bool flag=true;
    for(int i=2; i*i<=N; i++){
        if(N%i==0) flag=false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
