/*
给定⼀个数组，它的第 i 个元素是⼀⽀给定股票第 i 天的价格。
设计⼀个算法来计算你所能获取的最⼤利润。你可以尽可能地完成更多的交易（多次买卖⼀
⽀股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
⽰例 1:
输⼊: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买⼊，在第 3 天（股票价格 = 5）的时候卖出, 这笔
交易所能获得利润 = 5-1 = 4。随后，在第 4 天（股票价格 = 3）的时候买⼊，在第 5 天（股
 }
 return dp[(len - 1) % 2][1];
 }
};
票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
⽰例 2:
输⼊: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买⼊，在第 5 天 （股票价格 = 5）的时候卖出, 这笔
交易所能获得利润 = 5-1 = 4 。注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们
卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
⽰例 3:
输⼊: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最⼤利润为 0。
提⽰：
1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
*/
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class ShareBuyingTable2{
public:
    //动态规划
    int ShareBuyingTable2_A(vector<T>share);
};
/*
dp[i][0]:第i天持有股票所得最多现金
dp[i][1]:第i天不持有股票所得最多现金
第i-1天持有股票，那么就保持现状，所得现金为昨天的现金,dp[i-1][0]
第i天买入股票，那么所得现金就是昨天所不持有的现金减去今天的股票价格dp[i-1][1]-share[i]
第i-1天不持有股票，保持现状那么，所得现金就是昨天不持有股票的所得现金即，dp[i-1][1];
第i天卖出股票，所得现金就是i今天卖出的现金share[i]+dp[i-1][0];
*/
template<typename T>
int ShareBuyingTable2<T>::ShareBuyingTable2_A(vector<T>share){
    vector<vector<int>>dp(share.size(),vector<int>(2));
    dp[0][0]-=share[0];
    dp[0][1]=0;
    for(int i=1;i<share.size();i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]-share[i]);
        dp[i][1]=max(dp[i-1][1],share[i]+dp[i-1][0]);
    }
    return dp[share.size()-1][1];
}

//输入输出
void ShareByingFormat2(){
    int N;
    cin>>N;
    vector<int>share(N);
    for(int i=0;i<N;i++)cin>>share[i];

    ShareBuyingTable2<int> obj;
    int val=obj.ShareBuyingTable2_A(share);
    cout<<val;
}