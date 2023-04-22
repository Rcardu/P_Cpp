/*
给定不同⾯额的硬币和⼀个总⾦额。写出函数来计算可以凑成总⾦额的硬币组合数。假设每
⼀种⾯额的硬币有⽆限个。
⽰例 1:
输⼊: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种⽅式可以凑成总⾦额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
⽰例 2:
输⼊: amount = 3, coins = [2]
输出: 0
解释: 只⽤⾯额2的硬币不能凑成总⾦额3。
⽰例 3:
输⼊: amount = 10, coins = [10]
输出: 1
注意，你可以假设：
0 <= amount (总⾦额) <= 5000
1 <= coin (硬币⾯额) <= 5000
硬币种类不超过 500 种
结果符合 32 位符号整数
*/
#include<iostream>
#include<vector>

using namespace std;

class coindenominations
{
    public:
        //求金币组成的目标值的组合方式
        //dp[j]:凑成金额为j的货币组合数为dp[j]
        //因为要求的是目标和，所以再不考虑coins[i]的情况下，dp[j-coins[i]]的总和
        //即，dp[j]+=dp[j-coins[i]];
        //凑成总金额为0的组合方式为1，所以dp[0]=1
        //先遍历物品再遍历背包，使每种组合只出现一次
        //如果先背包，再物品，会使物品组合多次出现，就成了排列数
        /*  00  01  02  03  04  05
        1   01  01  01  01  01  01
        2   01  01  02  02  03  03
        5   01  01  02  02  03  04
        */
       int conindenomination(int amount,vector<int>&coins){
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
       }
 
};



//输入输出
void CoindeFormat(){
    //金币数和目标额度
    int N,amount;
    cin>>N>>amount;
    vector<int>coins(N,0);
    for(int i=0;i<N;i++)cin>>coins[i];

    coindenominations obj;
    int val=obj.conindenomination(amount,coins);
    cout<<val;
}