#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int N, R;
    cin >> N >> R;
    vector<int> x(N);
    for(int i=0; i<N; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int i=0, ans=0;
    while(i<N){
        int s=x[i++];//カバーされていない一番左の点
        while(i<N && x[i]<=s+R) i++;
        int p = x[i-1];
        while(i<N && x[i]<=p+R) i++;
        ans++;
    }
    cout << ans << endl;

    return 0;
}