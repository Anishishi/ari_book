#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//UnionFind
class UnionFind{
public:
    vector<int> Parent;

    UnionFind(int N){
        Parent = vector<int>(N, -1);
    }
    int root(int a){
        if(Parent[a]<0) return a;
        return Parent[a]=root(Parent[a]);
    }
    int size(int a){
        return -Parent[root(a)];
    }
    bool connect(int a, int b){
        a = root(a);
        b = root(b);
        if(a==b){
            return false;
        }
        if(size(a)<size(b)) swap(a,b);
        Parent[a]+=Parent[b];
        Parent[b]=a;
        return true;
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    int ans=0;
    UnionFind Uni(3*N);
    for(int i=0; i<K; i++){
        int info_type, x, y;
        cin >> info_type >> x >> y;
        x--;
        y--;
        if(x<0 || x>=N || y<0 || y>=N){
            ans++;
            continue;
        }
        if(info_type==1){
            if(Uni.root(x)==Uni.root(y+N) || Uni.root(x)==Uni.root(y+2*N)){
                ans++;
            }else{
                Uni.connect(x, y);
                Uni.connect(x+N, y+N);
                Uni.connect(x+2*N, y+2*N);
            }
        }else{
            if(Uni.root(x)==Uni.root(y) || Uni.root(x)==Uni.root(y+2*N)){
                ans++;
            }else{
                Uni.connect(x, y+N);
                Uni.connect(x+N, y+2*N);
                Uni.connect(x+2*N, y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}