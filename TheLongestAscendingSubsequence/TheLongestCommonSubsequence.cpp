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
/*
字符串的⼀个⼦序列是原始字符串删除⼀些（也可以不删除）字符⽽不改变剩余字符相对位
置形成的新字符串。（例如，"ace"是"abcde"的⼀个⼦序列，⽽"aec"不是）。
⽰例 1：
输⼊：s = "abc", t = "ahbgdc"
输出：true
⽰例 2：
输⼊：s = "axc", t = "ahbgdc"
输出：false
 }
};
提⽰：
0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由⼩写字符组成。
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
    //动态规划，判断S是否是T的子序列
    bool TheLongestCommentTorF_A(string S2,string T2);
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
dp[i][j]:表示以下标i-1为结尾的字符串S，和以下标j-1为结尾的字符串T，相同的子序列长度为dp[i][j]
***递推公式
考虑两个操作
if(s[i-1]==t[j-1])在t中找到了一个字符，这个字符也在s中出现了
if(s[i-1]!=t[j-1])相当于要删除t的元素，剩下的继续与s匹配

if(s[i-1]==t[j-1])那么dp[i][j]=dp[i-1][j-1]+1因为找到了一个相同的字符，所以要在dp[i-1][j-1]的基础上+1
if(s[i-1]!=t[j-1])那么相当于要删除t的一个元素，t如果把当前元素t[j-1]删除，那么dp[i][j]的数值就是看s[i-1],t[j-2]的结果了即dp[i][j]=dp[i][j-1];
***初始化
dp[i][j]是依赖于dp[i-1][j-1]与dp[i][j-1]的所以要初始化dp[0][0]与dp[i][0];
***举例推导
    t="ahbjdc"      s="abc"

                a   h   b   j   d   c
            0   0   0   0   0   0   0
        a   0   1   1   1   1   1   1
        b   0   0   0   2   2   2   2
        c   0   0   0   0   0   0   3
        结果的意思是S于T相同的子序列的长度，那如果这个长度与S相等，那么S就是T的子序列
*/
template<typename T>
bool TheLongestComment<T>::TheLongestCommentTorF_A(string S2,string T2){
    vector<vector<int>>dp(S2.size()+1,vector<int>(T2.size()+1,0));
    for(int i=1;i<=S2.size();i++){
        for(int j=1;j<=T2.size();j++){
            if(S2[i]==T2[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=dp[i][j-1];
        }
    }
    if(dp[S2.size()][T2.size()]==S2.size());return true;
    return false;
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
/*
***dp数组
dp[i][j]:以i-1为结尾的字符串s的子序列中出现以j-1为结尾的字符串t的个数为dp[i][j]
***递推公式
两种情况
1.当s[i-1]==t[j-1]时：
    （1）：使用s[i-1]来匹配，那么个数就是dp[i-1][j-1];
    （2）：不使用s[i-1]来匹配，那么个数就是dp[i-1][j];
    例如：bagg 与 bag中s[3]与t[2]匹配, 这时s可以不用s[3]来匹配，即用s[0],s[1],s[2]来匹配组成bag
    也可以用s[0],s[1],s[3]来匹配故dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
2.当s[i-1]!=t[j-1]时，只有一种情况：
    也就是不用s[i-1]来匹配即，dp[i][j]=dp[i-1][j];
***初始化
从递推公式dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 和 dp[i][j] = dp[i - 1][j]; 中可以看出dp[i][0]和dp[0][j]是⼀定要初始化的。
每次当初始化的时候，都要回顾⼀下dp[i][j]的定义，不要凭感觉初始化。
dp[i][0]表⽰什么呢？
dp[i][0] 表⽰：以i-1为结尾的字符串s可以随便删除元素，出现空字符串的个数，即字符串t为空串。
那么dp[i][0]⼀定都是1，因为也就是把以i-1为结尾的s，删除所有元素，出现空字符串的个数就是1。

再来看dp[0][j]，dp[0][j]：空字符串s删除其中的元素使其变成字符串t，也就是出现以j-1为结尾的字符串t的个数。
那么dp[0][j]⼀定都是0，空串s如论如何也变成不了t。
最后就要看⼀个特殊位置了，即：dp[0][0] 应该是多少。
dp[0][0]应该是1，空字符串s，可以删除0个元素，变成空字符串t。
***遍历顺序
由dp[i][j]=dp[i-1][j-1]+dp[i-1][j]与dp[i][j]=dp[i-1][j]可以看出，dp[i][j]是由左上与正上方推断出来的
也就是说应该从上到下，从左往右遍历
***举例推导
        s="baegg"   t="bag"
                b   a   g
            1   0   0   0
        b   1   1   0   0
        a   1   1   1   0
        e   1   1   1   0
        g   1   1   1   1
        g   1   1   1   2
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
    //int val=obj.TheLongestCommentTorF_A(text1,text2);
    cout<<val;

}