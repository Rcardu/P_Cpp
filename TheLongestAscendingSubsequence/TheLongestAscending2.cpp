/*
给定⼀个未经排序的整数数组，找到最长且 连续递增的⼦序列，并返回该序列的长度。
连续递增的⼦序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有
nums[i] < nums[i + 1] ，那么⼦序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连
续递增⼦序列。
⽰例 1：
输⼊：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的⼦序列, 但它不是连续的，因为 5 和 7 在原数组⾥被 4 隔开。
⽰例 2：
输⼊：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
提⽰：
0 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
*/
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class TheLongestAscending2{
public:
    //最长连续递增子序列
    int TheLongestAscending2_A(vector<T>nums);
    //贪心算法
    int TheLongestAscending2_B(vector<T>nums);
};
/*
dp[i]:以下标i结尾的数组的连续递增子序列的长度为dp[i];
***递推公式
如果nums[i+1]>nums[i]那么以i+1结尾的数组的连续递增子序列长度一定等于以i结尾的数组的连续递增子序列的长度+1
dp[i+1]=dp[i]+1;
因为是连续递增所以只需要比较nums[i]与nums[i+1]之间的大小而不用比较nums[i]与nums[j]之间的大小
只需要一层循环
***初始化
所有以i开始的连续递增子序列的长度至少为1，所以dp[i]=1;
***遍历顺序
从前往后
***举例推导
以[1 3 5 4 7]为例
    0   1   2   3   4
    1   1   1   1   1
    1   2   3   1   2

    最终取dp[i]里的最大值即可
*/
template<typename T>
int TheLongestAscending2<T>::TheLongestAscending2_A(vector<T>nums){
    vector<int>dp(nums.size(),1);
    int value=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i+1]>nums[i])dp[i+1]=dp[i]+1;
        value=max(value,dp[i]);
    }
    return value;
}
/*
这道题⽬也可以⽤贪⼼来做，也就是遇到nums[i + 1] > nums[i]的情况，count就++，否则
count为1，记录count的最⼤值就可以了。
*/
template<typename T>
int TheLongestAscending2<T>::TheLongestAscending2_B(vector<T>nums){
    if(nums.size()==0)return 0;
    int result=1;//最少也为1
    int count=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i+1]>nums[i])count++;
        else count=1;
        if(count>result)result=count;//因为count如果被断掉的话会更新，这里记录最长的
    }
    return result;
    
}

//输入输出
void TheLongestAscending2Format(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(int i=0;i<N;i++)cin>>nums[i];

    TheLongestAscending2<int>obj;
    //int val=obj.TheLongestAscending2_A(nums);
    int val=obj.TheLongestAscending2_B(nums);
    cout<<val;
}