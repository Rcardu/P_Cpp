/*
给你⼀个整数数组 nums ，找到其中最长严格递增⼦序列的长度。
⼦序列是由数组派⽣⽽来的序列，删除（或不删除）数组中的元素⽽不改变其余元素的顺
序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的⼦序列。
⽰例 1：
输⼊：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增⼦序列是 [2,3,7,101]，因此长度为 4 。
⽰例 2：
输⼊：nums = [0,1,0,3,2,3]
输出：4
⽰例 3：
输⼊：nums = [7,7,7,7,7,7,7]
输出：1
提⽰：
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 104
*/
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class ThelongestAscending{
public:
    //动态规划 最长递增子序列
    int TheLongestAscending_A(vector<T>nums);
};
/*
***dp数组的含义
dp[i]表示i之前包括i的最长子序列
***状态转移方程
位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列+1的最大值
if(nums[i]>nums[j])dp[i]=max(dp[i],dp[j]+1)
不是将dp[i]与dp[j]+1比较，而是要取dp[j]+1的最大值
***初始化
对于每一个i对应的dp[i]（即最长升序子序列）的初始都为1
***确定遍历顺序
dp[i]是由0到i-1各个位置的最长子序列推导而来，那么遍历i一定是从前往后遍历
j就是0到i-1，即j<i开始遍历
***举例推导 [0 1 0 3 2]
        0 1 2 3 4
i=1     1 2 1 1 1      
i=2     1 2 1 1 1
i=3     1 2 1 3 1
i=4     1 2 1 3 3
*/
template<typename T>
int ThelongestAscending<T>::TheLongestAscending_A(vector<T>nums){
    vector<int>dp(nums.size(),1);
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j])dp[i]=max(dp[i],dp[j]+1);
        }
    }
    return dp[nums.size()-1];
}

//输入输出
void TheLongesFormat(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(int i=0;i<N;i++)cin>>nums[i];

    ThelongestAscending<int>obj;
    int val=obj.TheLongestAscending_A(nums);
    cout<<val;
}