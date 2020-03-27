#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> tile(N);
    for(int i=0; i<N; i++){
        cin >> tile[i];
    }
    //順位キューが小さい数から出てくるように作る、何も指定しない場合は大きい方から出てくる。
    //template <class T, class Container = std::vector<T>, class Compare = less<typename Container::value_type>>
    priority_queue<int, vector<int>, greater<int> > que;
    for(int i=0; i<N; i++){
        que.push(tile[i]);
    }
    ll ans=0;
    while(que.size() > 1){
        int tmp1, tmp2;
        tmp1 = que.top();
        que.pop();
        tmp2 = que.top();
        que.pop();

        ans += tmp1+tmp2;
        que.push(tmp1+tmp2);
    }
    cout << ans << endl;

    return 0;
}