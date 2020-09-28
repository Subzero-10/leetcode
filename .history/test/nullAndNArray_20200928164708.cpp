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
const double PI = acos(-1.0);
int a;

int main() {
    string input;
    while(getline(cin,input)){
        istringstream iss(input);
        vector<int> arr;
        int val;
        while(iss >> val)
            arr.push_back(val);
        cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    }
    system("pause");
}