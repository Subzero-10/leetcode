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
    scanf("%d",&val);//先输入一个数字表示数组大小
    vector<int> arr(val);
    for(int i=0;i<val;++i)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",arr[1]);
    system("pause");
}
//并查集
int pre[1000 ];
int find(int x)                                       //查找根节点
{ 
    int r=x;
    while ( pre[r] != r )                           //返回根节点 r
        r=pre[r];
    int i=x , j ;
    while( i != r )                                   //路径压缩
    {
         j = pre[ i ]; 				// 在改变上级之前用临时变量  j 记录下他的值 
         pre[ i ]= r ; 				//把上级改为根节点
        i=j;
    }
    return r ;
}
void join(int x,int y)                           //判断x y是否连通，
                                               //如果已经连通，就不用管了 如果不连通，就把它们所在的连通分支合并起,
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fx ]=fy;
}