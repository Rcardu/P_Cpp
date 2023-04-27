/*
给定⼀个数组 prices ，它的第 i 个元素 prices[i] 表⽰⼀⽀给定股票第 i 天的价格。
你只能选择 某⼀天 买⼊这只股票，并选择在 未来的某⼀个不同的⽇⼦ 卖出该股票。设计⼀
个算法来计算你所能获取的最⼤利润。
返回你可以从这笔交易中获取的最⼤利润。如果你不能获取任何利润，返回 0 。
⽰例 1：
输⼊：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买⼊，在第 5 天（股票价格 = 6）的时候卖出，最
⼤利润 = 6-1 = 5 。注意利润不能是 7-1 = 6, 因为卖出价格需要⼤于买⼊价格；同时，你不
能在买⼊前卖出股票。
⽰例 2：
输⼊：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最⼤利润为 0
*/
#include<iostream>
#include<vector>

using namespace std;

template<typename S>
class ShareBuyingTable{
public:
    
    int ShareBuyingTable_A(vector<S>&share);
    //贪心算法
    int ShareBuyingTable_B(vector<S>&share);
    //动态规划
   int ShareBuyingTable_C(vector<S>&share);

};
//暴力递归  时间O(n^2)    空间O(1)
//暴力递归找最大间距
    //从0开始遍历所有
    //从0+1开始遍历所有
    //即从i开始遍历
    //从i+1开始遍历
template<typename S>
int ShareBuyingTable<S>::ShareBuyingTable_A(vector<S>&share){
    int result=0;
    for(int i=0;i<share.size();i++){
        for(int j=i+1;j<share.size();j++){
                result=max(result,share[j]-share[i]);
        }
    }
    return result;
}
//贪心算法  时间O(n)    空间O(1)
//因为股票只买一次，贪心算法就是取最左边的最小值，取最右边的最大值
template<typename S>
int ShareBuyingTable<S>::ShareBuyingTable_B(vector<S>&share){
    int low=INT_MAX;
    int result=0;
    for(int i=0;i<share.size();i++){
        low=min(low,share[i]);//取左侧最小值
        result=max(result,share[i]-low);//取最大区间
    }
    return result;
}
/*dp[i][0]:第i天持有股票时所得到的最大现金
    //刚开始现金数量为0，第i天购买时所持有现金为-share[i];
    //持有与买入不同，可能是昨天持有，今天不买入的话所持有的还是昨天买入的
    //如果第i天持有dp[i][0]
    //第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得现金即，dp[i-1][0];
    //第i天买入所得现金就是今天买入后所得的现金即，-share[i];
    //那么dp[i][0]就应该选择现金最大的即，max(dp[i-1][0],-share[i])
    //dp[i][1]:第i天不持有股票
    //第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票所得现金
    //第i天卖出股票，所得现金就是今天卖出股票后所得的现金即：share[i]+dp[i-1][0];
    //dp[i][1]=max(dp[i-1][1],share[i]+dp[i-1][0])
    //dp[0][0]就表示第0天就持有股票也就是要在第0天买入即，-share[i];
    //dp[0][1]就表示在第0天不持有股票也就是在0天不买入股票即，0;
    //由递推公式可知，dp[i]是由dp[i-1]则采用从前往后遍历
    /*推导  [7 1 5 3 6 4]
            dp[i][0]    dp[i][1]
        0       -7          0
        1       -1          0
        2       -1          4
        3       -1          4
        4       -1          5
        5       -1          5
    */
template<typename S>
int ShareBuyingTable<S>::ShareBuyingTable_C(vector<S>&share){
    vector<vector<int>>dp(share.size(),vector<int>(2));
    dp[0][0]-=share[0];
    dp[0][1]=0;
    for(int i=1;i<share.size();i++){
        dp[i][0]=max(-share[i],dp[i-1][0]);
        dp[i][1]=max(share[i]+dp[i-1][0],dp[i-1][1]);
    }
    return dp[share.size()-1][1];
}


//输入输出 
void ShareBuyingFormat(){
    int N;
    cin>>N;
    vector<int>share;
    for(int i=0;i<N;i++){
        int v;
        cin>>v;
        share.push_back(v);
    }

    ShareBuyingTable<int> shares;
    //int vale=shares.ShareBuyingTable_A(share);
    //int vale=shares.ShareBuyingTable_B(share);
    int vale=shares.ShareBuyingTable_C(share);
    cout<<vale;
\


}