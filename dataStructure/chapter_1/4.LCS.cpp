#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcs(string &text1, string &text2, int i, int j, vector<vector<int> > &dp)
{

    if (!i || !j) return 0;
    if(dp[i][j]) return dp[i][j];
    // 如果两个序列最后一个字母相同，返回均去掉最后一个字母的子串的最长子序列长度+1
    // 这个+1代表找到了一个公共字母，因此子序列长度加一
    if(text1[i-1] == text2[i-1]) 
    
    {
        dp[i][j] = lcs(text1, text2, i-1, j-1, dp) + 1;
    }
    // 反之，如果两个序列最后一个字母不相同，就返还s1(i, j-1)和s2(i-1, j)最长子序列中的最大值
    // 即该字母不在子序列中，子序列长度不变，向左向右找值
    else{
        dp[i][j] = max(lcs(text1, text2, i-1, j, dp), lcs(text1, text2, i, j-1, dp));
    }
    return dp[i][j];
}


class Solution {//递归, 自顶而下

private:
    vector<vector<int>> dp;
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        dp = vector<vector<int>>(text1.size() + 1, vector<int>(text2.size() + 1));
        return  longest(text1, text2, text1.size(), text2.size());

    }
    int longest(string& text1, string& text2, int i, int j) {
        if (!i || !j) {
            return 0;
        }
        if (dp[i][j]) return dp[i][j];
        if (text1[i - 1] == text2[j - 1]) {
            dp[i][j] = longest(text1, text2, i - 1, j - 1) + 1;
        }
        else
            dp[i][j] = max(longest(text1, text2, i, j - 1), longest(text1, text2, i - 1, j));
        return dp[i][j];
    }

};

class Solution_iter
{
public:
    int longestCommonSubsequence(string &s1, string &s2)
    {
        vector<vector<int> >dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i=0; i<s1.size(); i++)
        {
            for (int j=0; j<s2.size(); j++)
            {
                if(s1[i] == s2[j])
                {
                    dp[i+1][j+1] = dp[i][j]+1;
				}
                else
                {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    } 
};



int main()
{   
    Solution_iter algor;

    string s1 = "abc";
    string s2 = "adc";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int> > dps = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, 0)); // 创建二维数组，动态vector

    int ret = lcs(s1, s2, n, m, dps);
    int ans = algor.longestCommonSubsequence(s1, s2);
    cout << "ret= " << ret << endl;
    cout << "ans= " << ans << endl;
    return 0;
}

