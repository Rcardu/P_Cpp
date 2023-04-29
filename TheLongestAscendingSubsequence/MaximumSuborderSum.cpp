/*
给定⼀个整数数组 nums ，找到⼀个具有最⼤和的连续⼦数组（⼦数组最少包含⼀个元
素），返回其最⼤和。
⽰例:
输⼊: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续⼦数组 [4,-1,2,1] 的和最⼤，为 6。
*/
#include<iostream>
#include<vector>

using namespace std;

class MaximumSuborderSum{
public:
    /*
    dp[i]:包括i在内的i之前的最大子序和为dp[i];
    两个来源即dp[i-1]+nums[i];dp[i-1]的最大子序和加上当前i下标nums[i]的和
    nums[i];从i开始重新计算最大子序和
    max(nums[i],dp[i-1]+nums[i]);
    因为dp[i]是由dp[i-1]推出，所以dp[0]就是初值
    dp[0]代表最大子序和从0开始加即dp[0]=nums[0];
    从前往后遍历
    ***举例推导 例如 [-2 1 -3 4 -1 2 1 -5 4]
        0   1   2   3   4   5   6   7   8
        -2  1   -2  4   3   5   6   1   5
        每次取每个自序中的最大值即可
    */
   int MaximumSuborderSum_A(vector<int>nums){
    vector<int>dp(nums.size(),0);
    dp[0]=nums[0];
    int result=INT_MIN;
    for(int i=1;i<nums.size();i++){
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        result=max(result,dp[i]);
    }   
    return result;
   }
};

//输入输出
void MaximumSuborderFormat(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(int i=0;i<N;i++)cin>>nums[i];
    MaximumSuborderSum obj;
    int val=obj.MaximumSuborderSum_A(nums);
    cout<<val;

}