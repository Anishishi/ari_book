#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> dir(N);
    for(int i=0; i<N; i++){
        char tmp;
        cin >> tmp;
        if(tmp=='B') dir[i]=0;
        else dir[i]=1;
    }

    int K=1, M=N;//Mを最小にする、Kは最小のものが一意に決まる
    for(int k=1; k<=N; k++){
        vector<int> f(N, 0);
        int sum=0, ans_M=0;
        for(int i=0; i+k<=N; i++){
            if((dir[i]+sum)%2==0){
                f[i]=1;
                ans_M++;
            }
            sum+=f[i];

            if(i-k+1>=0) sum-=f[i-k+1];
        }
        for(int i=N-k+1; i<N; i++){
            if((dir[i]+sum)%2==0) ans_M=N;

            if(i-k+1>=0) sum-=f[i-k+1];
        }
        
        if(ans_M<M){
            M=ans_M; K=k;
        }
    }
    cout << "(M,K):(" << M << ',' << K << ')' << endl;

    return 0;
}