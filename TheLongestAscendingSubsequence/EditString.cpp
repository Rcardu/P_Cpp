/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使⽤的最少操作数 。
你可以对⼀个单词进⾏如下三种操作：
插⼊⼀个字符
删除⼀个字符
替换⼀个字符
⽰例 1：
输⼊：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
⽰例 2：
输⼊：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插⼊ 'u')
提⽰：
0 <= word1.length, word2.length <= 500
word1 和 word2 由⼩写英⽂字母组成
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class EditString{
public:
/*
dp[i][j]:以i-1为结尾的串str1，转换到以j-1为结尾的串str2最少的操作步数为dp[i][j];
***递推公式
~if(str1[i-1]==str[j-1])不进行操作
    ~即dp[i][j]=dp[i-1][j-1];
~if(str1[i-1]!=str2[j-1])对str1或str2进行删除、替换、插入操作
    ~对于删除操作：
        ~删除str1的一个元素，那么就是以i-2为结尾的str1与以j-1为结尾的str2的最近编辑距离再加上一个操作dp[i][j]=dp[i-1][j]+1;
        ~删除str2的一个元素，同上dp[i][j]=dp[i][j-1]+1;
    !对于插入操作，假如删除str1中的一个元素，那么就相当于给str2添加一个元素，两者的操作数都是一样的
    例如str1="ad"   str2="a"    那么删除str1中的"d"达成str1="a" 此时str1==str2了
                                同理给str2添加一个元素"d",达成str2="ad",这两个操作所都用了一步
    ~对于替换操作：在str1中替换一个元素str1[i-1]使其与str2[j-1]相等，此时不用增加元素
    那么，以i-2为结尾的str1与以j-2为结尾的str2的最近编辑距离加上一个操作就是dp[i][j]即，dp[i][j]=dp[i-1][j-1]+1;
    综上，操作取最小值dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1);
***初始化
对于递推公式可知，dp[i][0]与dp[0][j]需要初始化
当str2为空串时，str1需要删除所有元素，即dp[i][0]=i
同理dp[0][j]=j;
***遍历顺序
由递推公式可知：
从上往下，从左往右
***举例推导
以 str1="horse" str2="ros"
            r   o   s
        0   1   2   3
    h   1   1   2   3
    o   2   2   1   2
    r   3   2   2   2   
    s   4   3   3   2
    e   5   4   4   3

*/
int EditString_A(string str1,string str2){
    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));
    for(int i=1;i<=str1.size();i++)dp[i][0]=i;
    for(int j=1;j<=str2.size();j++)dp[0][j]=j;
    for(int i=1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    return dp[str1.size()][str2.size()];
}
};



//输入输出
void EditStringFormat(){
    string str1,str2;
    cin>>str1>>str2;

    EditString obj;
    int val=obj.EditString_A(str1,str2);
    cout<<val;
}