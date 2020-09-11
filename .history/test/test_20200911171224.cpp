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


void getnext(string str, vector<int>& next)
{
    int i = 0,k=-1;
    next[0] = -1;
    while(i<(int)str.size())
    {
        if(k== -1 || str[i] == str[k])
        {
            i++;
            k++;
            next[i] = k;
        }
        else
            k = next[k];
    }
}
int KMP(string s, string t, vector<int>& next)
{
    int i=0,j=0;
    int ans = 0;
    int len1=s.size();
    int len2=t.size();
    while(i<len2)
    {
        if(j==-1||s[j]==t[i])
        {
            ++i;
            ++j;
        }
        else
            j=next[j];
        if(j==len1)
        {
            ans++;
            j=next[j];//只要找到了就加一,并且不返回即可;
        }
    }
    return ans;
}

int main() {
    int n=0;
    cin>>n;//n长
    int m=0;
    cin>>m;//m行
    cin.ignore();
    string str1;
    getline(cin, str1);
    vector<string> arr(m);
    string str;
    int sum = 0;
    for(int i=0;i<m;++i)
    {
        getline(cin, str);
        arr[i] = str;
    }
    vector<int> next(10);
    for (int i = 0; i < m; i++)
    {
        getnext(arr[i],next);
        sum += KMP(arr[i],str1,next);
        printf("?");
    }
    printf("%d",sum);
    system("pause");
}