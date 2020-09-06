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
    vector<string> arr(val);
    for(int i=0;i<val;++i)
    {
        char buff[255];
        cin.getline(buff,255);
        arr.push_back(s);
        //cout << s << endl;
    }
    printf("%s",arr[1].c_str());
    system("pause");
}