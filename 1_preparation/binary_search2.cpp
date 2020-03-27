#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool binary_search(int x, vector<int> k, int n){
    int lower=0;
    int upper=n-1;
    while(upper-lower>=1){
        int half=(upper+lower)/2;
        if(k[half]<x){
            lower=half+1;
        }else if(k[half]>x){
            upper=half;
        }else{
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> k(n);
    for(int i=0; i<n; i++){
        cin >> k[i];
    }
    bool ans=false;
    vector<int> card_pair;
    sort(k.begin(), k.end());
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            card_pair.push_back(k[i]+k[j]);
        }
    }
    sort(card_pair.begin(), card_pair.end());
    for(int i=0; i<n*n; i++){
        if(binary_search(m-card_pair[i], card_pair, n*n)){
            ans=true;
            break;
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}