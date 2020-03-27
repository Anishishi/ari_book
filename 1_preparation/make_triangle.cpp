#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vt(n);
    for(int i=0; i<n; i++){
        cin >> vt[i];
    }
    int ans=0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int length=vt[i]+vt[j]+vt[k];
                int M=max(vt[i], max(vt[j], vt[k]));
                if(M<length-M){
                    ans=max(ans, length);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}