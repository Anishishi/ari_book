#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int P;
    cin >> P;
    vector<int> a(P), flags(10000000, 0);
    set<int> nums;
    for(int i=0; i<P; i++){
        cin >> a[i];
        nums.insert(a[i]);
    }

    //愚直なしゃくとり
    /*int r=0, l=0;
    while(nums.size()!=0){
        flags[a[r]]++;
        nums.erase(a[r]);
        r++;
    }
    r--;
    int ans=r-l+1;
    
    while(true){
        flags[a[l]]--;
        l++;

        while(flags[a[l-1]]<=0){
            r++;
            if(r==P) break;
            flags[a[r]]++;
        }
        ans=min(ans, r-l+1);
        
        if(r==P) break;
    }*/

    //mapを用いたしゃくとり法
    int s=-1, t=-1, num=0, n=nums.size();
    map<int, int> count;//事柄、出現回数
    int ans=P;
    for(;;){
        while(t<P && num<n){
            if(count[a[t++]]++ == 0){
                //新しい事柄が出現
                num++;
            }
        }
        if(num<n) break;
        ans=min(ans, t-s);
        if(--count[a[s++]]==0){
            //ある事柄の出現回数が0になった
            num--;
        }
    }

    cout << ans << endl;

    return 0;
}