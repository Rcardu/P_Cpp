/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共⼦序列的长度。
⼀个字符串的 ⼦序列 是指这样⼀个新的字符串：它是由原字符串在不改变字符的相对顺序
的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的⼦序列，但 "aec" 不是 "abcde" 的⼦序列。两个字符串的「公共⼦
序列」是这两个字符串所共同拥有的⼦序列。
若这两个字符串没有公共⼦序列，则返回 0。
⽰例 1:
输⼊：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共⼦序列是 "ace"，它的长度为 3。
⽰例 2:
输⼊：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共⼦序列是 "abc"，它的长度为 3。
⽰例 3:
输⼊：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共⼦序列，返回 0。
提⽰:
1 <= text1.length <= 1000
1 <= text2.length <= 1000
输⼊的字符串只含有⼩写英⽂字符。
*/

/*
动态规划：
    给定一个字符串S和字符串T，计算在S的子序列中T出现的次数
    示例1：
        输入：S="rabbbit",T="rabbit"
        输出：3
        解释：  
            rabb b it
            rab b bit
            ra b bbit

*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename T>
class TheLongestComment{
public:
    //动态规划，最长公共子序列
    int TheLongestComment_A(string text1,string text2);
    //动态规划，S的子序列中T出现的次数
    int TheLongestCommentFine_A(string S1,string T1);
};
/*
不要求连续，但要求相对顺序
***dp数组
dp[i][j]:长度为[0,i-1]的字符串text1与长度为[0,j-1]的字符串text2的最长公共子序列长度为dp[i][j];
***递推公式
如果text1[i-1]==text2[j-1]那么就找到了一个公共元素，即dp[i][j]=dp[i-1][j-1]+1;
如果text1[i-1]!=text2[j-1]那么就看看text1[0,i-2]与text2[0,j-1]的最长公共子序列
和text1[i-1]与text2[j-2]的最长公共子序列，取最大值即，dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
***初始化
当一个串不为空，另一个串为空时，这两个串的公共子序列也就是0，所以dp[i][0]=0;dp[0][j]=0;
***遍历顺序
dp[i][j]可由三个方向得到即，dp[i-1][j-1],dp[i-1][j],dp[i][j-1],可以从前往后，从上到下来遍历
***距离推导
            text1="abcde"   text2="ace"
            0   1   2   3   4   5
        0   0   0   0   0   0   0
        1   0   1   1   1   1   1
        2   0   1   1   2   2   2
        3   0   1   1   2   2   3
        答案取最后一个即可
*/
template<typename T>
int TheLongestComment<T>::TheLongestComment_A(string text1,string text2){
    vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
    for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[text1.size()][text2.size()];
}
/*
***dp数组
dp[i][j]:长度为[0,i-1]的字符串T中出现长度为[0,j-1]的字符串S的次数dp[i][j];
**递推公式
如果T[i-1]==S[j-1]那么就找到了一个公共元素，即dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
如果不相等就就用剩下的j-1个元素来计算即，dp[i][j]=dp[i][j-1];
***初始化
当S串为空时，就是T串的一个字串，即dp[i][0]=1;
***遍历顺序
T在外，S在内，从前往后遍历
***举例推导
    T="rabbbi"  S="rabbi"
    0   1   2   3   4   5
0   1   0   0   0   0   0
1   1   1   0   0   0   0
2   1   1   1   0   0   0
3   1   1   1   1   0   0
4   1   1   1   2   1   0
5   1   1   1   3   3   0
6   1   1   1   3   3   3
*/
template<typename T>
int TheLongestComment<T>::TheLongestCommentFine_A(string S1,string T1){
    vector<vector<int>>dp(S1.size()+1,vector<int>(T1.size()+1,0));
    for(int i=0;i<=S1.size();i++)dp[i][0]=1;
    for(int i=1;i<=S1.size();i++){
        for(int j=1;j<=T1.size();j++){
            if(S1[i-1]==T1[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[S1.size()][T1.size()];
}

//输入输出
void TheLongestCommonForamt(){
    string text1;
    string text2;
    cin>>text1>>text2;

    TheLongestComment<int>obj;
    //int val=obj.TheLongestComment_A(text1,text2);
    int val=obj.TheLongestCommentFine_A(text1,text2);
    cout<<val;

}