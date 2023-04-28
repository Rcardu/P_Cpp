/*
给定⼀个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；⾮负整数 fee 代表了
交易股票的⼿续费⽤。
你可以⽆限次地完成交易，但是你每笔交易都需要付⼿续费。如果你已经购买了⼀个股票，
在卖出它之前你就不能再继续购买股票了。
返回获得利润的最⼤值。
注意：这⾥的⼀笔交易指买⼊持有并卖出股票的整个过程，每笔交易你只需要为⽀付⼀次⼿
续费。
 }
};
⽰例 1:
输⼊: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最⼤利润:
在此处买⼊ prices[0] = 1
在此处卖出 prices[3] = 8
在此处买⼊ prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:
0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/
/*****冷却期*****/

/*
给定⼀个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
设计⼀个算法计算出最⼤利润。在满⾜以下约束条件下，你可以尽可能地完成更多的交易
（多次买卖⼀⽀股票）:
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你⽆法在第⼆天买⼊股票 (即冷冻期为 1 天)。
⽰例:
输⼊: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买⼊, 卖出, 冷冻期, 买⼊, 卖出]
*/
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class ShareBuyingTableect{
public:
    //动态规划 冷却期
    int ShareBuyingTableShut_A(vector<T>price);
    //动态规划 手续费
    int ShareBuyingTableEct_A(vector<T>price,T k);
};
/*
dp[i][j]:第i天的状态为j，所剩最大现金为dp[i][j]
1.买入股票（或者之前买入了，那么今天就没有操作）
2.卖出股票，两天前卖出了股票，度过了冷却期，一直没有操作，今天继续保持
3.卖出股票，今天才卖出股票
4.今天为冷却期，但冷却期为不可持续状态，只有一天
***递推公式
对于状态一：即dp[i][0]
    操作一：前一天就持有股票了，保持现状即可dp[i-1][0];
    操作二：今天买入了，有两种情况
            1：前一天是冷却期（状态4）dp[i-1][3]-price[i];
            2:前一天是保持股票卖出时的状态（状态2），dp[i-1][1]-price[i];
    二者操作取最大值max(dp[i-1][0],max(dp[i-1][3]-price[i],dp[i-1])-price[i]);
对于状态二：即dp[i][1]
    操作一：前一天的状态
    操作二：前一天是冷却期（状态四）
    dp[i][1]=max(dp[i-1][1],dp[i-1][3]);
对于状态三：即dp[i][2]:
    操作一：昨天一定是买入了股票，今天卖出dp[i-1][0]+price[i];
对于状态四：即dp[i][3]:
    操作一：昨天卖出了股票，今天是冷却期dp[i-1][2];
***初始化
如果是持有状态（状态一）dp[0][0]=-price[i];
如果是保持卖出状态（状态二）dp[0][1]=0;因为是第0天卖出也是0
今天卖出了股票（状态3）dp[0][2]=0;
冷却期初始也为0;
***从前往后
***举例推导 [1  2   3   0   2]
        0       1       2       3
0   1   -1      0       0       0
1   2   -1      0       1       0     
2   3   -1      0       2       1
3   0   1       1       -1       2
4   2   1       2       3       -1
最大值在于前两天卖出股票后已经最大，今天卖出股票才是最大，昨天卖出股票才是最大
*/
template <typename T>
int ShareBuyingTableect<T>::ShareBuyingTableShut_A(vector<T>price){
    vector<vector<int>>dp(price.size(),vector<int>(4));
    dp[0][0]=-price[0];
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=0;
    for(int i=1;i<price.size();i++){
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][3],dp[i-1][1])-price[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][3]);
        dp[i][2]=dp[i-1][0]+price[i];
        dp[i][3]=dp[i-1][2];
    }
    return max(dp[price.size()-1][1],max(dp[price.size()-1][2],dp[price.size()-1][3]));
}
/*
dp[i][0]:第i天所持有股票所得最大现金
dp[i][1]:第i天所不持有股票所得最大现金
dp[i][0]:若第i天买入，则所持现金为昨天不持有状态减去当天股价dp[i-1][1]-price[i];若保持现状则dp[i-1][0]
dp[i][1]:若第i天卖出，则所持现金就是昨天持有状态加上当天股价减去手续费dp[i-1][0]+price[i]-fee,保持现状则dp[i-1][1];
dp[0][0]:就是第0天持有即-price[0];
dp[0][1]:就是第0天不持有即0
从后往前遍历
举例推导 以[1 3 2 8 4 9] fee=2为例
            0       1
    1   0   -1      0
    3   1   -1      0
    2   2   -1      0
    8   3   -1      5
    4   4   1       5
    9   5   1       8
*/
template<typename T>
int ShareBuyingTableect<T>::ShareBuyingTableEct_A(vector<T>price,T k){
    vector<vector<int>>dp(price.size(),vector<int>(2));
    dp[0][0]=-price[0];
    dp[0][1]=0;
    for(int i=1;i<price.size();i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]-price[i]);
        dp[i][1]=max(dp[i-1][0]+price[i]-k,dp[i-1][1]);
    }
    return dp[price.size()-1][1];
}

//输入输出
void ShareBuyingFormatEct(){
    int N,fee;
    cin>>N;
    //cin>>N>>fee;
    vector<int>price(N);
    for(int i=0;i<N;i++)cin>>price[i];

    ShareBuyingTableect<int>prices;
    //int val=prices.ShareBuyingTableEct_A(price,fee);
    int val=prices.ShareBuyingTableShut_A(price);
    cout<<val;

}
