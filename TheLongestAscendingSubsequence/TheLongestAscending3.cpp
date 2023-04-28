/*
最长重复⼦数组
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的⼦数组的长度。
⽰例：
输⼊：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共⼦数组是 [3, 2, 1] 。
提⽰：
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class TheLongestAscending3{
public:
    //最长重复子数组
    int TheLongestAscending_A(vector<T>nums1,vector<T>nums2);
};
/*
***dp数组
dp[i][i]:以i-1为结尾的A和以j-1为结尾的B最长重复子数组为dp[i][j]
***递推公式
由dp[i][j]的定义，dp[i][j]的状态只能由dp[i-1][j-1]推导出来
即当dp[i-1][j-1]与dp[i][j]相等的时候dp[i][j]=dp[i-1][j-1]+1;
也就是要从i,j=开始遍历
***初始化
有定义可知dp[i][0]与dp[0][j]都是没有意义的
将这两个都初始化为0
即dp[1][1]=dp[0][0]+1=1
***遍历顺序
外A内B与外B内A都是一样的 
由前往后
***举例推导
A:[1 2 3 2 1]   B:[3 2 1 4 7]
        0   1   2   3   4   5
    0   0   0   0   0   0   0
    1   0   0   0   1   0   0
    2   0   0   1   0   0   0
    3   0   1   0   0   0   0
    4   0   0   2   0   0   0
    5   0   0   0   3   0   0
    取所有dp[i][j]中的最大值
*/
template<typename T>
int TheLongestAscending3<T>::TheLongestAscending_A(vector<T>nums1,vector<T>nums2){
    vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
    int result=INT_MIN;
    for(int i=1;i<=nums1.size();i++){
        for(int j=1;j<=nums2.size();j++){
            if(nums1[i-1]==nums2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            result=max(dp[i][j],result);
        }
    }
    return result;
}

//输入输出
void ThelongestFormat3(){
    int N,M;
    cin>>N>>M;
    vector<int>num1(N),num2(M);
    for(int i=0;i<N;i++)cin>>num1[i];
    for(int i=0;i<M;i++)cin>>num2[i];

    TheLongestAscending3<int>obj;
    int val=obj.TheLongestAscending_A(num1,num2);
    cout<<val;
}