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
#include"math.h"
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
    for(int i=0;i<val;++i)
    {
        int n,m,k;
        cin>>n;
        cin>>m;
        cin>>k;
        double a;
        double b;
        for (int j = 0; j < m; j++)
        {
            for (int l = 0; l < k; l++)
            {
                cin>>a;
            }
        }
        a = (m*pow((m-k),(n-1)));
        b = (pow(10,9)+7);
        printf("%d\n",a);
    }
    //printf("%d\n",hp);
    //printf("%d",arr[1]);
    system("pause");
}