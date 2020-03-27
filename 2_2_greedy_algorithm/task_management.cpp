#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int> tasks[n];
    //終了時間をfirst,開始時間をsecondに格納
    for(int i=0; i<n; i++){
        cin >> tasks[i].second;
    }
    for(int i=0; i<n; i++){
        cin >> tasks[i].first;
    }
    
    sort(tasks, tasks+n);
    int ans=0;
    int now=0;
    for(int i=0; i<n; i++){
        if(tasks[i].second>now){
            ans++;
            now=tasks[i].first;
        }
    }
    cout << ans << endl;//最大可能仕事量
    return 0;
}