#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    //宣言(int がキー, const char* が値)
    map<int, const char*> m;

    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED";//別の書き方

    map<int, const char*>::iterator ite;
    ite = m.find(1);
    cout << ite->second << endl;

    ite = m.find(2);
    if(ite==m.end()) cout << "not found\n";
    else cout << ite->second << endl;

    cout << m[10] << endl;

    m.erase(10);

    for(ite=m.begin(); ite!=m.end(); ite++){
        cout << ite->first << ':' << ite->second << endl;
    }

    return 0;
}