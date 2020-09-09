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
    vector<int> arr1(val*2);
    vector<int> arr2(val*2);
    for(int i=0;i<val*2;++i)
    {
        cin>>arr1[i];
        //scanf("%d",&arr1[i]);
    }
    for(int i=0;i<val*2;++i)
    {
        cin>>arr2[i];
        //scanf("%d",&arr2[i]);
    }
    int left = 0;
    int right = val*2 -1;
    int hp = 1;
    for (int i = 0; i < val*2; i++)
    {
        if (left == val)
        {
            if (hp<=arr2[right])
            {
                hp = hp+arr2[right]+1;
            }
            hp += arr1[right];
            right--;
        }
        else if (right == val-1)
        {
            if (hp<=arr2[left])
            {
                hp = hp+arr2[left]+1;
            }
            hp += arr1[left];
            left++;
        }
        else
        {
            if ((arr1[left]) >= (arr1[right]))
            {
                if (hp<=arr2[left])
                {
                    hp = hp+arr2[left]+1;
                }
                hp += arr1[left];
                left++;
            }
            else
            {
                if (hp<=arr2[right])
                {
                    hp = hp+arr2[right]+1;
                }
                hp += arr1[right];
                right--;
            }
        }
        printf("%d",hp);
    }
    printf("%d",hp);
    //printf("%d",arr[1]);
    system("pause");
}