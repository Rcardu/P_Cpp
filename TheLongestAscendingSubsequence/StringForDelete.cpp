/*
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最⼩步数，每步可以
删除任意⼀个字符串中的⼀个字符。
⽰例：
输⼊: "sea", "eat"
输出: 2
解释: 第⼀步将"sea"变为"ea"，第⼆步将"eat"变为"ea"
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class StringForDelete{
public:
    /*
    dp[i][j]:以i-1为结尾的字符串str1和以j-1为结尾的字符串str2，想要达到相等，至少需要删除元素的次数为dp[i][j];
    ***
    ~当str1[i-1]==str2[j-1]时
    ~当str1[i-1]!=str2[j-1]时
    当str1[i-1]==str2[j-1]时，要删除的次数就是上一次删除的次数dp[i][j]=dp[i-1][j-1];
    当str1[i-1]!=str2[j-1]时有三种情况
        ~删除str1[i-1],最少操作次数为dp[i-1][j]+1;
        ~删除str2[j-1],最少操作次数为dp[i][j-1]+1;
        ~同时删除str1[i-1],str2[j-1]最少操作次数为dp[i-1][j-1]+2;
    最后取最小值即dp[i][j]=min(dp[i-1][j-1]+2,dp[i][j-1]+1,dp[i][j-1]+1);
    ***
    由递推公式dp[i][0]与dp[0][j]需要初始化
    dp[i][0]:即str2为空串，str1就需要删除i个元素才能是空串，即dp[i][0]=i;
    相同dp[0][j]=j;
    ***遍历顺序
    dp[i][j]由左上，左边，上边决定，故从上到下，从左往后遍历
    ***举例推导
        str1="sea"  str2="eat"
                    e   a   t
                0   1   2   3
            s   1   2   3   4
            e   2   1   2   3
            a   3   2   1   2
    */
   int StringForDelete_A(string str1,string str2){
    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));
    for(int i=1;i<=str1.size();i++)dp[i][0]=i;
    for(int j=1;j<=str2.size();j++)dp[0][j]=j;
    for(int i=1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j-1]+2,min(dp[i][j-1]+1,dp[i-1][j]+1));
        }
    }
    return dp[str1.size()][str2.size()];
   }
};


//输入输出
void StringForDeleteFormaat(){
    string str1,str2;
    cin>>str1>>str2;
    StringForDelete obj;
    int val=obj.StringForDelete_A(str1,str2);
    cin>>val;

}