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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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


/*
9223372036854775807   记住long的最大值是一个以9开头的十九位的数！！！
int的最大值是2147483647,int的最大值是个以二开头的十位数！！
*/