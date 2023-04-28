/*
给定⼀个数组，它的第 i 个元素是⼀⽀给定的股票在第 i 天的价格。
设计⼀个算法来计算你所能获取的最⼤利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
⽰例 1:
输⼊：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买⼊，在第 6 天（股票价格 = 3）的时候卖出，这
笔交易所能获得利润 = 3-0 = 3 。随后，在第 7 天（股票价格 = 1）的时候买⼊，在第 8 天
（股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3。
⽰例 2：
输⼊：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买⼊，在第 5 天 （股票价格 = 5）的时候卖出, 这笔
交易所能获得利润 = 5-1 = 4。注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们
卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
};
⽰例 3：
输⼊：prices = [7,6,4,3,1]
输出：0
解释：在这个情况下, 没有交易完成, 所以最⼤利润为0。
⽰例 4：
输⼊：prices = [1]
输出：0
提⽰：
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^5
*/
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class ShareBuyingTable3{
public:
    //动态规划
    int ShareBuyingTable3_A(vector<T>share);
};
/*
***dp数组的含义
一天一共5个状态
0.没有操作
1.第一次买入
2.第一次卖出
3.第二次买入
4.第二次卖出
dp[i][j]:i表示第i天，j为[0~4]五个状态dp[i][j]表示第i天状态j所剩的最大现金
***递推公式
dp[i][1]:表示第i天股票买入的状态，不是一定要买入股票
达到dp[i][1]状态有两个操作
第i天要买入股票：那么dp[i][1]=dp[i-1][0]-share[i];
第i天保持原来的状态：那么dp[i][1]=dp[i-1][1];
这一天的值取最大值即，dp[i][1]=max(dp[i-1][0]-share[i],dp[i-1][1]);
同理,dp[i][2]也有两个操作
第i天要卖出股票，那么dp[i][2]=dp[i-1][1]+share[i];
第i天什么都不做，那么沿用前一天股票卖出的状态dp[i][2]=dp[i-1][2];
dp[i][2]=max(dp[i-1][1]+share[i],dp[i-1][2]);
可得dp[i][3]与dp[i][4]
dp[i][3]=max(dp[i-1][2]-share[i],dp[i-1][3]);
dp[i][4]=max(dp[i-1][3]+share[i],dp[i-1][4]);
***初始化
第0天没有操作，即dp[0][0]=0;
第0天买入，dp[0][1]=-share[i];
第0天卖出，也就是说没有现金即dp[0][2]=0;
第0天第二次买入，在第0天无论第几次买入都是在同一天只能买入一次，也就是dp[0][3]=-share[i]
第0天第二次卖出，同理即dp[0][4]=0;
***遍历顺序
由递推公式可知，从前往后遍历
***举例推导
以[1 2 3 4 5 ]为例
        状态j：     不操作      买入        卖出        买入        卖出

   下标     股票       0        1           2           3           4
   0        1       0           -1          0           -1          0
   1        2       0           -1          1           -1          1
   2        3       0           -1          2           -1          2
   3        4       0           -1          3           -1          3
   4        5       0           -1          4           -1          4     
*/
template<typename T>
int ShareBuyingTable3<T>::ShareBuyingTable3_A(vector<T>share){
    vector<vector<int>>dp(share.size(),vector<int>(5));//天数与状态
    dp[0][0]=0;
    dp[0][1]=-share[0];
    dp[0][2]=0;
    dp[0][3]=-share[0];
    dp[0][4]=0;
    for(int i=1;i<share.size();i++){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][0]-share[i],dp[i-1][1]);
            dp[i][2]=max(dp[i-1][1]+share[i],dp[i-1][2]);
            dp[i][3]=max(dp[i-1][2]-share[i],dp[i-1][3]);
            dp[i][4]=max(dp[i-1][3]+share[i],dp[i-1][4]);
    }
    return dp[share.size()-1][4];
}

//输入输出
void ShareBuyingForamt3(){
    int N;
    cin>>N;
    vector<int>share(N);
    for(int i=0;i<N;i++)cin>>share[i];

    ShareBuyingTable3<int>shares;
    int val=shares.ShareBuyingTable3_A(share);
    cout<<val;

}
