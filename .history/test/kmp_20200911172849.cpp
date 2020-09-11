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

int KMP(string t, string p, vector<int>& next) 
{
	int i = 0; 
	int j = 0;

	while (i < t.size() && j < p.size())
	{
		if (j == -1 || t[i] == p[j]) 
		{
			i++;
            j++;
		}
        else 
            j = next[j];
    }
    if (j == p.size())
        return i - j;//找到p在t的位置
    else 
        return -1;
}
void getNext(string p, vector<int>& next)
{
	next[0] = -1;
	int i = 0, j = -1;

	while (i < p.size()-1)
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}

int main() {
    int val=0;
    cin>>val;//先输入一个数字表示数组个数
    cin.ignore();
    vector<string> arr(val);
    string s;
    for(int i=0;i<val;++i)
    {
        getline(cin, s);
        arr[i] = s;
    }
    vector<int> next(arr[1].size());
    getNext(arr[1], next);
    int a;
    a = KMP(arr[0], arr[1], next);
    printf("%d",a);
    system("pause");
}


/*多个
void getnext(string str, vector<int>& next)
{
    int i = 0,k=-1;
    next[0] = -1;
    while(i<(int)str.size()-1)
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
*/