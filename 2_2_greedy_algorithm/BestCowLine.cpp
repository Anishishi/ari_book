#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<char> S;
    for(int i=0; i<N; i++){
        char tmp;
        cin >> tmp;
        S.push_back(tmp);
    }
    vector<char> ans;
    for(int i=0; i<N; i++){
        if(S.front()<S.back()){
            ans.push_back(S.front());
            S.erase(S.begin());
        }else{
            ans.push_back(S.back());
            S.pop_back();
        }
    }
    for(int i=0; i<N; i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}