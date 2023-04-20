/*
给定⼀个只包含正整数的⾮空数组。是否可以将这个数组分割成两个⼦集，使得两个⼦集的
元素和相等。
注意:
每个数组中的元素不会超过 100
数组的⼤⼩不会超过 200
⽰例 1:
输⼊: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
⽰例 2:
输⼊: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的⼦集
*/
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class SerNumberOfStreamDivisions{
    public:
        // 如果数组中存在总和为sum/2的子集，就说明可以分割
        //设背包的容量为sum/2，将物品放入背包中，若可以放进去则证明存在
        //dp[j]:ij代表背包容量，最大可以凑成子集总和为dp[j];
        //dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        //也就有dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
        //也就是说物品价值与物品重量相等
        /*物品为[1  5   13  5]下标为i
        00    00  01  02  03  04  05  06  07  08  09  10  11    12
        01    00  01  01  01  01  01  01  01  01  01  01  01    01
        05    00  01  01  01  01  05  06  06  06  06  06  06    06
        11    00  01  01  01  01  05  06  06  06  06  06  06    06
        05    00  01  01  01  01  05  06  06  06  06  06  06    11
        */
       bool SetNumberOfStreamDivisions_A(vector<int>&nums){
        int sum=0;
        //sum/2就是背包容量
        sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        vector<int>dp(sum/2+1,0);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=sum/2;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[sum/2]==sum/2)return true;
        return false;
       }
};


//输入和输出
void SetNumberOfStreamFormat(){
    int N;
    cin>>N;
    vector<int>nums(N,0);
    for(int i=0;i<N;i++)cin>>nums[i];
    cout<<endl;

    SerNumberOfStreamDivisions obj;
    bool val=obj.SetNumberOfStreamDivisions_A(nums);
    cout<<val<<endl;
    if(val)cout<<"true";
    else cout<<"false";
}