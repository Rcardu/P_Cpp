/*
数组的每个下标作为⼀个阶梯，第 i 个阶梯对应着⼀个⾮负数的体⼒花费值 cost[i]（下标从
0 开始）。
每当你爬上⼀个阶梯你都要花费对应的体⼒值，⼀旦⽀付了相应的体⼒值，你就可以选择向
上爬⼀个阶梯或者爬两个阶梯。
请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初
始阶梯。


⽰例 1：
输⼊：cost = [10, 15, 20]
输出：15
解释：最低花费是从 cost[1] 开始，然后⾛两步即可到阶梯顶，⼀共花费 15 。

⽰例 2：
输⼊：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出：6
解释：最低花费⽅式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，⼀共花费 6 。

提⽰：
cost 的长度范围是 [2, 1000]。
cost[i] 将会是⼀个整型数据，范围为 [0, 999] 。
*/
//dp[i]:到达第i个阶梯的最少花费体力为dp[i]
//dp[i]由dp[i-2]或者dp[i-1]得到
//当从0或者1开始爬时，即花费了当前的体力
//dp[i]=min(dp[i-1],dp[i-2])+cost[i];爬到这个楼梯前所花费的体力加上当前此楼梯的体力
#include<iostream>
#include<vector>
using namespace std;
class ClimbStairs_2{
    public:
        int Clim(vector<int>&cost){
            vector<int>dp(cost.size());
            dp[0]=cost[0];
            dp[1]=cost[1];
            for(int i=2;i<cost.size();i++){
                dp[i]=min(dp[i-1],dp[i-2])+cost[i];
            }
            return min(dp[cost.size()-1],dp[cost.size()-2]);
        }
};
//输入，输出
void ClimFormat(){
    int N;
    cin>>N;
    vector<int>cost(N);
    for(int i=0;i<N;i++)cin>>cost[i];
    ClimbStairs_2 obj;
    int val=obj.Clim(cost);
    cout<<val;
}
