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
    int n = 0;
    scanf("%d",&n);//先输入一个数字表示数组大小
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    priority_queue <int> value_heap;
    map<int,priority_queue <int>> mc;
    for (int i = 0; i < n; i++)
    {
        if (!mc.count(arr[i]))
        {
            priority_queue <int> tem;
            tem.push(i);
            mc[arr[i]] = tem;
        }
        else
        {
            mc[arr[i]].push(i);
        }
    }
    //
    map<int,priority_queue<int>>::iterator it;
    for (it = mc.begin(); it != mc.end(); it++)
    {
        value_heap.push(it->first);
    }
    while (!value_heap.empty())
    {
        //printf("%d",(int)value_heap.size());
        int tem_value;
        tem_value = value_heap.top();
        if ((int)mc[tem_value].size() >= 2)
        {
            value_heap.pop();
            int tem_index;
            tem_index = mc[tem_value].top();
            mc[tem_value].pop();
            arr[tem_index] = 0;
            int tem_index2;
            tem_index2 = mc[tem_value][0];
            mc[tem_value].pop();//
            arr[tem_index2] = arr[tem_index2]*2;
            if ((int)mc[tem_value].size() >= 2)
            {
                value_heap.push(tem_value);
            }
            if (mc.count(tem_value*2))
            {
                mc[tem_value*2].push(tem_index2);
            }
            else
            {
                priority_queue<int> tem_vector;
                tem_vector.push(tem_index2);
                mc[tem_value*2] = tem_vector;
                value_heap.push(tem_value*2);
            }
        }
        else
            value_heap.pop();//
    }
    

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            printf("%d",arr[i]);
            printf(" ");
        }
        
    }

    //printf("%d",dp[c]);
    system("pause");
}