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
    int c=0;
    int n = 0;
    scanf("%d",&n);//先输入一个数字表示数组大小
    scanf("%d",&c);
    vector<int> cost(n);
    vector<int> happy(n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&cost[i]);
        scanf("%d",&happy[i]);
    }
    vector<int> dp(c+1,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = c; j > cost[i]-1; j--)
        {
            dp[j] = max(dp[j],dp[j-cost[i]]+happy[i]);
        }
    }
    
    printf("%d",dp[c]);
    system("pause");
}