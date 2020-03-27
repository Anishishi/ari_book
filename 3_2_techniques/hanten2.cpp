#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;

const int dx[5]={-1, 0, 0, 0, 1};
const int dy[5]={0, -1, 0, 1, 0};//xがH,yがW
int H,W;
vector< vector <int> > tile(15, vector<int>(15)),flip(15, vector<int>(15));//入力、最適解、反転回数
int opt[15][15], optans[15][15];

void cp(vector< vector<int> >& v){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            opt[i][j]=v[i][j];
        }
    }
}

void print(vector< vector<int> >& p_v){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << p_v[i][j];
        }
        cout << endl;
    }
}

int get(int x, int y){//そのマスの色を調べる
    int c=tile[x][y];
    for(int i=0; i<5; i++){
        int x1=x+dx[i], y1=y+dy[i];
        if(0<=x1 && x1<H && 0<=y1 && y1<W) c+=flip[x1][y1];
    }
    return c%2;
}

//1行目を決めた時の最小回数を求める、解が存在しなければ-1
int calc(){
    int ans=0;
    for(int h=1; h<H; h++){
        for(int w=0; w<W; w++){
            if(get(h-1,w)==1){
                flip[h][w]=1;
            }
            //print(tile);print(flip);
            //cout << endl;
        }
    }
    for(int w=0; w<W; w++){
        ans+=flip[0][w];
        if(get(H-1, w)==1) return -1;
    }
    cp(flip);
    return ans;
}

void solve(){
    int ans=-1;
    for(int w=0; w< 1<<W; w++){
        vector< vector <int> > flip(15, vector<int>(15, 0));
        for(int j=0; j<W; j++){
            flip[0][W-j-1]=w >> j & 1;
        }
        int tmp=calc();
        //print(flip);
        if(tmp>=0 && (ans<0 || ans>tmp)){
            ans=tmp;
            memcpy(optans, opt, sizeof(opt));
        }
    }

    if(ans<0) cout << "IMPOSSIBLE\n";
    else{
        for(int h=0; h<H; h++){
            for(int w=0; w<W; w++){
                cout << optans[h][w] << (w+1==W ? '\n' : ' ');
            }
        }
    }
}

int main(){
    cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> tile[i][j];
        }
    }

    solve();

    return 0;
}