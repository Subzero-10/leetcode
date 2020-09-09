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
    vector<int> value_heap;
    map<int,vector<int>> mc;
    for (int i = 0; i < n; i++)
    {
        if (!mc.count(arr[i]))
        {
            vector<int> tem;
            tem.push_back(i);
            mc[arr[i]] = tem;
        }
        else
        {
            mc[arr[i]].push_back(i);
            push_heap(mc[arr[i]].begin(),mc[arr[i]].end());
        }
    }
    //
    map<int,vector<int>>::iterator it;
    for (it = mc.begin(); it != mc.end(); it++)
    {
        value_heap.push_back(it->first);
        push_heap(value_heap.begin(),value_heap.end());
    }
    while (!value_heap.empty())
    {
        int tem_value;
        tem_value = value_heap[0];
        pop_heap(value_heap.begin(),value_heap.end());
        int tem_index;
        tem_index = mc[tem_value][0];
        pop_heap(mc[tem_value].begin(),mc[tem_value].end());
        arr[tem_index] = 0;
        int tem_index2;
        tem_index2 = mc[tem_value][0];
        arr[tem_index2] = arr[tem_index2]*2;
        if ((int)mc[tem_value].size() >= 2)
        {
            value_heap.push_back(tem_value);
            push_heap(value_heap.begin(), value_heap.end());
        }
        if (mc.count(tem_value*2))
        {
            mc[tem_value*2].push_back(tem_index2);
            push_heap(mc[tem_value*2].begin(), mc[tem_value*2].end());
        }
        else
        {
            vector<int> tem_vector(1,tem_index2);
            mc[tem_value*2] = tem_vector;
        }
        if ((int)mc[tem_value*2].size() >=2 && count(value_heap.begin(),value_heap.end(),tem_value*2) == 0)
        {
            value_heap.push_back(tem_value*2);
        }
        printf("?");
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