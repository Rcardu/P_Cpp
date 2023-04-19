/*
有N件物品和⼀个最多能被重量为W 的背包。第i件物品的重量是weight[i]，得到的价值是
value[i] 。每件物品只能⽤⼀次，求解将哪些物品装⼊背包⾥物品价值总和最⼤。

这是标准的背包问题，以⾄于很多同学看了这个⾃然就会想到背包，甚⾄都不知道暴⼒的解
法应该怎么解了。

这样其实是没有从底向上去思考，⽽是习惯性想到了背包，那么暴⼒的解法应该是怎么样的
呢？

每⼀件物品其实只有两个状态，取或者不取，所以可以使⽤回溯法搜索出所有的情况，那么
时间复杂度就是O(2^n)，这⾥的n表⽰物品数量。
*/
#include<iostream>
#include<vector>
using namespace std;

class  knapsack_01{
    public:
        //有i个物品，背包的容量为j，则dp[i][j]就是背包物品的最大价值
        /*              背包容量为j
            有i个物品   0   1   2   3   4
                物品0
                物品1
                物品2
        */
       //当背包种不放物品i时，背包状态（即dp[i][j]）为dp[i-1][j]，也就是上一次存放的状态
       //当背包种放入物品i时，背包状态（即dp[i][j]）为dp[i-1][j-weight[i]]+value[i]，也就是存入物品i时的状态
       //只需要取是否将物品i放入背包即可
       //max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
       //当背包容量j为0时，也就没有物品,价值也就为0
       /*                  背包容量为j
       有i个物品      0   1   2   3   4
             物品0    0   
             物品1    0
             物品2    0
       */
      //由于i是否放入取决于i-1是否放入也就是当i=1，i-1=0时即dp[0][j]时各个容量的背包所存放的价值
      //例如第0个物品价值为15时
      /*                  背包容量为j
       有i个物品    0   1   2   3   4
       物品0        0   15  15  15  15  
       物品1        0
       物品2        0
       */
      //可知当放入物品0时不论背包现在的容量时多少，价值都是15
      //但如果背包自身的容量j<weight[0]时，他就装不下第0个物品，价值也就是0
      //j>=weight时，可以装下，价值也就是value[0];

      int knapsack_01i(vector<int>&weight,vector<int>&value,int W){
        vector<vector<int>>dp(weight.size()+1,vector<int>(W+1,0));

        for(int j=weight[0];j<=W;j++){
            dp[0][j]=value[0];
      }
      for(int i=1;i<weight.size();i++){
        for(int j=0;j<=W;j++){
            if(j<weight[i])dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
        }
      }
      return dp[weight.size()-1][W];
    }
};


//输入和输出
void packFormat(){
    int N,W;
    cin>>N>>W;
    vector<int>weight(N,0);
    vector<int>value(N,0);
    for(int i=0;i<N;i++){
        cin>>weight[i]>>value[i];
    }

    knapsack_01 obj;
    int val=obj.knapsack_01i(weight,value,W);
    cout<<val;
}