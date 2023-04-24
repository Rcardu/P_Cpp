/*
给定不同⾯额的硬币 coins 和⼀个总⾦额 amount。编写⼀个函数来计算可以凑成总⾦额所
需的最少的硬币个数。如果没有任何⼀种硬币组合能组成总⾦额，返回 -1。
你可以认为每种硬币的数量是⽆限的。
⽰例 1：
输⼊：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
⽰例 2：
输⼊：coins = [2], amount = 3
输出：-1
⽰例 3：
输⼊：coins = [1], amount = 0
输出：0
⽰例 4：
输⼊：coins = [1], amount = 1
输出：1
⽰例 5：
输⼊：coins = [1], amount = 2
输出：2
提⽰：
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/
#include<iostream>
#include<vector>

using namespace std;

//find the minimum number of coins to make up the amount
        class RedeemChangeAgain{
            public:
                //dp[j]:凑到j金额的最少硬币数量(0-based indexing)为dp[j];
                //不计算第i个硬币的价值cions[i]下，最少的硬币数量为dp[j - cions[i]]
                //凑足金额为j-coins[i]的硬币数量的最少个数为dp[j-coins[i]]+1;
                //当加上cions[i]后就是凑足金额为j个需要的最少的硬币数量了
                //dp[j]取所有dp[j-coins[i]]中最小的
                //dp[j]=min(dp[j],dp[j-coins[i]]+1);
                //凑足金额为0的数目需要的硬币数量为0
                //dp[0]=0;
                //dp[j]为防止被覆盖应该初始化为一个最大值
                //vector<int>dp(N+1,INT_MAX);
                //dp[0]=0;
                //求组成目标值的最小个数，所以硬币本身是有序还是无序并不影响
                //求组和为外物品，内背包
                //求排列为外背包，内物品
                //本体只求最小数，所以并不需要组合或者排列
                /*  1   2   5
                    0   1   2   3   4   5
                    0   1   1   2   2   1
                */
               int RedeemChangeAgain_A(vector<int>coins,int amount){
                    vector<int>dp(amount+1,INT_MAX);
                    dp[0]=0;
                    for(int i=0;i<coins.size();i++){
                        for(int j=coins[i];j<=amount;j++){
                            dp[j]=min(dp[j],dp[j-coins[i]]+1);  //min number of coins to make change with remaining coins
                        }
                    }
                    return dp[amount];  //amount of coins to make change with remaining coins
               }
                //coins[]: the coins used, amount: the amount to be made with coins.
        };


//输入输出
void RedeemForamt(){
    int N,amount;
    cin>>N>>amount; //N coins, amount to be redeemed.
    vector<int> coins(N);//coins[i] is the value of the ith coin.
    for(int i=0;i<N;i++){//fill coins vector with coins. (read coins from left to right)
        cin>>coins[i];//read coins. (coins[0] is the most common way of filling coins vector)
    }

    RedeemChangeAgain obj;
    int val=obj.RedeemChangeAgain_A(coins,amount);//amount of coins to make change with remaining coins. (returns INT_MAX if coins
    cout<<val;//amount is not possible or coins are not ordered)


}