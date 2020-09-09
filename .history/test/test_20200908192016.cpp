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

bool find(vector<vector<char>> & board, string s){
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[0].size(); j++)
        {
            if (helper(board, s, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}
bool helper(vector<vector<char>> & board, string s, int i, int j, int l){
    int ilen = board.size();
    int jlen = board.size();
    if (i<0||i>=ilen||j<0||j>=jlen)
    {
        return false;
    }
    if (l == ((int)s.size() - 1))
    {
        if (s[l] == board[i][j])
        {
            return true;
        }
    }
    char tem = board[i][j];
    board[i][j] = '\0';
    if (s[l] == tem)
    {
        if (helper(board, s, i+1, j, l+1)||helper(board, s, i, j+1, l+1)||helper(board, s, i, j-1, l+1)||helper(board, s, i-1, j, l+1))
        {
            return true;
        }
    }
    board[i][j] = tem;
    return false;
}
int main() {
    string s;
    getline(cin, s);
    vector<char> s1 = {'A','B','C','E'};
    vector<char> s2 = {'S','F','C','S'};
    vector<char> s3 = {'A','D','E','E'};
    vector<vector<char>> board;
    board.push_back(s1);
    board.push_back(s2);
    board.push_back(s3);
    
    if (find(board, s))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    system("pause");
}