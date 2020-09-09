#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include <sstream>
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

int helper(string s){
    int len = s.size();
    if (len<8 || len>120)
    {
        return 1;
    }
    
}
int main() {
    string input;
    while(getline(cin,input)){
        istringstream iss(input);
        vector<string> arr;
        string tem;
        while(iss >> tem){
            arr.push_back(tem);
        }
        int len = arr.size();
        vector<int> output(len);
        for (int i = 0; i < len; i++)
        {
            output[i] = helper(arr[i]);
        }
        for (int i = 0; i < len; i++)
        {
            printf("%d\n",output[i]);//shuchu
        }
    }
    
    system("pause");
}