/*
有⼀堆⽯头，每块⽯头的重量都是正整数。
每⼀回合，从中选出任意两块⽯头，然后将它们⼀起粉碎。假设⽯头的重量分别为 x 和 y，
且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块⽯头都会被完全粉碎；
如果 x != y，那么重量为 x 的⽯头将会完全粉碎，⽽重量为 y 的⽯头新重量为 y-x。
最后，最多只会剩下⼀块⽯头。返回此⽯头最⼩的可能重量。如果没有⽯头剩下，就返回
0。
⽰例：
输⼊：[2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
提⽰：
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/
#include<iostream>
#include<vector>

using namespace std;

class Milestone{
    public: 
        //将石头分为相差最小的两部分，取出最大的那一部分取撞另一部分
        //结果就是剩下的最小的石头
        //dp[i]：重量为j的背包最多可以背dp[i]重量的石头
        //dp[j]=max(dp[j],dp[j-stone[i]]+stone[i])
        //dp[0]=0;背包重量为0就装不下石头
        //j就是石头一半向下取整的重量
        //先遍历石头，再遍历背包
        //推导
        /*      00  01  02  03  04  05  06  07  08  09  10  11        
    02  00  02  02  02  02  02  02  02  02  02  02  02
    07  00  02  02  02  02  02  02  02  09  09  09  09
    04  00  00  02  02  04  06  06  06  09  09  09  09
    01  00  01  02  03  04  06  07  07  09  10  10  10
    08  00  01  02  03  04  06  07  07  09  10  10  11
    01  00  01  02  03  04  06  07  08  09  10  11  11
*/
        int milestone(vector<int>&stone){
            int sum=0,weight=0;
            for(int i=0;i<stone.size();i++)sum+=stone[i];
            weight=sum/2;
            vector<int>dp(weight+1,0);
            dp[0]=0;
            for(int i=0;i<stone.size();i++){
                for(int j=weight;j>=stone[i];j--){
                    dp[j]=max(dp[j],dp[j-stone[i]]+stone[i]);
                }
            }
            return sum-dp[weight]-dp[weight];
        }
};


//输入和输出
void milestoneFormat(){
    int N;
    cin>>N;
    vector<int>stone(N,0);
    for(int i=0;i<N;i++)cin>>stone[i];

    Milestone obj;
    int val=obj.milestone(stone);
    cout<<val;
}