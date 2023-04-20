/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 - 中选择一个符号添加在前面。返回可以使最终数组和为目标数 S 的所有添加符号的方法数。 

    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int target = (sum + S) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }

⽰例：
输⼊：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
⼀共有5种⽅法让最终⽬标和为3。
提⽰：
数组⾮空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下。
*/
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class EpriorityStandard{
    public:
        //进行加或者减使总和达到目标值
        //数组中有m个数相加，再减去其他n个数的总和就可以得到目标S
        //当着m个数的总和为x时，整个数组的总和sum减去x就是剩下n个数的总和
        //即m个数的总和x减去n个书的总和sum-x就是目标S
        //S=x-(sum-x);
        //x=(S+sum)/2;
        //只需要求出x有几种分配情况就可以了
        //也就是如何装满容量为x的背包
        //因为x=(S+sum)/2,所以当此值不为整数时也就没有解
        //即,if((S+sum)%2==1)return false;
        //dp[j]:装满j容量大小的背包有dp[i]种方法
        //假设需要填满容量为4的背包，就有dp[4]种方法
        //当不考虑nums[i]时，装满容量为j-nums[i]的背包，就需要dp[j-nums[i]]种方法
        //如果将nums[i]加进去，就时装满容量为j的背包，也就是加上dp[j-num[i]]种方法，从而的到dp[j];
        //装容量为0的背包只有一种方法就是装0件物品
        //dp[j]+=dp[j-nums[i]];
        /*          [1,1,1,1,1]=5 S=3   (sum+S)/2=4
            00  01  02  03  04
        01  01  01  00  00  00
        01  01  02  01  00  00
        01  01  03  03  01  00
        01  01  04  06  04  01
        01  01  05  10  10  05
        */
       int ePriorityStandard_A(vector<int>&nums,int S){
        //总和与重量
        int sum=0,traget=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        if(S>sum||(sum+S)%2==1)return false;
        traget=(sum+S)/2;
        vector<int>dp(traget+1,0);
        //装容量为0的背包只有一种方法
        dp[0]=1;
        for(int i=0;i<nums.size();i++){//遍历物品
            for(int j=traget;j>=nums[i];j--){//遍历背包
                dp[j]+=dp[j-nums[i]];
            }    
        }
        return dp[traget];
        //AI
       }
       // 找到目标和的方法
int findTargetSumWays(vector<int>& nums, int S) {
    // 计算数组的总和
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // 如果总和小于目标和或者总和加目标和为奇数，则无法找到目标和
    if (sum < S || (sum + S) % 2 == 1) {
        return 0;
    }
    // 计算目标和
    int target = (sum + S) / 2;
    // 初始化动态规划数组
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    // 动态规划
    for (int num : nums) {
        for (int i = target; i >= num; i--) {
            dp[i] += dp[i - num];
        }
    }
    // 返回结果
    return dp[target];
}
};


//输入输出
void EPriorityFormat(){
    int N,S;
    cin>>N>>S;
    vector<int>nums(N,0);
    for(int i=0;i<N;i++)cin>>nums[i];

    EpriorityStandard obj;
    int val=obj.ePriorityStandard_A(nums,S);
    cout<<val;

}