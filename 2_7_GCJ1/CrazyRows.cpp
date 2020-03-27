#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector< int > last1(N);//-1は1がない、その他は1が最後に出てくる列のindex
    for(int i=0; i<N; i++){
        int R=-1,tmp;
        for(int j=0; j<N; j++){
            cin >> tmp;
            if(tmp==1) R=j;
        }
        last1[i]=R;
    }
    
    int ans=0;
    vector<int> up(N, 0);
    for(int n=0; n<N; n++){
        for(int i=0; i<N; i++){
            if(last1[i]<=n){
                ans+=i-n+up[i];
                last1[i]=N+1;
                break;
            }
            else up[i]++;
        }
    }

    cout << ans << endl;
    
    return 0;
}