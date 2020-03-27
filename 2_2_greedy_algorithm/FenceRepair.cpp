#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> board(N);
    for(int i=0; i<N; i++){
        cin >> board[i];
    }
    ll ans=0;
    while(N>1){//板が1本になるまでソート
        sort(board.begin(), board.begin()+N);
        ll tmp=board[0]+board[1];
        ans+=tmp;
        board.erase(board.begin(),board.begin()+2);
        board.insert(board.begin(),tmp);
        N--;
    }
    cout << ans << endl;

    return 0;
}