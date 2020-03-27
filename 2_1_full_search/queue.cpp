#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << que.front() << endl;
    que.pop();
    cout << que.front() << endl;
    que.pop();
    cout << que.front() << endl;
    que.pop();
    
    return 0;
}