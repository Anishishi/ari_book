#include <iostream>
using namespace std;

int main()
{
    int coin[6]={1,5,10,50,100,500};
    int coin_num[6];//1,5,10,50,100,500円硬貨の枚数
    for(int i=0; i<6; i++){
        cin >> coin_num[i];
    }
    int pay;
    int ans=0;
    cin >> pay;
    for(int i=5; i>=0; i--){
        int tmp=pay/coin[i];
        if(tmp<=coin_num[i]){
            ans+=tmp;
            pay=pay-tmp*coin[i];
        }else{
            ans+=coin_num[i];
            pay=pay-coin_num[i]*coin[i];
        }
    }
    cout << ans << endl;
    return 0;
}