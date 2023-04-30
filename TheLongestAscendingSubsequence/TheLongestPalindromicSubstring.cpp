/*
给定⼀个字符串 s ，找到其中最长的回⽂⼦序列，并返回该序列的长度。可以假设 s 的最⼤
长度为 1000 。
⽰例 1:
输⼊: "bbbab"
输出: 4
⼀个可能的最长回⽂⼦序列为 "bbbb"。
⽰例 2:
输⼊:"cbbd"
输出: 2
⼀个可能的最长回⽂⼦序列为 "bb"。
提⽰：
1 <= s.length <= 1000
s 只包含⼩写英⽂字母
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class TheLongestPalindromSub{
public:
/*
dp[i][j]:字符串str在[i,j]范围内的最长回文子序列长度为d[i][j];
***递推公式
如果str[i]==str[j]那么最长回文子序列就是dp[i][j]=dp[i+1][j-1]+2;
即，在上一个回文字串里再加上左右两个
如果str[i]!=str[j]那么就分别加入str[i]与str[j]看哪一个的回文子序列更长
即,dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
***初始化
因为计算不到i=j的情况，所以需要手动初始化dp[i][j](i=j)的情况
其他初始化为0
***遍历顺序
由递推公式可知，应该从上往下，从左往右初始化
***举例推导
        str="cbbd"
        c   b   b   d
    c   1   1   2   2
    b   0   1   2   2
    b   0   0   1   1
    d   0   0   0   1
    结果就是dp[0][str.size()-1];
*/
    int TheLongestPalindormSub_A(string str){
        vector<vector<int>>dp(str.size(),vector<int>(str.size(),0));
        for(int i=0;i<str.size();i++)dp[i][i]=1;
        for(int i=str.size()-1;i>=0;i--){
            for(int j=i+1;j<=str.size()-1;j++){
                if(str[i]==str[j])dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
        return dp[0][str.size()-1];
    }
};

//输入输出
void TheLongestPalindromFormat(){
    string str;
    cin>>str;
    TheLongestPalindromSub obj;
    int val=obj.TheLongestPalindormSub_A(str);
    cout<<val;
}