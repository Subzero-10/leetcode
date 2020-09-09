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
    cin.ignore();
    vector<string> arr(val);
    string s;
    for(int i=0;i<val;++i)
    {
        getline(cin, s);
        int left = 0;
        int right = 0;
        if(s[0] == 'S')
        {
            if (s[2] == 'J')
            {
                left++;
            }
            else
            {
                left--;
            }
            if (s[3] == 'J')
            {
                left++;
            }
            else
            {
                left--;
            }
        }
        else if (s[0] == 'J')
        {
            if (s[2] == 'B')
            {
                left++;
            }
            else
            {
                left--;
            }
            if (s[3] == 'B')
            {
                left++;
            }
            else
            {
                left--;
            }
        }
        else if (s[0] == 'B')
        {
            if (s[2] == 'S')
            {
                left++;
            }
            else
            {
                left--;
            }
            if (s[3] == 'S')
            {
                left++;
            }
            else
            {
                left--;
            }
        }
        //右手
        if(s[1] == 'S')
        {
            if (s[2] == 'J')
            {
                right++;
            }
            else
            {
                right--;
            }
            if (s[3] == 'J')
            {
                right++;
            }
            else
            {
                right--;
            }
        }
        else if (s[0] == 'J')
        {
            if (s[2] == 'B')
            {
                right++;
            }
            else
            {
                right--;
            }
            if (s[3] == 'B')
            {
                right++;
            }
            else
            {
                right--;
            }
        }
        else if (s[0] == 'B')
        {
            if (s[2] == 'S')
            {
                right++;
            }
            else
            {
                right--;
            }
            if (s[3] == 'S')
            {
                right++;
            }
            else
            {
                right--;
            }
        }
        if (left>right)
        {
            printf("left");
        }
        else if (left<right)
        {
            printf("right");
        }
        else
        {
            printf("same");
        }
        
        
    }
    printf("%s", arr[0].c_str());//输出
    system("pause");
}