#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

const int MAX_N = 100000;
bool used[MAX_N];
int perm[MAX_N];
//{0,1,2,3,4,...,n-1}の並び替えn!通りを生成する
void permutation(int pos, int n)
{
    if(pos == n){
        for(int i=0; i<n; i++){
            cout << perm[i];
        }
        cout << ',';
        return;
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            perm[pos]=i;
            used[i]=true;
            permutation(pos+1, n);
            used[i]=false;
        }
    }
    return;
}

//重複があっても全ての順列を生成する
//next_permutationは辞書順で次の順列を生成する
int perm2[MAX_N];
void permutation2(int n)
{
    for(int i=0; i<n; i++){
        perm2[i]=i;
    }
    do{
        for(int i=0; i<n; i++){
            cout << perm2[i];
        }
        cout << ',';
    }while(next_permutation(perm2, perm2+n));
    return;
}

int main()
{
    cout << "再帰による実装:";
    permutation(0, 4);
    cout << endl;
    
    cout << "標準ライブラリ:";
    permutation2(4);
    cout << endl;

    return 0;
}