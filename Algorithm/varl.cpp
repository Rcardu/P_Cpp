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
void S_and_T(){
    string S,T;
    cin>>S;
    cin>>T;
    int s_length=S.length();
    int t_length=T.length();
    vector<vector<int>>dp(t_length,vector<int>(s_length,0));
    //边界条件,当字符串T为空时默认为S的子串，即dp[0][j]=1;
    for(int j=0;j<s_length;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<t_length;i++){
        for(int j=1;j<s_length;j++){
            if(T[i-1]==S[j-1]){
                //如果T的第i个字符和S的第j个字符一样
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            }else{
                //如果不一样就用j-1个字符来计算其他的包含量
                dp[i][j]=dp[i][j-1];
            }
        }
    }

}
