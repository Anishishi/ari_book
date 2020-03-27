#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;

void print(vector< vector<int> >& p_v){
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            cout << p_v[i][j];
        }
        cout << endl;
    }
}

int main(){
    vector< vector<int> > vt(4, vector<int>(3, 1));
    print(vt);

    //fill(vt.begin(), vt.begin(), 0);
    print(vt);
    return 0;
}