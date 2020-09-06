#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
int a;

int main() {
    int val=0;
    cin>>val;//先输入一个数字表示数组大小
    vector<int> arr[1];
    for(int i=0;i<val;++i)
    {
        cin>>arr[i];
    }
    printf("%d",arr[0]);
}