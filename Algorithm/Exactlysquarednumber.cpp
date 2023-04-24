/*
给定正整数 n，找到若⼲个完全平⽅数（⽐如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要
让组成和的完全平⽅数的个数最少。
给你⼀个整数 n ，返回和为 n 的完全平⽅数的 最少数量 。
完全平⽅数 是⼀个整数，其值等于另⼀个整数的平⽅；换句话说，其值等于⼀个整数⾃乘
的积。例如，1、4、9 和 16 都是完全平⽅数，⽽ 3 和 11 不是。
⽰例 1：
输⼊：n = 12
输出：3
解释：12 = 4 + 4 + 4
⽰例 2：
输⼊：n = 13
输出：2
解释：13 = 4 + 9
提⽰：
1 <= n <= 10^4
*/
#include<iostream>
#include<vector>

using namespace std;

class ExactlysquraentlyIntegratedNumbers{
    public:
        //dp[i]:和为i的完全平方数的最少数量为dp[i]
        //dp[j-i*i]可以推出dp[j];
        //dp[0]=0;
        //dp[j]=min(dp[j],dp[j-i*i]+1);
        //i*i就是完全平方数，这个值要小于给定的数
        //而j从1开始，也就是背包从1开始装
        /*              12
            0   1   2   3   4   5   6   7   8   9  10  11  12
            0   1   2   3   1   2   3   4   2   1  02  03  03
        */
        int minNumberOfIntegratedNumbers_A(int n){
            vector<int>dp(n+1,INT_MAX);
            dp[0]=0;
            for(int i=1;i*i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(j>=i*i)dp[j]=min(dp[j],dp[j-i*i]+1);
                }
            }
            /*先背包后物品
                for(int i=1,i<=n;i++){
                    for(int j=1;j*j<=i;j++){
                        dp[i]=min(dp[i],dp[i-j*j]+1);//这里要比前一个更简单，不要
                    }
                }
            
            */
            return dp[n];
        }
};

//输入输出
void ExacltlysquraedForamt(){
    int n; cin >> n; 

    ExactlysquraentlyIntegratedNumbers obj;
    int val = obj.minNumberOfIntegratedNumbers_A(n);
    cout<<val;

}